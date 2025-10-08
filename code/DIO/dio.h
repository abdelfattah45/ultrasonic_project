#ifndef DIO_H_
#define DIO_H_

#include <avr/io.h>
#include <stdint.h>

// Port identifiers
#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

#define PIN_0	   0
#define PIN_1      1
#define PIN_2      2
#define PIN_3      3
#define PIN_4	   4
#define PIN_5      5
#define PIN_6      6
#define PIN_7      7

// Direction
#define DIO_INPUT  0
#define DIO_OUTPUT 1

// Value
#define DIO_LOW    0
#define DIO_HIGH   1

void DIO_SetPinDirection(uint8_t port, uint8_t pin, uint8_t direction);
void DIO_SetPinValue(uint8_t port, uint8_t pin, uint8_t value);
uint8_t DIO_GetPinValue(uint8_t port, uint8_t pin);
void DIO_TogglePin(uint8_t port, uint8_t pin);  
void DIO_EnablePullup(uint8_t port, uint8_t pin);
void DIO_SetPortValue(uint8_t port, uint8_t value);
#endif /* DIO_H_ */
