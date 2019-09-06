/*
 * BLMGR_CFG.c
 *
 * Created: 28/02/2016 06:54:45 م
 *  Author: hossam
 */ 
#include "DIO.h"
#include "BLMGR_CFG.h"
BLMGR_DioPinConfig BuzzerConfig      = {PC,(u8)1<<4};
BLMGR_DioPinConfig BlueToothPwrConfig = {PC,(u8)1<<5};
BLMGR_DioPinConfig BluetoothKeyConfig = {PD,(u8)1<<2};
	
