/**
 * \file DS2438_Commands.h
 * \brief Commands to be used in the 1-Wire communication with a DS2438.
 *
 * This header file defines all the commands that need to be
 * written over the 1-Wire interface to communicate with a DS2438 device.
 * [Here](https://datasheets.maximintegrated.com/en/ds/DS2438.pdf) you can find the datasheet of the component.
 *
*/
#ifndef __DS2438_COMMANDS_H__
    #define __DS2438_COMMANDS_H__
    
    #define DS2438_READ_ROM 0x33
    #define DS2438_SKIP_ROM 0xCC
    
    #define DS2438_VOLTAGE_CONV 0xB4
    #define DS2438_TEMP_CONV 0x44
    
    #define DS2438_RECALL_MEMORY 0xB8
    #define DS2438_READ_SCRATCHPAD 0xBE
#endif
    /* [] END OF FILE */
