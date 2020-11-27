/**
 * \file DS2438.h
 * \brief DS2438 Library with 1-Wire interface. 
 *
 * This library allows to use the DS2438 device
 * on PSoC 3/5LP devices. The current implementation
 * only allows to have one single DS2438 in your system,
 * as all the functions perform a skip ROM command when
 * sending commands to the device. 
 * ========================================
*/

#ifndef __DS2438_H__
    #define __DS2438_H__
    
    #include "cytypes.h"
    #include "OneWire.h"
    
    /**
    *   \brief Initializes the DS2438.
    *
    *   This function initializes the device by checking that
    *   the DS2438 is present on the 1-Wire bus.
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    */
    uint8_t DS2438_Init(void);
    
    /**
    *   \brief Check that the DS2438 is present on the bus.
    *
    *   This function checks that the DS2438 is present
    *   on the 1-Wire bus.
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    */
    uint8_t DS2438_DevIsPresent(void);
    
    // ===========================================================
    //                  64-BIT LASERED ROM FUNCTIONS
    // ===========================================================
    /**
    *   \brief Read 64-bit lasered ROM.
    *
    *   This function reads the 64-bit lasered ROM of the DS2438
    *   and returns its content in the array passed in as
    *   parameter to the function.
    *   \param rom pointer to array where raw ROM data will be saved.
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    */
    uint8_t DS2438_ReadRawRom(uint8_t* rom);
    
    /**
    *   \brief Read 64-bit lasered ROM.
    *
    *   This function reads the 64-bit lasered ROM of the DS2438
    *   and returns its content in the array passed in as
    *   parameter to the function.
    *   \param serial_number pointer to array where raw ROM data will be saved.
    *   \param #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_ReadSerialNumber(uint8_t* serial_number, uint8_t check);
    
    // ===========================================================
    //                  VOLTAGE CONVERSION FUNCTIONS
    // ===========================================================
    
    uint8_t DS2438_StartVoltageConversion(void);
    uint8_t DS2438_HasVoltageData(void);
    uint8_t DS2438_GetVoltageData(float* voltage);
    uint8_t DS2438_ReadVoltage(void);
    
    // ===========================================================
    //                  TEMPERATURE CONVERSION FUNCTIONS
    // ===========================================================
    
    uint8_t DS2438_StartTemperatureConversion(void);
    uint8_t DS2438_HasTemperatureData(void);
    uint8_t DS2438_GetTemperatureData(float* temperature);
    uint8_t DS2438_ReadTemperature(void);
    
    // ===========================================================
    //                  CONFIGURATION FUNCTIONS
    // ===========================================================
    uint8_t DS2438_EnableIAD(void);
    uint8_t DS2438_DisableIAD(void);
    
    uint8_t DS2438_EnableCA(void);
    uint8_t DS2438_DisableCA(void);
    
    // ===========================================================
    //              CURRENT AND ACCUMULATORS FUNCTIONS
    // ===========================================================
    uint8_t DS2438_GetCurrentData(float* current);

    // ===========================================================
    //                  LOW LEVEL UNCTIONS
    // ===========================================================
    uint8_t DS2438_ReadPage(uint8_t page_number, uint8_t* page_data);
    
#endif

/* [] END OF FILE */
