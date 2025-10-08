#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

// LCD pins
#define LCD_PORT PORTA
#define LCD_DDR  DDRA

#define LCD_RS PA0
#define LCD_EN PA1
#define LCD_D4 PA2
#define LCD_D5 PA3
#define LCD_D6 PA4
#define LCD_D7 PA5

static void LCD_EnablePulse(void) {
	LCD_PORT |= (1 << LCD_EN);
	_delay_us(1);
	LCD_PORT &= ~(1 << LCD_EN);
	_delay_us(100);
}

static void LCD_Send4Bits(uint8_t data) {
	if (data & 0x01) LCD_PORT |= (1 << LCD_D4); else LCD_PORT &= ~(1 << LCD_D4);
	if (data & 0x02) LCD_PORT |= (1 << LCD_D5); else LCD_PORT &= ~(1 << LCD_D5);
	if (data & 0x04) LCD_PORT |= (1 << LCD_D6); else LCD_PORT &= ~(1 << LCD_D6);
	if (data & 0x08) LCD_PORT |= (1 << LCD_D7); else LCD_PORT &= ~(1 << LCD_D7);
	LCD_EnablePulse();
}

void LCD_SendCommand(uint8_t cmd) {
	LCD_PORT &= ~(1 << LCD_RS); // RS = 0 for command
	LCD_Send4Bits(cmd >> 4);
	LCD_Send4Bits(cmd & 0x0F);
	_delay_ms(2);
}

void LCD_SendChar(char data) {
	LCD_PORT |= (1 << LCD_RS); // RS = 1 for data
	LCD_Send4Bits(data >> 4);
	LCD_Send4Bits(data & 0x0F);
	_delay_us(100);
}

void LCD_SendString(const char *str) {
	while (*str) {
		LCD_SendChar(*str++);
	}
}

void LCD_SetCursor(uint8_t row, uint8_t col) {
	uint8_t address = (row == 0) ? 0x00 : 0x40;
	address += col;
	LCD_SendCommand(0x80 | address);
}
void LCD_Clear(void) {
	LCD_SendCommand(LCD_CLEAR_DISPLAY);
	_delay_ms(2);  // Required delay after clearing
}

void LCD_Init(void) {
	// Set control and data pins as output
	LCD_DDR |= (1 << LCD_RS) | (1 << LCD_EN) |
	(1 << LCD_D4) | (1 << LCD_D5) |
	(1 << LCD_D6) | (1 << LCD_D7);

	_delay_ms(20);  // Wait for LCD to power up

	// Initialization sequence
	LCD_Send4Bits(0x03); _delay_ms(5);
	LCD_Send4Bits(0x03); _delay_us(200);
	LCD_Send4Bits(0x03); _delay_us(200);
	LCD_Send4Bits(0x02);  // Set 4-bit mode

	// Configure LCD
	LCD_SendCommand(LCD_FUNCTION_SET);
	LCD_SendCommand(LCD_DISPLAY_ON);
	LCD_SendCommand(LCD_CLEAR_DISPLAY);
	LCD_SendCommand(LCD_ENTRY_MODE);
}
