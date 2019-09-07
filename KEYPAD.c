/*
 * KEYPAD.c
 *
 * Created: 30/01/2016 06:38:37 م
 *  Author: hossam
 */ 
#include "DIO.h"
#include "KEYPAD.h"
/*Local Symbols*/
#define KPD_COL_PORT 0x80U
#define KPD_ROW_PORT 0X90U
#define KPD_COL_MASK 0x70U
#define KPD_ROW_MASK 0x0fU
#define KPD_COL_PIN_NUM 4U
#define KPD_ROW_PIN_NUM 0U
/**************************************************/
void KPD_Init(void)
{
    DIO_vidWritePortDirection(KPD_COL_PORT,KPD_COL_MASK,0x00U);
    DIO_vidWritePortDirection(KPD_ROW_PORT,KPD_ROW_MASK,0xffU);
    DIO_vidWritePortData(KPD_ROW_PORT,KPD_ROW_MASK,0x00U);
}

void DIO_vidReadPortData(u8 col_port, u8 col_mask, u8* value_ptr)
{
    *(value_ptr) = (*(value_ptr)) >> KPD_COL_PIN_NUM;
}


 /*#define KPD_ROW_WRITE(DATA) DIO_vidWritePortData(KPD_ROW_PORT,KPD_ROW_MASK,((DATA) << KPD_ROW_PIN_NUM))*/

void KPD_ReadVal(unsigned char* ValuePtr)
{
    static const unsigned char KeysLut[]= {'1' , '2' , '3' , '4' , '5' , '6','7' , '8' , '9','*' , '0' , '#'};
    unsigned char Rowdata;
    unsigned char ColData;
    unsigned char LoopTermnate = 0U;
    unsigned char value1;
    for(Rowdata = 0U ; (Rowdata < 4U) && (LoopTermnate == 0U) ; Rowdata ++)
    {
        value1 = ((u8)1u<<Rowdata);
        DIO_vidWritePortData(KPD_ROW_PORT, KPD_ROW_MASK, value1);
        DIO_vidReadPortData(KPD_COL_PORT, KPD_COL_MASK, &ColData);


        if(ColData != 0U)
        {
            *ValuePtr = KeysLut[(Rowdata*3U) + (ColData/2U)];
            LoopTermnate = 1U;
        }
        else
        {
            *ValuePtr = (u8)'n';
        }
    }



}

