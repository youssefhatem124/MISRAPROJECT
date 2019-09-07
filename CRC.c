#include "Basic_Types.h"
#include"CRC.h"
/***************************************************************************************/
static u32 GetPower(u32 Base,u32 Pow);
static u16 gen_crc16(const u8 *data, u16 size, u32 CRC16);
/***************************************************************************************/
void SECR_CrcPolynomialGenerate(u32* PolynomialPtr,u8 CrcLengthInBits)
{
    u32 DevisorValue;
    DevisorValue = (u32)(GetPower(2U,(u32)CrcLengthInBits)) - 1U;
    *PolynomialPtr = (rand_() % DevisorValue) +0x10000U ;
}
/***************************************************************************************/
void SECR_GnerateCrc(const u8 PayloadPtr[], u16 PayloadLength, u16* CrcPtr, u32 CrcPoly)
{
    u16 LoopIndex;
    static u8 InternalBuffer[8];
    /*Copying data to internal buffer*/
    for (LoopIndex = 0U; LoopIndex < (u16)PayloadLength; LoopIndex ++)
    {
        InternalBuffer[LoopIndex] = PayloadPtr[LoopIndex];
    }
    /*perform bit wise invert on the data*/
    for (LoopIndex = 0U; LoopIndex < (u16)PayloadLength; LoopIndex ++)
    {
        InternalBuffer[LoopIndex]  ^= 0xffU;
    }
    /*Generate CRC*/
    *CrcPtr = gen_crc16(InternalBuffer,PayloadLength*8U,0x18005U);
}
/***************************************************************************************/
static u32 GetPower(u32 Base,u32 Pow)
{
    u32 result = 1u;
    u32 LoopIndex1;
    for (LoopIndex1 = 0U; LoopIndex1 < (u32)Pow; LoopIndex1 ++)
    {
        result *= Base;
    }
    return result;
}
/***************************************************************************************/
static u16 gen_crc16(const u8 *data, u16 size, u32 CRC16)
{
    u16 out = 0;
    u16 bits_read = 0, bit_flag;
    u16 i;
    u16 crc = 0;
    u16 j = 0x0001;
    u16 result1;
    /* Sanity check: */
    if(data == 0U)
    {
       result1=0u;
    }
    else
    {

    }
    {
        while(size > 0U)
        {
            bit_flag = out >> 15U;

            /* Get next bit: */
            out <<= 1;
            out |= ((*data >> bits_read) & (1U)); /* item a) work from the least significant bits*/

            /* Increment bit counter: */
            bits_read++;
            if(bits_read > 7U)
            {
                bits_read = 0U;
                /*data++;*/
                size--;
            }

            /* Cycle check: */
            if(bit_flag)
            {
                out ^= CRC16;

            }
            else
            {

            }

        }

        /* item b) "push out" the last 16 bits*/

        for (i = 0U; i < 16U; ++i) {
            bit_flag = out >> 15u;
            out <<= 1u;
            if(bit_flag)
            {
                out ^= CRC16;

            }
        }

        /* item c) reverse the bits*/

        i = 0x8000U;

            if (i & out)
            {
                crc |= j;
                result1=crc;
            }
        }

        return result1;
    }
    /***************************************************************************************/
