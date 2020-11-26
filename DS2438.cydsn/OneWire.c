/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "OneWire.h"

// Values of delays for 1-Wire communication protocol.

#define DELAY_A 6
#define DELAY_B 64
#define DELAY_C 60
#define DELAY_D 6
#define DELAY_E 9
#define DELAY_F 55
#define DELAY_G 0
#define DELAY_H 480
#define DELAY_I 70
#define DELAY_J 410

//-----------------------------------------------------------------------------
// Generate a 1-Wire reset, return 1 if no presence detect was found,
// return 0 otherwise.
int OneWire_TouchReset(unsigned int pin)
{
    int result;

    CyDelayUs(DELAY_G);
    CyPins_ClearPin(pin); // Drives DQ low
    CyDelayUs(DELAY_H);
    CyPins_SetPin(pin); // Releases the bus
    CyDelayUs(DELAY_I);
    result =  CyPins_ReadPin(pin) > 0 ? 1 : 0; // Sample for presence pulse from slave
    CyDelayUs(DELAY_J); // Complete the reset sequence recovery
    return result; // Return sample presence pulse result
}

//-----------------------------------------------------------------------------
// Send a 1-Wire write bit. Provide 10us recovery time.
//
void OneWire_WriteBit(unsigned int pin, int bit)
{
    if (bit)
    {
        // Write '1' bit
        CyPins_ClearPin(pin); // Drives DQ low
        CyDelayUs(DELAY_A);
        CyPins_SetPin(pin); // Releases the bus
        CyDelayUs(DELAY_B); // Complete the time slot and 10us recovery
    }
    else
    {
        // Write '0' bit
        CyPins_ClearPin(pin); // Drives DQ low
        CyDelayUs(DELAY_C);
        CyPins_SetPin(pin); // Releases the bus
        CyDelayUs(DELAY_D);
    }
}

//-----------------------------------------------------------------------------
// Read a bit from the 1-Wire bus and return it. Provide 10us recovery time.
//
int OneWire_ReadBit(unsigned int pin)
{
    int result;

    CyPins_ClearPin(pin); // Drives DQ low
    CyDelayUs(DELAY_A); // A
    CyPins_SetPin(pin); // Releases the bus
    //OneWire_TickDelay(9); // E
    CyDelayUs(DELAY_E);
    result =  (CyPins_ReadPin(pin)>0) ? 0x01 : 0x00; // Sample the bit value from the slave
    CyDelayUs(DELAY_F); // Complete the time slot and 10us recovery // F

    return result;
}

//-----------------------------------------------------------------------------
// Write 1-Wire data byte
//
void OneWire_WriteByte(unsigned int pin, int data)
{
    int loop;

    // Loop to write each bit in the byte, LS-bit first
    for (loop = 0; loop < 8; loop++)
    {
        OneWire_WriteBit(pin, data & 0x01);

        // shift the data byte for the next bit
        data >>= 1;
    }
    
}

//-----------------------------------------------------------------------------
// Read 1-Wire data byte and return it
//
int OneWire_ReadByte(unsigned int pin)
{
    
    int loop, result=0;

    for (loop = 0; loop < 8; loop++)
    {
        // shift the result to get it ready for the next bit
        result >>= 1;

        // if result is one, then set MS bit
        if (OneWire_ReadBit(pin))
            result |= 0x80;
    }
    return result;
}

//-----------------------------------------------------------------------------
// Write a 1-Wire data byte and return the sampled result.
//
int OneWire_TouchByte(unsigned int pin, int data)
{
    int loop, result=0;

    for (loop = 0; loop < 8; loop++)
    {
        // shift the result to get it ready for the next bit
        result >>= 1;

        // If sending a '1' then read a bit else write a '0'
        if (data & 0x01)
        {
            if (OneWire_ReadBit(pin))
                    result |= 0x80;
        }
        else
            OneWire_WriteBit(pin, 0);

        // shift the data byte for the next bit
        data >>= 1;
    }
    return result;
}

//-----------------------------------------------------------------------------
// Write a block 1-Wire data bytes and return the sampled result in the same
// buffer.
//
void OneWire_Block(unsigned int pin, unsigned char *data, int data_len)
{
    int loop;

    for (loop = 0; loop < data_len; loop++)
    {
        data[loop] = OneWire_TouchByte(pin, data[loop]);
    }
}



/* [] END OF FILE */
