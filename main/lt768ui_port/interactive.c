#include "interactive.h"

#define STD_LOCAL_LOG_LEVEL STD_LOG_DEBUG

#define MAIN 1
#define HUMIDIFY 2
#define TEMP 3
#define SWITCH 4
#define AD 5
#define MAINTAIN 6

void main_jump()
{
	interface_jump(MAIN);
}

void humidity_jump()
{
	interface_jump(HUMIDIFY);
}

void temp_jump()
{
	interface_jump(TEMP);
}

void switch_jump()
{
	interface_jump(SWITCH);	
}

void ad_jump()
{
	interface_jump(AD);
}

void maintain_jump()
{
	interface_jump(MAINTAIN);
}

char temp_show[10] = "75%%";

static void main_init()
{
	interface_t *interface;
	button_t *button;
	widget_t *widget;
	enumpic_t *enumpic;
	text_t *text;
	interface = build_interface(MAIN, &main_bg);
	resgister_interface(interface);

	button = build_button(SHAPE_RECT, &main_BTjump_normal, &main_BTjump_click, 325, 576, ad_jump, LAY_WIDGET0);
	widget = build_widget(WIDGET_BUTTON, button);
	interface_add_widget(interface, widget);

	button = build_button(SHAPE_RECT, &main_BTjump_normal, &main_BTjump_click, 450, 576, temp_jump, LAY_WIDGET0);
	widget = build_widget(WIDGET_BUTTON, button);
	interface_add_widget(interface, widget);

	button = build_button(SHAPE_RECT, &main_BTjump_normal, &main_BTjump_click, 578, 576, switch_jump, LAY_WIDGET0);
	widget = build_widget(WIDGET_BUTTON, button);
	interface_add_widget(interface, widget);

	enumpic =  build_enumpic(240, 260, &first_num, LAY_WIDGET0);
	enumpic_add_case(enumpic, &main_ENUMindoor_0);
	enumpic_add_case(enumpic, &main_ENUMindoor_1);
	enumpic_add_case(enumpic, &main_ENUMindoor_2);
	enumpic_add_case(enumpic, &main_ENUMindoor_3);
	enumpic_add_case(enumpic, &main_ENUMindoor_4);
	enumpic_add_case(enumpic, &main_ENUMindoor_5);
	enumpic_add_case(enumpic, &main_ENUMindoor_6);
	enumpic_add_case(enumpic, &main_ENUMindoor_7);
	enumpic_add_case(enumpic, &main_ENUMindoor_8);
	enumpic_add_case(enumpic, &main_ENUMindoor_9);
	widget = build_widget(WIDGET_ENUMPIC, enumpic);
	interface_add_widget(interface, widget);

	enumpic =  build_enumpic(396, 260, &second_num, LAY_WIDGET0);
	enumpic_add_case(enumpic, &main_ENUMindoor_0);
	enumpic_add_case(enumpic, &main_ENUMindoor_1);
	enumpic_add_case(enumpic, &main_ENUMindoor_2);
	enumpic_add_case(enumpic, &main_ENUMindoor_3);
	enumpic_add_case(enumpic, &main_ENUMindoor_4);
	enumpic_add_case(enumpic, &main_ENUMindoor_5);
	enumpic_add_case(enumpic, &main_ENUMindoor_6);
	enumpic_add_case(enumpic, &main_ENUMindoor_7);
	enumpic_add_case(enumpic, &main_ENUMindoor_8);
	enumpic_add_case(enumpic, &main_ENUMindoor_9);
	widget = build_widget(WIDGET_ENUMPIC, enumpic);
	interface_add_widget(interface, widget);

	enumpic =  build_enumpic(62, 80, &time_1, LAY_WIDGET0);


	enumpic_add_case(enumpic, &main_ENUMtime_0);
	enumpic_add_case(enumpic, &main_ENUMtime_1);
	enumpic_add_case(enumpic, &main_ENUMtime_2);
	enumpic_add_case(enumpic, &main_ENUMtime_3);
	enumpic_add_case(enumpic, &main_ENUMtime_4);
	enumpic_add_case(enumpic, &main_ENUMtime_5);
	enumpic_add_case(enumpic, &main_ENUMtime_6);
	enumpic_add_case(enumpic, &main_ENUMtime_7);
	enumpic_add_case(enumpic, &main_ENUMtime_8);
	enumpic_add_case(enumpic, &main_ENUMtime_9);
	widget = build_widget(WIDGET_ENUMPIC, enumpic);
	interface_add_widget(interface, widget);

	enumpic =  build_enumpic(88, 80, &time_2, LAY_WIDGET0);
	enumpic_add_case(enumpic, &main_ENUMtime_0);
	enumpic_add_case(enumpic, &main_ENUMtime_1);
	enumpic_add_case(enumpic, &main_ENUMtime_2);
	enumpic_add_case(enumpic, &main_ENUMtime_3);
	enumpic_add_case(enumpic, &main_ENUMtime_4);
	enumpic_add_case(enumpic, &main_ENUMtime_5);
	enumpic_add_case(enumpic, &main_ENUMtime_6);
	enumpic_add_case(enumpic, &main_ENUMtime_7);
	enumpic_add_case(enumpic, &main_ENUMtime_8);
	enumpic_add_case(enumpic, &main_ENUMtime_9);
	widget = build_widget(WIDGET_ENUMPIC, enumpic);
	interface_add_widget(interface, widget);

	enumpic =  build_enumpic(128, 80, &time_3, LAY_WIDGET0);
	enumpic_add_case(enumpic, &main_ENUMtime_0);
	enumpic_add_case(enumpic, &main_ENUMtime_1);
	enumpic_add_case(enumpic, &main_ENUMtime_2);
	enumpic_add_case(enumpic, &main_ENUMtime_3);
	enumpic_add_case(enumpic, &main_ENUMtime_4);
	enumpic_add_case(enumpic, &main_ENUMtime_5);
	enumpic_add_case(enumpic, &main_ENUMtime_6);
	enumpic_add_case(enumpic, &main_ENUMtime_7);
	enumpic_add_case(enumpic, &main_ENUMtime_8);
	enumpic_add_case(enumpic, &main_ENUMtime_9);
	widget = build_widget(WIDGET_ENUMPIC, enumpic);
	interface_add_widget(interface, widget);

	enumpic =  build_enumpic(152, 80, &time_4, LAY_WIDGET0);
	enumpic_add_case(enumpic, &main_ENUMtime_0);
	enumpic_add_case(enumpic, &main_ENUMtime_1);
	enumpic_add_case(enumpic, &main_ENUMtime_2);
	enumpic_add_case(enumpic, &main_ENUMtime_3);
	enumpic_add_case(enumpic, &main_ENUMtime_4);
	enumpic_add_case(enumpic, &main_ENUMtime_5);
	enumpic_add_case(enumpic, &main_ENUMtime_6);
	enumpic_add_case(enumpic, &main_ENUMtime_7);
	enumpic_add_case(enumpic, &main_ENUMtime_8);
	enumpic_add_case(enumpic, &main_ENUMtime_9);
	widget = build_widget(WIDGET_ENUMPIC, enumpic);
	interface_add_widget(interface, widget);


	enumpic =  build_enumpic(500, 68, &set_temp_1, LAY_WIDGET0);
	enumpic_add_case(enumpic, &main_ENUMset_0);
	enumpic_add_case(enumpic, &main_ENUMset_1);
	enumpic_add_case(enumpic, &main_ENUMset_2);
	enumpic_add_case(enumpic, &main_ENUMset_3);
	enumpic_add_case(enumpic, &main_ENUMset_4);
	enumpic_add_case(enumpic, &main_ENUMset_5);
	enumpic_add_case(enumpic, &main_ENUMset_6);
	enumpic_add_case(enumpic, &main_ENUMset_7);
	enumpic_add_case(enumpic, &main_ENUMset_8);
	enumpic_add_case(enumpic, &main_ENUMset_9);
	widget = build_widget(WIDGET_ENUMPIC, enumpic);
	interface_add_widget(interface, widget);

	enumpic =  build_enumpic(562, 68, &set_temp_2, LAY_WIDGET0);
	enumpic_add_case(enumpic, &main_ENUMset_0);
	enumpic_add_case(enumpic, &main_ENUMset_1);
	enumpic_add_case(enumpic, &main_ENUMset_2);
	enumpic_add_case(enumpic, &main_ENUMset_3);
	enumpic_add_case(enumpic, &main_ENUMset_4);
	enumpic_add_case(enumpic, &main_ENUMset_5);
	enumpic_add_case(enumpic, &main_ENUMset_6);
	enumpic_add_case(enumpic, &main_ENUMset_7);
	enumpic_add_case(enumpic, &main_ENUMset_8);
	enumpic_add_case(enumpic, &main_ENUMset_9);
	widget = build_widget(WIDGET_ENUMPIC, enumpic);
	interface_add_widget(interface, widget);

	text =  build_text(16, get_rgb565(0x12, 0x96, 0xdb), 73, 136, "December 10th", LAY_WIDGET1);
	widget = build_widget(WIDGET_TEXT, text);
	interface_add_widget(interface, widget);

	text =  build_text(24, get_rgb565(0x12, 0x96, 0xdb), 77, 652, "12~17", LAY_WIDGET1);
	widget = build_widget(WIDGET_TEXT, text);
	interface_add_widget(interface, widget);

	text =  build_text(24, get_rgb565(0x12, 0x96, 0xdb), 213, 652, "1.9g/L", LAY_WIDGET1);
	widget = build_widget(WIDGET_TEXT, text);
	interface_add_widget(interface, widget);

	text =  build_text(24, get_rgb565(0x12, 0x96, 0xdb), 353, 652, temp_show, LAY_WIDGET1);
	widget = build_widget(WIDGET_TEXT, text);
	interface_add_widget(interface, widget);

	text =  build_text(24, get_rgb565(0x12, 0x96, 0xdb), 483, 652, "15", LAY_WIDGET1);
	widget = build_widget(WIDGET_TEXT, text);
	interface_add_widget(interface, widget);

	text =  build_text(24, get_rgb565(0x12, 0x96, 0xdb), 600, 652, "status", LAY_WIDGET1);
	widget = build_widget(WIDGET_TEXT, text);
	interface_add_widget(interface, widget);
}

