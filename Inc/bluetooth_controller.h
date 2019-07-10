#include "usart.h"
#include <string.h>

#ifndef BLUETOOTH_CONTROLLER_H_
#define BLUETOOTH_CONTROLLER_H_

void establish_master_relationship(void);

void transmit_camera_image(void);

void take_photo(void);

void confirm_connection();

void send_error_message(void);

char bluetooth_status(void);

void turn_off_device(void);

#endif /* BLUETOOTH_CONTROLLER_H_ */
