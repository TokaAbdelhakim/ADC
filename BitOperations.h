/*
 * BitOperations.h
 *
 *  Created on: 31 Aug 2019
 *      Author: Kimo Store
 */

#ifndef BITOPERATIONS_H_
#define BITOPERATIONS_H_

#define SETBIT(X,BIT_NUM) (unsigned char)((X)=((X)|(1<<(BIT_NUM))))

#define CLRBIT(X,BIT_NUM) (unsigned char)((X)=((X)&(~(1<<(BIT_NUM)))))

#define GETBIT(X,BIT_NUM) (unsigned char)(((X)>>(BIT_NUM))&(1))

#define TOGGLEBIT(X,BIT_NUM) (unsigned char)((X)^=(((unsigned char)(1))<<(BIT_NUM)))


#endif
