#include "bluetooth_controller.h"
#include "display.h"


void confirm_connection()
{
    char success_message[50] = "Connection Successful, You're now connected to the mirror";
    UART_HandleTypeDef *huart;
    HAL_UART_Transmit(&huart, (uint8_t *)success_message, strlen(success_message), 50);
}

void confirm_master_connected()
{
}

void toggle_led_light_on()
{
    char on[6] = "LED on";
    volatile uint8_t generic_buffer[10];
    HAL_UART_Receive(&huart1, &generic_buffer, sizeof(generic_buffer), HAL_MAX_DELAY);
    if (generic_buffer[0] == 'y')
    {
        display_bluetooth_message(generic_buffer[0]);
        HAL_UART_Transmit(&huart1, &on, sizeof(on), HAL_MAX_DELAY);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
        display_bluetooth_message(generic_buffer);
    }
}

void toggle_led_light_off()
{
    char off[7] = "LED off";
    volatile uint8_t generic_buffer[10];
    HAL_UART_Receive(&huart1, &generic_buffer, sizeof(generic_buffer), HAL_MAX_DELAY);
    if (generic_buffer[0] == 'n')
    {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
        HAL_UART_Transmit(&huart1, &off, sizeof(off), HAL_MAX_DELAY);
        display_bluetooth_message(generic_buffer);
    }
}

void transmit_camera_image()
{
    //	HAL_UART_Transmit(&UartHandle, (uint8_t*)msg, sizeof(msg), 10);
}

void turn_off_device() {}

void take_photo() {}

void send_error_message() {}
