/*
 * LCD.h
 *
 *  Created on: 7 Sep 2019
 *      Author: Kimo Store
 */

#ifndef LCD_H_
#define LCD_H_

/*
 * LCD CONFIGURATION
 */
#define LCD_PORT PORT2
#define LCD_ENABLE_PORT PORT1
#define LCD_ENABLE_PIN PIN5
#define LCD_RW_PORT PORT1
#define LCD_RW_PIN PIN6
#define LCD_RS_PORT PORT1
#define LCD_RS_PIN PIN7

/*
 * COMMANDS
 */
#define CLR_DISPLAY 0x01
#define RETURN_HOME 0x02
#define CURSOR_INCREMENT 0x06
#define CURSOR_DECREMENT 0x04
#define DISPLAY_ON 0x0F
#define DISPLAY_OF 0x08
#define DISPLAY_RIGHT_SHIFT 0x1C
#define DISPLAY_LEFT_SHIFT 0x18
#define CURSOR_RIGHT_SHIFT 0x14
#define CURSOR_LEFT_SHIFT 0x10
#define FUNCTION_SET 0x30
#define TOW_LINE_MODE 0x38
#define SET_DDR_ADDRESS 0x80
#define SECONDLINE_DDR_ADDRESS 0xC0


void LCD_Init (void);

void LCD_SendCommand (U8 Command);

void LCD_SendData (char Character);

void LCD_PrintString (char *String);

void LCD_PrintNumber (long int Number);

#endif /* LCD_H_ */
