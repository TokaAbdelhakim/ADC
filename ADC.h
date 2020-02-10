/*
 * ADC.h
 *
 *  Created on: 5 Oct 2019
 *      Author: Kimo Store
 */

#ifndef ADC_H_
#define ADC_H_

//v reference
#define AREF 0
#define AVCC 1
#define INTERNAL 2
#define REF_VOLTAGE AVCC

 //conversion modes
#define SINGLE 0
#define AUTO_FREERUNNING 1
#define AUTO_EXTERNALINTERUPT 2
#define MODE AUTO_EXTERNALINTERUPT

//8 for 1M clock, 128 for 16M clock
#define PRESCALER 128

// 10 or 8 bits
#define RESOLUTION 10

//adjustment
#define RIGHT_ADJUST 0
#define LEFT_ADJUST 1
#define ADJUSTMENT RIGHT_ADJUST

void ADC_Init (void);

// channels from 0 to 7
#if RESOLUTION == 8
U8 ADC_Read (U8 channel);
#elif RESOLUTION == 10
U16 ADC_Read (U8 channel);
void Set_ADC_value (void);
U16 Get_ADC_value (void);
void Calculate_ADC_value(void);
#endif
#endif /* ADC_H_ */
