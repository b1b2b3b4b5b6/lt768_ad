#include "business.h"

#define STD_LOCAL_LOG_LEVEL STD_LOG_DEBUG

void business_init()
{
    up_service_init();
    ad_service_init();
    STD_LOGI("business init success");
}