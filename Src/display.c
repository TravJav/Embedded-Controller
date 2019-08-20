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
  SSD1306_UpdateScreen(); //display
  HAL_Delay(1000);
  SSD1306_Fill(0); //clear oled
}

void display_bluetooth_message(volatile uint8_t *generic_buffer)
{
    SSD1306_GotoXY(0, 0);               // goto 10, 10
    SSD1306_Puts("Hello", &Font_11x18, 1); // print Hello
    SSD1306_GotoXY(10, 30);
    SSD1306_Puts(generic_buffer, &Font_11x18, 1);
    SSD1306_UpdateScreen();
    HAL_Delay(5000);
    SSD1306_ScrollRight(0x00, 0x0f);
}

void perform_animation() {}

void display_loading_symbol() {}

void display_percentage_symbol() {}

void display_warning_message()
{
    update_view();
    SSD1306_GotoXY(7, 30);
    SSD1306_Puts("Warning", &Font_7x10, 1);
}

void start_up_confirmation()
{
    update_view();
    SSD1306_GotoXY(10, 30);
    SSD1306_Puts("Initializing...", &Font_7x10, 1);
}


void perform_demo(){
    /* USER CODE BEGIN 2 */
  uint8_t res = SSD1306_Init();
  printf("OLED init: %d\n", res);
  SSD1306_GotoXY(10, 27);
  SSD1306_Puts("OLED inited", &Font_7x10, 1);
  SSD1306_GotoXY(10, 52);
  SSD1306_Puts("Travis Haycock", &Font_7x10, 1);
  SSD1306_UpdateScreen(); //display
  HAL_Delay(1000);
  SSD1306_Fill(0); //clear oled
  int y1 = 64, y2 = 0;
  while (y1 > 0)
  {
    SSD1306_DrawLine(0, y1, 128, y2, 1);
    SSD1306_UpdateScreen();
    y1 -= 2;
    y2 += 2;
  }
  HAL_Delay(1000);
  SSD1306_Fill(1); //clear oled
  SSD1306_UpdateScreen();
  SSD1306_DrawCircle(64, 32, 25, 0);
  SSD1306_UpdateScreen();
  SSD1306_DrawCircle(128, 32, 25, 0);
  SSD1306_UpdateScreen();
  SSD1306_DrawCircle(0, 32, 25, 0);
  SSD1306_UpdateScreen();
  SSD1306_DrawCircle(32, 32, 25, 0);
  SSD1306_UpdateScreen();
  SSD1306_DrawCircle(96, 32, 25, 0);
  SSD1306_UpdateScreen();
  HAL_Delay(1000);

  SSD1306_Fill(0); //clear oled
  SSD1306_UpdateScreen();
  int32_t i = -100;
  char buf[10];
  while (i <= 100)
  {
    memset(&buf[0], 0, sizeof(buf));
    sprintf(buf, "%d", i);
    SSD1306_GotoXY(50, 27);
    SSD1306_Puts(buf, &Font_7x10, 1);
    SSD1306_DrawLine(64, 10, (i + 100) * 128 / 200, (i + 100) * 64 / 200, 1);
    SSD1306_UpdateScreen();
    SSD1306_Fill(0); //clear oled
    i++;
  }
  SSD1306_GotoXY(50, 27);
  sprintf(buf, "END");
  SSD1306_Puts(buf, &Font_7x10, 1);
  SSD1306_GotoXY(10, 52);
  SSD1306_Puts("Travis Haycock", &Font_7x10, 1);
  SSD1306_UpdateScreen();
  SSD1306_Fill(0); //clear oled
  HAL_Delay(1000);
  uint32_t lst = 0, cu;
    cu = HAL_GetTick();
    SSD1306_GotoXY(30, 27);
    sprintf(buf, "fps: %f", 1000.0 / (double)(cu - lst));
}

