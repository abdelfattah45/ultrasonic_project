// #include "ultrasonic.h"
// 
// static volatile uint8_t sensor_working = 0;
// static volatile uint8_t rising_edge = 0;
// static volatile uint32_t timer_counter = 0;
// static volatile uint16_t distance_cm = 0;
// static void Ultrasonic_INT1_Handler(void);
// 
// 
// static void Timer0_OverflowHandler(void)
// {
// 	timer_counter++;
// 	if (timer_counter > 730)  // timeout after ~30ms
// 	{
// 		timer_counter = 0;
// 		rising_edge = 0;
// 		sensor_working = 0;
// 	}
// }
// 
// void Ultrasonic_Init(void)
// {
// 	// TRIG as output, ECHO as input
// 	DIO_SetPinDirection(TRIG_PORT, TRIG_PIN, DIO_OUTPUT);
// 	DIO_SetPinDirection(ECHO_PORT, ECHO_PIN, DIO_INPUT);
// 	DIO_EnablePullup(ECHO_PORT, ECHO_PIN);
// 
// 	// Use your custom EXTI driver
// 	EXTI_Enable(EXTI_INT1, EXTI_ANY_CHANGE);
// 	EXTI_SetCallback(EXTI_INT1, Ultrasonic_INT1_Handler);
// 
// 	// Timer0 setup
// 	Timer0_Init(TIMER0_NORMAL, TIMER0_PRESCALE_8);
// 	Timer0_SetCallback(Timer0_OverflowHandler);
// }
// 
// 
// void Ultrasonic_Trigger(void)
// {
// 	if (!sensor_working)
// 	{
// 		DIO_SetPinValue(TRIG_PORT, TRIG_PIN, DIO_HIGH);
// 		_delay_us(15);
// 		DIO_SetPinValue(TRIG_PORT, TRIG_PIN, DIO_LOW);
// 		sensor_working = 1;
// 	}
// }
// 
// uint16_t Ultrasonic_GetDistance(void)
// {
// 	return distance_cm;
// }
// 
// 
// static void Ultrasonic_INT1_Handler(void)
// {
// 	if (!sensor_working) return;
// 
// 	if (rising_edge == 0)
// 	{
// 		TCNT0 = 0;
// 		timer_counter = 0;
// 		rising_edge = 1;
// 	}
// 	else
// 	{
// 		uint32_t ticks = (timer_counter * 256UL) + TCNT0;
// 		distance_cm = ticks / 466;
// 		rising_edge = 0;
// 		sensor_working = 0;
// 	}
// }
