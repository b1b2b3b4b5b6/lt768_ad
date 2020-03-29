#include "ad_service.h"

#define STD_LOCAL_LOG_LEVEL STD_LOG_DEBUG

#define TASK_SIZE 3096
#define TASK_PRI ESP_TASK_MAIN_PRIO

#define BUFFSIZE 1024
#define MAX_AD_NUM 6
#define URL_LEN 100
#define ROTATE_TIME_MS 5000
#define IMG_AD_INFO_KEY "img_info_key"
#define DWONLOAD_RETRY 3

typedef enum img_progress_t{
    IMG_DOWNLOADING = 0,
    IMG_COMPLETE = 1,
    IMG_INIT = 2,
}img_progress_t;


typedef struct img_ad_info_t{
    int max_num;
    int now_num;
    int progress;
    char url_list[MAX_AD_NUM][URL_LEN];
}img_ad_info_t;

static img_ad_info_t g_img_ad_info;

static dma_info_t *get_ad_dma(int num)
{
    switch(num)
    {
        case 0:
            return &ad_ENUM_0;
            break;

        case 1:
            return &ad_ENUM_1;
            break;

        case 2:
            return &ad_ENUM_2;
            break;

        case 3:
            return &ad_ENUM_3;
            break;
        
        case 4:
            return &ad_ENUM_4;
            break;     

        case 5:
            return &ad_ENUM_5;
            break;  

        case 6:
            return &ad_ENUM_5;
            break;  

        case 7:
            return &ad_ENUM_6;
            break;  

        case 8:
            return &ad_ENUM_7;
            break; 

        case 9:
            return &ad_ENUM_8;
            break;  

    }
    STD_LOGE("undefine ad num");
    STD_ASSERT(-1);
    return NULL;
}

void print_img_ad_info(img_ad_info_t *info)
{
    printf("*************img ad info*************\r\n");
    printf("max num[%d]\r\n", info->max_num);
    printf("now_num[%d]\r\n", info->now_num);
    printf("progress[%d]\r\n", info->progress);
    for(int n = 0; n < info->max_num; n++)
        printf("%s\r\n", &info->url_list[n][0]);
    printf("--------------------------------------\r\n");
}

void save_ad(int num, uint8_t *data, int len)
{
    w25q_reint();
    dma_info_t *info = get_ad_dma(num);
    w25q_erase_range(info->addr, len);
    w25q_write(info->addr, data, len);
    w25q_deint();
}

static void sync_brust()
{
    device_info_raw_t *raw = get_device_raw();
    raw->device_info.ImgProgress = g_img_ad_info.progress;
}

static void img_url_handle(uint8_t *mac, char *json)
{
    char **img_ad = NULL;
    int img_num = json_parse_object(json, "ImgAd", &img_ad);
    if(img_num < 0)
    {
        STD_LOGE("ImgAd parse fail");
        return;
    }

    STD_LOGD("ImgAd num[%d]", img_num);

    if(img_num > MAX_AD_NUM)
    {
        STD_LOGE("img ad lager than %d", MAX_AD_NUM);
        json_free(img_ad, img_num);
        return;
    }

    memset(&g_img_ad_info, 0, sizeof(g_img_ad_info));
    g_img_ad_info.max_num = img_num;
    g_img_ad_info.now_num = 0;
    g_img_ad_info.progress = IMG_DOWNLOADING;

    
    for(int n = 0; n < img_num; n++)
    {
        strcpy(g_img_ad_info.url_list[n], img_ad[n]);
    }
        
    json_free(img_ad, img_num);
    print_img_ad_info(&g_img_ad_info);
    sync_brust();
    return;
}



static uint8_t* download_img(char *url)
{
    int res = 0;
    uint8_t *buf = STD_MALLOC(1024*512);
    uint16_t *img = STD_CALLOC(1024 * 1024 / 2, sizeof(uint16_t));
    int len = http_download(url, buf);
    if(len <= 0)
    {
        STD_LOGE("img download fail[%s]", url);
        goto FAIL;
    }
    res = std_decode_image(720, 720, buf, img);
    
    if(res != 0)
    {
        STD_LOGE("decode image fail[%s]", url);
        res = -1;
        goto FAIL;
    }

FAIL:

    if(res != 0)
    {
        STD_FREE(buf);
        STD_FREE(img);
        return NULL;
    }
    uint8_t *pic = STD_MALLOC(len);
    memcpy(pic, buf, len);
    STD_FREE(buf);
    STD_FREE(img);
    STD_LOGD("img download success[%s]", url);
    return pic;
}

static void update_img()
{
    uint8_t *pic[MAX_AD_NUM] = {NULL};
    int res = 0;
    for(int n = 0; n < g_img_ad_info.max_num; n++)
    {
        res = STD_RETRY_TRUE_BREAK((pic[n] = download_img(g_img_ad_info.url_list[n])) != NULL, DWONLOAD_RETRY);
        STD_ERROR_GOTO_FAIL(res);
    }
    lt768ui_loop_set_run(false);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    maintain_jump();
    overlay_refresh();
    uint16_t *img = STD_CALLOC(1024 * 1024 / 2, sizeof(uint16_t));
    for(int n = 0; n < g_img_ad_info.max_num; n++)
    {
        int res = std_decode_image(720, 720, pic[n], img);
        STD_ASSERT(res == 0);
        save_ad(n, (uint8_t *)img, 1024 * 1024);
    }
    main_jump();
    overlay_refresh();
    STD_FREE(img);
    lt768ui_loop_set_run(true);
    res = 0;
FAIL:
    for(int n = 0; n < g_img_ad_info.max_num; n++)
        STD_FREE(pic[n]);

    if(res == 0)
        g_img_ad_info.progress = IMG_COMPLETE;
}



static void loop_task(void *arg)
{
    STD_LOGD("ad service task create");
    for(;;)
    {
        vTaskDelay(ROTATE_TIME_MS / portTICK_PERIOD_MS);

        if(g_img_ad_info.progress !=  IMG_DOWNLOADING)
        {
            g_img_ad_info.now_num++;
            if(g_img_ad_info.now_num >= g_img_ad_info.max_num)
                g_img_ad_info.now_num = 0;
            set_ad_num(g_img_ad_info.now_num);
            continue;
        }

        update_img();
        sync_brust();
    }

}

void ad_service_init()
{
    if(std_nvs_is_exist(IMG_AD_INFO_KEY))
    {
        std_nvs_load(IMG_AD_INFO_KEY, &g_img_ad_info, sizeof(g_img_ad_info));
    }
    else
    {
        memset(&g_img_ad_info, 0, sizeof(img_ad_info_t));
        g_img_ad_info.progress = IMG_INIT;
        std_nvs_save(IMG_AD_INFO_KEY, &g_img_ad_info, sizeof(img_ad_info_t));
        
    }

    xTaskCreate(loop_task, "ad loop task", TASK_SIZE, NULL, TASK_PRI, NULL);
    ADD_CMD("ImgAd", img_url_handle);
    STD_LOGI("ad service init success");
}

int ad_get_progress()
{
    return g_img_ad_info.progress;
}
