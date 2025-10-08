#include "dio.h"

void DIO_SetPinDirection(uint8_t port, uint8_t pin, uint8_t direction) {
	switch(port) {
		case DIO_PORTA:
		{
			if (direction == DIO_OUTPUT)
				DDRA |= (1 << pin);
			else
				DDRA &= ~(1 << pin);
			break;	
		}
		case DIO_PORTB:
		{
			if (direction == DIO_OUTPUT)
				DDRB |= (1 << pin);
			else
				DDRB &= ~(1 << pin);
			break;	
		}
		case DIO_PORTC:
		{
			if (direction == DIO_OUTPUT)
				DDRC |= (1 << pin);
			else
				DDRC &= ~(1 << pin);
			break;
		}
		case DIO_PORTD:
		{
			if (direction == DIO_OUTPUT)
				DDRD |= (1 << pin);
			else
				DDRD &= ~(1 << pin);
			break;
		}
	}
}

void DIO_SetPinValue(uint8_t port, uint8_t pin, uint8_t value) {
	switch(port) {
		case DIO_PORTA:
		{
			if (value == DIO_HIGH)
				PORTA |= (1 << pin);
			else
				PORTA &= ~(1 << pin);
			break;
		}
		case DIO_PORTB:
		{
			if (value == DIO_HIGH)
				PORTB |= (1 << pin);
			else
				PORTB &= ~(1 << pin);
			break;
		}
		case DIO_PORTC:
		{
			if (value == DIO_HIGH)
				PORTC |= (1 << pin);
			else
				PORTC &= ~(1 << pin);
			break;
		}
		case DIO_PORTD:
		{
			if (value == DIO_HIGH)
				PORTD |= (1 << pin);
			else
				PORTD &= ~(1 << pin);
			break;
		}
	}
}

uint8_t DIO_GetPinValue(uint8_t port, uint8_t pin) {
	switch(port) {
		case DIO_PORTA:
		return (PINA & (1 << pin)) ? 1 : 0;
		case DIO_PORTB:
		return (PINB & (1 << pin)) ? 1 : 0;
		case DIO_PORTC:
		return (PINC & (1 << pin)) ? 1 : 0;
		case DIO_PORTD:
		return (PIND & (1 << pin)) ? 1 : 0;
		default:
		return 0;
	}
}
void DIO_SetPortValue(uint8_t port, uint8_t value) {
	switch(port) {
		case DIO_PORTA: PORTA = value; break;
		case DIO_PORTB: PORTB = value; break;
		case DIO_PORTC: PORTC = value; break;
		case DIO_PORTD: PORTD = value; break;
	}
}
void DIO_EnablePullup(uint8_t port, uint8_t pin) {
	switch(port) {
		case DIO_PORTA: PORTA |= (1 << pin); break;
		case DIO_PORTB: PORTB |= (1 << pin); break;
		case DIO_PORTC: PORTC |= (1 << pin); break;
		case DIO_PORTD: PORTD |= (1 << pin); break;
	}
}

void DIO_TogglePin(uint8_t port, uint8_t pin) {
	switch(port) {
		case DIO_PORTA: PORTA ^= (1 << pin); break;
		case DIO_PORTB: PORTB ^= (1 << pin); break;
		case DIO_PORTC: PORTC ^= (1 << pin); break;
		case DIO_PORTD: PORTD ^= (1 << pin); break;
	}
}



