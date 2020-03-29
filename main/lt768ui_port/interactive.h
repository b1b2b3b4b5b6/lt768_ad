#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include "operation.h"
#include "lt768ui_resources.h"
#include "custom_resources.h"
#include "up_interface.h"

void interactive_init();

void main_jump();
void humidity_jump();
void temp_jump();
void switch_jump();
void ad_jump();
void maintain_jump();

#endif