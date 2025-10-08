
// ultrasonic project:: new features

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h> 
#include "LCD/lcd.h"
#include "DIO/dio.h"
#include "Ultrasonic/ultrasonic.h"


// Select version to build:
//#define USE_BARE_METAL
#define USE_RTOS

#ifdef USE_RTOS
#include "FreeRTOS.h"
#include "task.h"
void vApplicationIdleHook() {}
#endif

// === PIN DEFINITIONS ===
#define LED_PORT     DIO_PORTC
#define LED_PIN      PIN_0

#define BUZZER_PORT  DIO_PORTC
#define BUZZER_PIN   PIN_1

#define THRESHOLD_CM 20

void init_hardware() {
	LCD_Init();
	Ultrasonic_Init();

	DIO_SetPinDirection(LED_PORT, LED_PIN, DIO_OUTPUT);
	DIO_SetPinDirection(BUZZER_PORT, BUZZER_PIN, DIO_OUTPUT);
	DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
}
#ifdef USE_BARE_METAL

int main(void) {
	char buffer[16];
	uint16_t distance;

	init_hardware();

	while (1) {
		// Toggle LED
		DIO_TogglePin(LED_PORT, LED_PIN);

		// Read ultrasonic distance
		distance = Ultrasonic_ReadDistance();

		// Display on LCD
		LCD_SetCursor(0, 0);
		LCD_SendString("Dist: ");
		itoa(distance, buffer, 10);
		LCD_SendString(buffer);
		LCD_SendString(" cm     ");

		// Control buzzer
		if (distance > THRESHOLD_CM) {
			DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_HIGH);
			} else {
			DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
		}

		_delay_ms(500);
	}
}

#endif

#ifdef USE_RTOS

void UltrasonicTask(void *pvParameters) {
	char buffer[16];
	uint16_t distance;

	while (1) {
		distance = Ultrasonic_ReadDistance();

		// Display on LCD
		LCD_SetCursor(0, 0);
		LCD_SendString("Dist: ");
		itoa(distance, buffer, 10);
		LCD_SendString(buffer);
		LCD_SendString(" cm     ");

		// Control buzzer
		if (distance > THRESHOLD_CM) {
			DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_HIGH);
			} else {
			DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
		}

		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

void LEDTask(void *pvParameters) {
	while (1) {
		DIO_TogglePin(LED_PORT, LED_PIN);
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

int main(void) {
	init_hardware();

	xTaskCreate(UltrasonicTask, "ULTRA", 128, NULL, 2, NULL);
	xTaskCreate(LEDTask, "LED", 128, NULL, 1, NULL);

	vTaskStartScheduler();
	while (1);
}

#endif
