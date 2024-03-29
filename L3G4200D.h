﻿/*
 * L3G4200D.h
 *
 * Created: 24/09/2015 09:13:19 م
 *  Author: hossam
 */ 


#ifndef L3G4200D_H_
#define L3G4200D_H_

#include "Basic_Types.h"
/*Wakeup States*/
#define u8WAKEUP_DN 0x00U
#define u8WAKEUP_IN_PROGRESS 0x01U
#define u8WAKEUP_FAILED 0x02U

/*Reading Status*/
#define u8READING_OK       0x00U
#define u8DATA_OVERWRITTEN 0x01U
#define u8AXIS_DISABLED    0x02U
#define u8NO_DATA_UPDATED  0x03U

/*Init Service*/
u8 GYHD_Init(void);

/*Power MAnagement Services*/
void GYHD_WakeUpModule(u8* u8WakeUpStatePtr);
void GYHD_SleepModule(void);
/*function to use in place of macros*/
void L3G4200D_Reg_Write(u8 add, u8 data);
void L3G4200D_Reg_Read(u8 address, u8* data_ptr);
/*Data Read*/
u8 GYHD_ReadXDirection(u16* pu16Data,u8* pu8ReadingStatus);
u8 GYHD_ReadYDirection(u16* pu16Data,u8* pu8ReadingStatus);
u8 GYHD_ReadZDirection(u16* pu16Data,u8* pu8ReadingStatus);
void _delay_ms(u16 delay);

#endif /* L3G4200D_H_ */