static int set_temp;

void set_temp_add()
{
	set_temp++;
	if(set_temp >= 10)
		set_temp = 9;
	set_set_temp(set_temp, set_temp);
}

void set_temp_minus()
{
	set_temp--;
	if(set_temp <= 0)
		set_temp = 0;
	set_set_temp(set_temp, set_temp);
}


static void temp_init()
{
	interface_t *interface;
	button_t *button;
	widget_t *widget;
	enumpic_t *enumpic;
	interface = build_interface(TEMP, &temp_bg);
	resgister_interface(interface);

	button = build_button(SHAPE_RECT, &temp_BTretrun_normal, &temp_BTretrun_click, 20, 12, main_jump, LAY_WIDGET0);
	widget = build_widget(WIDGET_BUTTON, button);
	interface_add_widget(interface, widget);

	button = build_button(SHAPE_CIRCLE, &temp_BUTTONminus_normal, &temp_BUTTONminus_click, 60, 304, set_temp_minus, LAY_WIDGET0);
	widget = build_widget(WIDGET_BUTTON, button);
	interface_add_widget(interface, widget);

	button = build_button(SHAPE_CIRCLE, &temp_BUTTONadd_normal, &temp_BUTTONadd_click, 528, 304, set_temp_add, LAY_WIDGET0);
	widget = build_widget(WIDGET_BUTTON, button);
	interface_add_widget(interface, widget);

	enumpic =  build_enumpic(268, 280, &set_temp_1, LAY_WIDGET0);
	enumpic_add_case(enumpic, &temp_ENUM_0);
	enumpic_add_case(enumpic, &temp_ENUM_1);
	enumpic_add_case(enumpic, &temp_ENUM_2);
	enumpic_add_case(enumpic, &temp_ENUM_3);
	enumpic_add_case(enumpic, &temp_ENUM_4);
	enumpic_add_case(enumpic, &temp_ENUM_5);
	enumpic_add_case(enumpic, &temp_ENUM_6);
	enumpic_add_case(enumpic, &temp_ENUM_7);
	enumpic_add_case(enumpic, &temp_ENUM_8);
	enumpic_add_case(enumpic, &temp_ENUM_9);
	widget = build_widget(WIDGET_ENUMPIC, enumpic);
	interface_add_widget(interface, widget);

	enumpic =  build_enumpic(368, 280, &set_temp_1, LAY_WIDGET0);
	enumpic_add_case(enumpic, &temp_ENUM_0);
	enumpic_add_case(enumpic, &temp_ENUM_1);
	enumpic_add_case(enumpic, &temp_ENUM_2);
	enumpic_add_case(enumpic, &temp_ENUM_3);
	enumpic_add_case(enumpic, &temp_ENUM_4);
	enumpic_add_case(enumpic, &temp_ENUM_5);
	enumpic_add_case(enumpic, &temp_ENUM_6);
	enumpic_add_case(enumpic, &temp_ENUM_7);
	enumpic_add_case(enumpic, &temp_ENUM_8);
	enumpic_add_case(enumpic, &temp_ENUM_9);
	widget = build_widget(WIDGET_ENUMPIC, enumpic);
	interface_add_widget(interface, widget);
}

