/*
 * LCD.c
 *
 *  Created on: 7 Sep 2019
 *      Author: Kimo Store
 */
#include "Std_types.h"
#include "Registers.h"
#include "BitOperations.h"
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"


void LCD_Init (void)
{

	DIO_SetPortDirection (LCD_PORT, OUTPUT);
	DIO_SetPinDirection (LCD_ENABLE_PORT, LCD_ENABLE_PIN,OUTPUT);
	DIO_SetPinDirection (LCD_RW_PORT, LCD_RW_PIN,OUTPUT);
	DIO_SetPinDirection (LCD_RS_PORT, LCD_RS_PIN,OUTPUT);
	LCD_SendCommand (DISPLAY_ON);
	LCD_SendCommand (TOW_LINE_MODE);
	LCD_SendCommand (RETURN_HOME);
	LCD_SendCommand (CLR_DISPLAY);
}

void LCD_SendCommand (U8 Command)
{

	DIO_SetPinValue (LCD_RS_PORT, LCD_RS_PIN, LOW);
	DIO_SetPinValue (LCD_RW_PORT, LCD_RW_PIN, LOW);
	_delay_ms(2);
	DIO_SetPinValue (LCD_ENABLE_PORT, LCD_ENABLE_PIN, HIGH);
	_delay_ms(2);
	DIO_SetPortValue (LCD_PORT, Command);
	_delay_ms(2);
	DIO_SetPinValue (LCD_ENABLE_PORT, LCD_ENABLE_PIN, LOW);
	_delay_ms(2);
}

void LCD_SendData (char Character)
{
	DIO_SetPinValue (LCD_RS_PORT, LCD_RS_PIN, HIGH);
	DIO_SetPinValue (LCD_RW_PORT, LCD_RW_PIN, LOW);
	_delay_ms(2);
	DIO_SetPinValue (LCD_ENABLE_PORT, LCD_ENABLE_PIN, HIGH);
	_delay_ms(2);
	DIO_SetPortValue (LCD_PORT, Character);
	_delay_ms(2);
	DIO_SetPinValue (LCD_ENABLE_PORT, LCD_ENABLE_PIN, LOW);
	_delay_ms(2);

}

void LCD_PrintString (char *String)
{
	U8 i;
	for (i=0;((String[i])!='\0'); i++)
	{
		LCD_SendData ((String[i]));
	}
}

void LCD_PrintNumber (long int Number)
{
		int y;
		int n=0;
	    int j,i;
	    char length=0;
	    char count =0;
	    char l;
	    int num=1;
	    int x,z;
	    char array[100]= {0};
	   // char array_2[100]= {0};
	    y = Number;
	    for (j=0; Number != 0; j++)
	    {
	        n = Number;
	        Number = (Number%10);
	        Number = n/10;
	        length = (j);
	    }
	    for ( i=(length) ; i>=0 ; i--)
	    {
	        for (l=0; l<i ; l++)
	        {
	            num *=10;
	        }
	        x = y % (num);
	        z = (y-x);
	        array[i-length+count] = ((z/num) + '0');
	        count +=2;
	        num = 1;
	      	 y = y-z;

	    }

	    LCD_PrintString (array);

}
