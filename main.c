/*
 * main.c
 *
 *  Created on: 6 Oct 2019
 *      Author: Kimo Store
 */

#include "Std_types.h"
#include "Registers.h"
#include "BitOperations.h"
#include "LCD.h"
#include "EXINT.h"
#include <avr/interrupt.h>
#include "ADC.h"

//void Calculate_ADC_value(void);

int main (void)
{
	LCD_Init();
	ADC_Init ();

	EXINT0_Init ();
	EXINT0_SetISR (Calculate_ADC_value);

	while (1)
	{
		//free running
	}
	return 0;
}

// external interrupt
void Calculate_ADC_value(void)
{
	        volatile U16 x,v;
	        Set_ADC_value();
	        x = Get_ADC_value();
			v = ((x*5)/(1024.0*1000))+2;
			LCD_SendCommand (SECONDLINE_DDR_ADDRESS);
			LCD_PrintString ("     ");
			LCD_SendCommand (SECONDLINE_DDR_ADDRESS);
			LCD_PrintNumber (v);
}
