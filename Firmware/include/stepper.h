#ifndef STEPPER_H
#define STEPPER_H

#include <stdint.h>

void init_stepper_ports(void);
void init_tim(void);
void init_t(void);
void delay(uint16_t ms);

#endif