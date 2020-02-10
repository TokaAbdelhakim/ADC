/*
 * EXINT_Cfg.h
 *
 *  Created on: 14 Sep 2019
 *      Author: Kimo Store
 */

#ifndef EXINT_CFG_H_
#define EXINT_CFG_H_

//check mode INT0
#define MODE_INT0_LL 0
#define MODE_INT0_AC 1
#define MODE_INT0_FE 2
#define MODE_INT0_RE 3

//check mode INT1
#define MODE_INT1_LL 0
#define MODE_INT1_AC 1
#define MODE_INT1_FE 2
#define MODE_INT1_RE 3

//check mode INT2
#define MODE_INT2_FE 0
#define MODE_INT2_RE 1

#define CHECKMODE_INT0 MODE_INT0_FE
#define CHECKMODE_INT1 MODE_INT1_LL
#define CHECKMODE_INT2 MODE_INT2_RE

#endif /* EXINT_CFG_H_ */
