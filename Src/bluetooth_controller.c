#include "bluetooth_controller.h"


void confirm_connection(){
 char success_message[50] = "Connection Successful, You're now connected to the mirror";
 UART_HandleTypeDef *huart;
 HAL_UART_Transmit(&huart, (uint8_t *) success_message, strlen(success_message), 50);
}

void confirm_master_connected(){

}

void transmit_camera_image(){
//	HAL_UART_Transmit(&UartHandle, (uint8_t*)msg, sizeof(msg), 10);
}

void turn_off_device(){}

void take_photo(){}

void send_error_message(){}
