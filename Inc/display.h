/*
 * display.h
 *
 *  Created on: Aug 15, 2019
 *      Author: travjav
 */
//https://www.controllerstech.com/oled-display-using-i2c-stm32/
#include "ssd1306.h"
#include "fonts.h"
#include "test.h"
#include "bitmap.h"

#ifndef DISPLAY_H_
#define DISPLAY_H_

void display_new_text();

void perform_demo();

void update_view();

void perform_animation();

void display_loading_symbol();

void display_percentage_symbol();

void display_warning_message();

void start_up_confirmation();

void display_bluetooth_message();

void init_display();

#endif /* DISPLAY_H_ */
