// #ifndef ULTRASONIC_H_
// #define ULTRASONIC_H_
// 
// #include <stdint.h>
// #include <avr/interrupt.h>
// #include <util/delay.h>
// #include "../TIMER/timer.h"
// #include "../Interrupt/exti.h"
// 
// #include "../DIO/dio.h"
// // TRIG: PD6, ECHO: PD3 (INT1)
// #define TRIG_PORT   DIO_PORTD
// #define TRIG_PIN    PIN_6
// 
// #define ECHO_PORT   DIO_PORTD
// #define ECHO_PIN    PIN_3
// 
// void Ultrasonic_Init(void);
// void Ultrasonic_Trigger(void);
// uint16_t Ultrasonic_GetDistance(void);  // call this from main loop
// 
// #endif