int humidity_value = 55;
char temp_set[10] = "20";

void humidity_change()
{
	int value = humidity_value * 100;
	value = value / humidity_SLIDER_back.w;
	sprintf(temp_set, "%d", value);
	sprintf(temp_show, "%d%%", value);
}

static void humidity_init()
{
	interface_t *interface;
	button_t *button;
	widget_t *widget;
	slider_t *slider;
	text_t *text;
	interface = build_interface(HUMIDIFY, &humidity_bg);
	resgister_interface(interface);

	button = build_button(SHAPE_RECT, &humidity_BTretrun_normal, &humidity_BTretrun_click, 20, 12, main_jump, LAY_WIDGET0);
	widget = build_widget(WIDGET_BUTTON, button);
	interface_add_widget(interface, widget);

	slider = build_slider(get_rgb565(0x12, 0x96, 0xdb), &humidity_SLIDER_back, &humidity_SLIDER_block, 16, 60, 360, &humidity_value, humidity_change, LAY_WIDGET0);
	widget = build_widget(WIDGET_SLIDER, slider);
	interface_add_widget(interface, widget);

	text =  build_text(32, get_rgb565(0x12, 0x96, 0xdb), 344, 281, temp_set, LAY_WIDGET1);
	widget = build_widget(WIDGET_TEXT, text);
	interface_add_widget(interface, widget);
}

