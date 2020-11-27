/**
 *  \file DS2438_Defines.h
 *  \brief Defines and commands for the DS2438 Library.
 *
 * This header file defines all the commands that need to be
 * written over the 1-Wire interface to communicate with a DS2438 device.
 * It also defines the errors returned by the DS2438 functions.
 * [Here](https://datasheets.maximintegrated.com/en/ds/DS2438.pdf) you can find the datasheet of the component.
 *
*/
#ifndef __DS2438_DEFINES_H__
    #define __DS2438_DEFINES_H__
    
    // ===========================================================
    //                   CRC ENABLE/DISABLE MACROS
    // ===========================================================
    
    /**
    *   \brief Enable CRC check when reading from scratchpad.
    */
    #define DS2438_CRC_CHECK        0       ///< Perform CRC Check
    
    /**
    *   \brief Disbale CRC check when reading from scratchpad.
    */
    #define DS2438_NO_CRC_CHECK     1       ///< Skip CRC Check

    // ===========================================================
    //                      ERROR CODES
    // ===========================================================
    
    /**
    *   \brief No error generated.
    */
    #define DS2438_OK               0       
    
    /**
    *   \brief Device was not found on the 1-Wire interface.
    */
    #define DS2438_DEV_NOT_FOUND    1       
    
    /**
    *   \brief CRC Check failed.
    */
    #define DS2438_CRC_FAIL         2       
    
    /**
    *   \brief Generic error.
    */
    #define DS2438_ERROR            3      
    
    /**
    *   \brief Bad parameter error.
    */
    #define DS2438_BAD_PARAM        4

    // ===========================================================
    //                      1-WIRE COMMANDS
    // ===========================================================
    
    /**
    *   \brief Command to read 64-bit lasered ROM.
    */
    #define DS2438_READ_ROM 0x33
    
    /**
    *   \brief Command to skip ROM match/search.
    *
    *   This command is used because the current implementation
    *   assumes only a DS2438 is present on the system.
    */
    #define DS2438_SKIP_ROM 0xCC
   
    /**
    *   \brief Command to trigger voltage conversion.
    */
    #define DS2438_VOLTAGE_CONV 0xB4
    
    /**
    *   \brief Command to trigger temperature conversion.
    */
    #define DS2438_TEMP_CONV 0x44
    
    /**
    *   \brief Command to perform memory recall from EEPROM.
    */
    #define DS2438_RECALL_MEMORY 0xB8
    
    /**
    *   \brief Command to read scratchpad. 
    */
    #define DS2438_READ_SCRATCHPAD 0xBE
    
    /**
    *   \brief Command to write scratchpad. 
    */
    #define DS2438_WRITE_SCRATCHPAD 0x4E
    
    /**
    *   \brief Command to copy scratchpad. 
    */
    #define DS2438_COPY_SCRATCHPAD 0x48
    
    // ===========================================================
    //                      SENSE RESISTOR
    // ===========================================================
    
    /**
    *   \brief Value of sense resistor to be used for current computation.
    */
    #define DS2438_SENSE_RESISTOR 0.05
    
    // ===========================================================
    //                      VOLTAGE A/D INPUT SELECTION
    // ===========================================================
    
    /**
    *   \brief Select battery voltage (VDD) as A/D input source. 
    */
    #define DS2438_INPUT_VOLTAGE_VDD 0
    
    /**
    *   \brief Select general purpose input as A/D input source. 
    */
    #define DS2438_INPUT_VOLTAGE_VAD 1
    
#endif
/* [] END OF FILE */
