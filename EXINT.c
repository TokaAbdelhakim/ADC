/*
 * EXINT.C
 *
 *  Created on: 14 Sep 2019
 *      Author: Kimo Store
 */

#include "Std_types.h"
#include "BitOperations.h"
#include "Registers.h"
#include "DIO.h"
#include "EXINT.h"
#include "EXINT_Cfg.h"
#include <avr/interrupt.h>

static void (* Gptr0) (void);
static void (* Gptr1) (void);
static void (* Gptr2) (void);

void EXINT0_Init (void)
{

#if  CHECKMODE_INT0 == MODE_INT0_LL

	    DIO_SetPinDirection (EXINT0_PORT,EXINT0_PIN,INPUT);
	    DIO_SetPinPullup (EXINT0_PORT, EXINT0_PIN);
		SETBIT(SREG,IBIT);
		CLRBIT(MCUCR,0);
		CLRBIT(MCUCR,1);
		SETBIT(GICR,GICR_INT0);

#elif CHECKMODE_INT0 == MODE_INT0_AC
	    DIO_SetPinDirection (EXINT0_PORT,EXINT0_PIN,INPUT);
		SETBIT(SREG,IBIT);
		SETBIT(MCUCR,0);
		CLRBIT(MCUCR,1);
		SETBIT(GICR,GICR_INT0);

#elif CHECKMODE_INT0 == MODE_INT0_FE
	    DIO_SetPinDirection (EXINT0_PORT,EXINT0_PIN,INPUT);
	    DIO_SetPinPullup (EXINT0_PORT, EXINT0_PIN);
		SETBIT(SREG,IBIT);
		CLRBIT(MCUCR,0);
		SETBIT(MCUCR,1);
		SETBIT(GICR,GICR_INT0);

#elif CHECKMODE_INT0 == MODE_INT0_RE
	    DIO_SetPinDirection (EXINT0_PORT,EXINT0_PIN,INPUT);
		SETBIT(SREG,IBIT);
		SETBIT(MCUCR,0);
		SETBIT(MCUCR,1);
		SETBIT(GICR,GICR_INT0);
#endif

}


void EXINT1_Init (void)
{

#if  CHECKMODE_INT1 == MODE_INT1_LL

	    DIO_SetPinDirection (EXINT1_PORT,EXINT1_PIN,INPUT);
	    DIO_SetPinPullup (EXINT1_PORT, EXINT1_PIN);
		SETBIT(SREG,IBIT);
		CLRBIT(MCUCR,2);
		CLRBIT(MCUCR,3);
		SETBIT(GICR,GICR_INT1);

#elif CHECKMODE_INT1 == MODE_INT1_AC
	    DIO_SetPinDirection (EXINT1_PORT,EXINT1_PIN,INPUT);
		SETBIT(SREG,IBIT);
		SETBIT(MCUCR,2);
		CLRBIT(MCUCR,3);
		SETBIT(GICR,GICR_INT1);

#elif CHECKMODE_INT1 == MODE_INT1_FE
	    DIO_SetPinDirection (EXINT1_PORT,EXINT1_PIN,INPUT);
	    DIO_SetPinPullup (EXINT1_PORT, EXINT1_PIN);
		SETBIT(SREG,IBIT);
		CLRBIT(MCUCR,2);
		SETBIT(MCUCR,3);
		SETBIT(GICR,GICR_INT1);

#elif CHECKMODE_INT1 == MODE_INT1_RE
	    DIO_SetPinDirection (EXINT1_PORT,EXINT1_PIN,INPUT);
		SETBIT(SREG,IBIT);
		SETBIT(MCUCR,2);
		SETBIT(MCUCR,3);
		SETBIT(GICR,GICR_INT1);
#endif

}

void EXINT2_Init (void)
{

#if  CHECKMODE_INT2 == MODE_INT2_FE

	    DIO_SetPinDirection (EXINT2_PORT,EXINT2_PIN,INPUT);
	    DIO_SetPinPullup (EXINT2_PORT, EXINT2_PIN);
		SETBIT(SREG,IBIT);
		CLRBIT(MCUCSR,6);
		SETBIT(GICR,GICR_INT2);

#elif CHECKMODE_INT2 == MODE_INT2_RE
	    DIO_SetPinDirection (EXINT2_PORT,EXINT2_PIN,INPUT);
		SETBIT(SREG,IBIT);
		SETBIT(MCUCSR,6);
		SETBIT(GICR,GICR_INT2);
#endif
}

void EXINT0_SetISR (void (*ptr) (void))
{
	Gptr0 = ptr;
}
void EXINT1_SetISR (void (*ptr) (void))
{
	Gptr1 = ptr;
}

void EXINT2_SetISR (void (*ptr) (void))
{
	Gptr2 = ptr;
}

ISR(INT0_vect)
{
	Gptr0();
}

ISR(INT1_vect)
{
	Gptr1();
}

ISR(INT2_vect)
{
	Gptr2();
}
