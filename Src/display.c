/*
 * display.c
 *
 *  Created on: Aug 15, 2019
 *      Author: travjav
 */
#include "display.h"

void init_display()
{
 // initialize the diaply
}

void update_view()
{
    SSD1306_UpdateScreen();
}

void display_bluetooth_message(char message)
{
    update_view();
    SSD1306_GotoXY(10, 30);
    SSD1306_Puts(message, &Font_7x10, 1);
}

void perform_animation() {}

void display_loading_symbol() {}

void display_percentage_symbol() {}

void display_warning_message()
{
    update_view();
    SSD1306_GotoXY(10, 30);
    SSD1306_Puts("Warning", &Font_7x10, 1);
}

void start_up_confirmation()
{
    update_view();
    SSD1306_GotoXY(10, 30);
    SSD1306_Puts("Initializing...", &Font_7x10, 1);
}