static bool status[4];

static void switch_init()
{
	interface_t *interface;
	button_t *button;
	widget_t *widget;
	checkbox_t *check_box;
	interface = build_interface(SWITCH, &switch_bg);
	resgister_interface(interface);

	button = build_button(SHAPE_RECT, &humidity_BTretrun_normal, &humidity_BTretrun_click, 20, 12, main_jump, LAY_WIDGET0);
	widget = build_widget(WIDGET_BUTTON, button);
	interface_add_widget(interface, widget);

	check_box = build_checkbox(SHAPE_RECT, &switch_CB_on, &switch_CB_off, 204, 380, checkbox_cb_1, &status[0], LAY_WIDGET0);
	widget = build_widget(WIDGET_CHECKBOX, check_box);
	interface_add_widget(interface, widget);

	check_box = build_checkbox(SHAPE_RECT, &switch_CB_on, &switch_CB_off, 334, 380, checkbox_cb_2,  &status[1], LAY_WIDGET0);
	widget = build_widget(WIDGET_CHECKBOX, check_box);
	interface_add_widget(interface, widget);

	check_box = build_checkbox(SHAPE_RECT, &switch_CB_on, &switch_CB_off, 464, 380, checkbox_cb_3,  &status[2], LAY_WIDGET0);
	widget = build_widget(WIDGET_CHECKBOX, check_box);
	interface_add_widget(interface, widget);

	check_box = build_checkbox(SHAPE_RECT, &switch_CB_on, &switch_CB_off, 594, 380, checkbox_cb_4,  &status[3], LAY_WIDGET0);
	widget = build_widget(WIDGET_CHECKBOX, check_box);
	interface_add_widget(interface, widget);
}


static void ad_init()
{
	interface_t *interface;
	button_t *button;
	widget_t *widget;
	enumpic_t *enumpic;
	interface = build_interface(AD, &ad_bg);
	resgister_interface(interface);

	button = build_button(SHAPE_RECT, &ad_BTjump_normal, &ad_BTjump_click, 0, 0, main_jump, LAY_WIDGET0);
	widget = build_widget(WIDGET_BUTTON, button);
	interface_add_widget(interface, widget);

	enumpic =  build_enumpic(0, 0, &set_ad, LAY_WIDGET1);
	enumpic_add_case(enumpic, &ad_ENUM_0);
	enumpic_add_case(enumpic, &ad_ENUM_1);
	enumpic_add_case(enumpic, &ad_ENUM_2);
	enumpic_add_case(enumpic, &ad_ENUM_3);
	enumpic_add_case(enumpic, &ad_ENUM_4);
	enumpic_add_case(enumpic, &ad_ENUM_5);
	widget = build_widget(WIDGET_ENUMPIC, enumpic);
	interface_add_widget(interface, widget);
}

void maintain_init()
{
	interface_t *interface;
	interface = build_interface(MAINTAIN, &maintain_bg);
	resgister_interface(interface);	
}

void interactive_init()
{
	up_interface_init();
	main_init();
	temp_init();
	humidity_init();
	switch_init();
	ad_init();
	maintain_init();
	interface_jump(MAIN);//FIXME:
	STD_LOGI("resource init success");
}