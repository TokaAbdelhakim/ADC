/*
 * DIO.c
 *
 *  Created on: 31 Aug 2019
 *      Author: Kimo Store
 */

#include "Std_types.h"
#include "Registers.h"
#include "BitOperations.h"
#include "DIO.h"

void DIO_SetPinDirection (U8 Port_number, U8 Pin_number, U8 Direction)

{
	switch (Port_number)
	{
	 case PORT0 :
	  if (Direction == OUTPUT)
	  {
		  SETBIT (DDRA,Pin_number);
	  }
	  else if (Direction == INPUT)
	  {
		  CLRBIT (DDRA,Pin_number);
	  }
	 break;

	 case PORT1:
	  if (Direction == OUTPUT)
	  {
		  SETBIT (DDRB,Pin_number);
	  }
	  else if (Direction == INPUT)
	  {
		  CLRBIT (DDRB,Pin_number);
	  }
	 break;

	 case PORT2:
	  if (Direction == OUTPUT)
	  {
		  SETBIT (DDRC,Pin_number);
	  }
	  else if (Direction == INPUT)
	  {
		  CLRBIT (DDRC,Pin_number);
	  }
	 break;

	 case PORT3:
	  if (Direction == OUTPUT)
	  {
		  SETBIT (DDRD,Pin_number);
	  }
	  else if (Direction == INPUT)
	  {
		  CLRBIT (DDRD,Pin_number);
	  }
	 break;
	}

}

void DIO_SetPortDirection (U8 Port_number, U8 Direction)
{
	switch (Port_number)
		{
		 case PORT0 :
		  if (Direction == OUTPUT)
		  {
			 DDRA = 0xFF;
		  }
		  else if (Direction == INPUT)
		  {
			  DDRA = 0x00;
		  }
		 break;

		 case PORT1:
		  if (Direction == OUTPUT)
		  {
			  DDRB = 0xFF;
		  }
		  else if (Direction == INPUT)
		  {
			  DDRB = 0x00;
		  }
		 break;

		 case PORT2:
		  if (Direction == OUTPUT)
		  {
			  DDRC = 0xFF;
		  }
		  else if (Direction == INPUT)
		  {
			  DDRC = 0x00;
		  }
		 break;

		 case PORT3:
		  if (Direction == OUTPUT)
		  {
			  DDRD = 0xFF;
		  }
		  else if (Direction == INPUT)
		  {
			  DDRD = 0x00;
		  }
		 break;
		}

}

void DIO_SetPinPullup (U8 Port_number, U8 Pin_number)
{
	CLRBIT (SFIOR,2);
	switch (Port_number)
	{
		case PORT0:
			SETBIT (PORTA,Pin_number);
		break;

		case PORT1:
			SETBIT (PORTB,Pin_number);
		break;

		case PORT2:
			SETBIT (PORTC,Pin_number);
		break;

		case PORT3:
			SETBIT (PORTD,Pin_number);
		break;

	}
}


void DIO_SetPinValue (U8 Port_number, U8 Pin_number, U8 value)
{
	switch (Port_number)
	{
		case PORT0:
		if ((GETBIT(DDRA,Pin_number)) == OUTPUT)
		{
			if (value == HIGH)
			{
				SETBIT (PORTA,Pin_number);
			}
			else if (value == LOW)
			{
				CLRBIT (PORTA,Pin_number);
			}
		}
		break;

		case PORT1:
		if ((GETBIT(DDRB,Pin_number)) == OUTPUT)
		{
			if (value == HIGH)
			{
				SETBIT (PORTB,Pin_number);
			}
			else if (value == LOW)
			{
				CLRBIT(PORTB,Pin_number);
			}
		}
		break;
		case PORT2:
		if ((GETBIT(DDRC,Pin_number)) == OUTPUT)
		{
			if (value == HIGH)
			{
				SETBIT (PORTC,Pin_number);
			}
			else if (value == LOW)
			{
				CLRBIT (PORTC,Pin_number);
			}
		}
		break;
		case PORT3:
		if ((GETBIT(DDRD,Pin_number)) == OUTPUT)
		{
			if (value == HIGH)
			{
				SETBIT (PORTD,Pin_number);
			}
			else if (value == LOW)
			{
				CLRBIT (PORTD,Pin_number);
			}
		}
		break;

	}
}

U8 DIO_GetPinValue (U8 Port_number, U8 Pin_number)
{
	U8 return_val=0;
	switch (Port_number)
	{
		case PORT0:
				return_val = GETBIT(PINA,Pin_number);
		break;

		case PORT1:

			return_val = GETBIT(PINB,Pin_number);
		break;

		case PORT2:
			return_val = GETBIT(PINC,Pin_number);
		break;

		case PORT3:
			return_val = GETBIT(PIND,Pin_number);
		break;

	}
	return return_val;
}
void DIO_SetPortValue (U8 Port_number, U8 port_Value)
{
	switch (Port_number)
	{
	case PORT0:
		PORTA =  port_Value;
	break;

	case PORT1:
		PORTB =  port_Value;
	break;

	case PORT2:
		PORTC =  port_Value;
	break;

	case PORT3:
		PORTD =  port_Value;
	break;

	}
}
