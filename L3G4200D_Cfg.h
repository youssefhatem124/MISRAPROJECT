/*
 * L3G4200D_Cfg.h
 *
 * Created: 24/09/2015 09:13:50 م
 *  Author: hossam
 */ 


#ifndef L3G4200D_CFG_H_
#define L3G4200D_CFG_H_
#include "Basic_Types.h"
#include "DIO.h"
#include "SPI.h"
#define ON (1U)
/*SPI Communication Configuration
 DIO_InitPortDirection(PB,1<<4,1<<4);
   DIO_WritePort(PB,1<<4,1<<4)*/
void GYHD_Init_Slave_Select(void);
void GYHD_Activate_Slave_Select(void);
void GYHD_DEActivate_Slave_Select(void);
/*DIO_WritePort(PB,~(1<<4),1<<4)
DIO_WritePort(PB,(1<<4),(1<<4))*/
/*Timeout Management Configuration*/
#define u8USE_DELAY 0x00
#define u8USE_TIMER 0x01

#define u8TIMEOUT_FUNCTION  0x00U

#if(u8TIMEOUT_FUNCTION == 0x00U)


/*#define u8START_TIME_OUT_MS(DELAY_MS,FLAG_PTR) _delay_ms(DELAY_MS);\
                                              *(FLAG_PTR) = 0x01*/
void u8START_Time_Out_MS(u16 delay, u8* flag_ptr);
#else
#define u8START_TIME_OUT_MS(DELAY_MS,FLAG_PTR)
#endif

/*Self Axis Movement Detection Config*/
#define u8SELF_AXIS_MOV  (ON)


#endif /* L3G4200D_CFG_H_ */
