/*
 * DIO.h
 *
 *  Created on: 31 Aug 2019
 *      Author: Kimo Store
 */

#ifndef DIO_H_
#define DIO_H_

#define PORT0 0
#define PORT1 1
#define PORT2 2
#define PORT3 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0
/*
#define NUM0 0x3F
#define NUM1 0x06
#define NUM2 0x5B
#define NUM3 0x4F
#define NUM4 0x66
#define NUM5 0x6D
#define NUM6 0x7C
#define NUM7 0x07
#define NUM8 0x7F
#define NUM9 0x5F*/

/*
Port_number :PORT0,PORT1,PORT2,PORT3
pin_number  :PIN0 ->> PIN7
Direction   : INPUT,OUTPUT
*/
void DIO_SetPinDirection (U8 Port_number, U8 Pin_number, U8 Direction);
/*
Port_number :PORT0,PORT1,PORT2,PORT3
pin_number  :PIN0 ->> PIN7
*/
void DIO_SetPinPullup (U8 Port_number, U8 Pin_number);
/*
Port_number :PORT0,PORT1,PORT2,PORT3
pin_number  :PIN0 ->> PIN7
value   : LOW,HIGH
*/
void DIO_SetPinValue (U8 Port_number, U8 Pin_number, U8 Value);
/*
Port_number :PORT0,PORT1,PORT2,PORT3
pin_number  :PIN0 ->> PIN7
*/
U8 DIO_GetPinValue (U8 Port_number, U8 Pin_number);
/*
Port_number :PORT0,PORT1,PORT2,PORT3
port_value  :2bytes
 */

void DIO_SetPortValue (U8 Port_number, U8 port_Value);


/*
Port_number :PORT0,PORT1,PORT2,PORT3
Direction   : INPUT,OUTPUT
*/
void DIO_SetPortDirection (U8 Port_number, U8 Direction);

#endif  /*DIO_H_*/
