#ifndef LCD_H_
#define LCD_H_

#include <stdint.h>

// LCD Commands
#define LCD_CLEAR_DISPLAY    0x01
#define LCD_RETURN_HOME      0x02
#define LCD_ENTRY_MODE       0x06
#define LCD_DISPLAY_ON       0x0C
#define LCD_FUNCTION_SET     0x28  // 4-bit, 2 lines, 5x8 font

// API
void LCD_Init(void);
void LCD_SendCommand(uint8_t cmd);
void LCD_SendChar(char data);
void LCD_SendString(const char *str);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Clear(void);
#endif /* LCD_H_ */
