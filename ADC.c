/*
 * ADC.c
 *
 *  Created on: 5 Oct 2019
 *      Author: Kimo Store
 */

#include "Std_types.h"
#include "Registers.h"
#include "BitOperations.h"
#include <avr/interrupt.h>
#include "ADC.h"
#include "EXINT.h"
#include "EXINT_Cfg.h"

static U16 ADC_result;

void ADC_Init (void)
{
#if (REF_VOLTAGE == AREF)
	CLRBIT(ADMUX,6);
	CLRBIT(ADMUX,7);
#elif (REF_VOLTAGE == AVCC)
	SETBIT(ADMUX,6);
	CLRBIT(ADMUX,7);
#elif (REF_VOLTAGE == INTERNAL)
	SETBIT(ADMUX,6);
	SETBIT(ADMUX,7);
#endif

#if PRESCALER == 8
	SETBIT(ADCSRA,0);
	SETBIT(ADCSRA,1);
	CLRBIT(ADCSRA,2);

#elif PRESCALER == 128
	SETBIT(ADCSRA,0);
	SETBIT(ADCSRA,1);
	SETBIT(ADCSRA,2);
#endif
	// ADClAR
#if (ADJUSTMENT==RIGHT_ADJUST)
	CLRBIT(ADMUX,5);
#elif (ADJUSTMENT==LEFT_ADJUST)

	 SETBIT(ADMUX,5);
#endif
// single mode handled in functions
#if MODE == AUTO_FREERUNNING
	SETBIT(ADCSRA,5);  // enable Auto trigger
	SETBIT(SREG,7);    // global interrupt enable
	SETBIT(ADCSRA,3);  // local interrupt enable
	CLRBIT(SFIOR,5);   // select free running mode
	CLRBIT(SFIOR,6);
	CLRBIT(SFIOR,7);
	SETBIT(ADCSRA,6);  //ADC start Conversion

#elif MODE == AUTO_EXTERNALINTERUPT
	SETBIT(ADCSRA,5);  // enable Auto trigger
	SETBIT(SREG,7);    // global interrupt enable
	SETBIT(ADCSRA,3);  // local interrupt enable
	CLRBIT(SFIOR,5);   // select external interrupt mode
	SETBIT(SFIOR,6);
	CLRBIT(SFIOR,7);
	SETBIT(ADCSRA,6);  //ADC start Conversion
#endif
	       // ADC enable
	SETBIT(ADCSRA,7);
}
#if RESOLUTION == 8
U8 ADC_Read (U8 channel)
{

	 U8 x,return_val;
		CLRBIT(ADMUX,3);
	    CLRBIT(ADMUX,4);
		switch (channel)
		{
		case (0):
			CLRBIT(ADMUX,0);
		    CLRBIT(ADMUX,1);
		    CLRBIT(ADMUX,2);
		  break;

		case (1):
			SETBIT(ADMUX,0);
		    CLRBIT(ADMUX,1);
		    CLRBIT(ADMUX,2);
		  break;
		case (2):
			CLRBIT(ADMUX,0);
		    SETBIT(ADMUX,1);
		    CLRBIT(ADMUX,2);
		  break;
		case (3):
			SETBIT(ADMUX,0);
		    SETBIT(ADMUX,1);
		    CLRBIT(ADMUX,2);
		  break;

		case (4):
			CLRBIT(ADMUX,0);
		    CLRBIT(ADMUX,1);
		    SETBIT(ADMUX,2);
		  break;

		case (5):
			SETBIT(ADMUX,0);
		    CLRBIT(ADMUX,1);
		    SETBIT(ADMUX,2);
		  break;

		case (6):
			CLRBIT(ADMUX,0);
		    SETBIT(ADMUX,1);
		    SETBIT(ADMUX,2);
		  break;

		case (7):
			SETBIT(ADMUX,0);
		    SETBIT(ADMUX,1);
		    SETBIT(ADMUX,2);
		  break;

		default:
			break;
	}
		SETBIT(ADCSRA,6);  // ADC start Conversion
		while (GETBIT(ADCSRA,6));
		x = ADCH;
		return_val = ((x*5)/256.0)*100; //over flow happen, so it is better to do this equation out from this function
		return (x);
}

#elif RESOLUTION == 10
U16 ADC_Read (U8 channel)
{
	U16 x,return_val;
	CLRBIT(ADMUX,3);
    CLRBIT(ADMUX,4);
	switch (channel)
	{
	case (0):
		CLRBIT(ADMUX,0);
	    CLRBIT(ADMUX,1);
	    CLRBIT(ADMUX,2);
	  break;

	case (1):
		SETBIT(ADMUX,0);
	    CLRBIT(ADMUX,1);
	    CLRBIT(ADMUX,2);
	  break;
	case (2):
		CLRBIT(ADMUX,0);
	    SETBIT(ADMUX,1);
	    CLRBIT(ADMUX,2);
	  break;
	case (3):
		SETBIT(ADMUX,0);
	    SETBIT(ADMUX,1);
	    CLRBIT(ADMUX,2);
	  break;

	case (4):
		CLRBIT(ADMUX,0);
	    CLRBIT(ADMUX,1);
	    SETBIT(ADMUX,2);
	  break;

	case (5):
		SETBIT(ADMUX,0);
	    CLRBIT(ADMUX,1);
	    SETBIT(ADMUX,2);
	  break;

	case (6):
		CLRBIT(ADMUX,0);
	    SETBIT(ADMUX,1);
	    SETBIT(ADMUX,2);
	  break;

	case (7):
		SETBIT(ADMUX,0);
	    SETBIT(ADMUX,1);
	    SETBIT(ADMUX,2);
	  break;

	default:
		break;
}
	// ADC start Conversion
	SETBIT(ADCSRA,6);
	while (GETBIT(ADCSRA,6));
	x = ADCL;
	x |= ((U16)ADCH<<8);
	return_val = ((x*5)/1024.0)*1000;
	return (return_val);
}

ISR (ADC_vect)
{
	 Set_ADC_value();
}

void Set_ADC_value (void)
{
	ADC_result = ADCL;
	ADC_result |= ((U16)ADCH<<8);
}

U16 Get_ADC_value (void)
{
	U16 ret_val;
	ret_val = ADC_result;
	return (ret_val);
}
#endif
