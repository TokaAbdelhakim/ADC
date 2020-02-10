/*
 * EXINT.h
 *
 *  Created on: 14 Sep 2019
 *      Author: Kimo Store
 */

#ifndef EXINT_H_
#define EXINT_H_

#define EXINT0_PORT PORT3
#define EXINT1_PORT PORT3
#define EXINT2_PORT PORT1

#define EXINT0_PIN PIN2
#define EXINT1_PIN PIN3
#define EXINT2_PIN PIN2

//EX INT ENABLE
#define IBIT 7

//INTX ENABLE
#define GICR_INT0 6
#define GICR_INT1 7
#define GICR_INT2 5



void EXINT0_Init (void);
void EXINT1_Init (void);
void EXINT2_Init (void);

void EXINT0_SetISR (void (*ptr) (void));
void EXINT1_SetISR (void (*ptr) (void));
void EXINT2_SetISR (void (*ptr) (void));


#endif /* EXINT_H_ */
