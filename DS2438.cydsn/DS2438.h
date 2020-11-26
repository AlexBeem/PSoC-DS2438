/* ========================================
 *
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
    *   \brief Error codes returned by DS2438 functions.
    */
    typedef enum {
        DS2438_OK,              ///<  No error generated
        DS2438_DEV_NOT_FOUND,   ///<  Device not found on the 1-Wire bus
        DS2438_CRC_FAIL,        ///<  CRC Check Failed
        DS2438_ERROR            ///<  Generic error
    } DS2438_ErrorCode;
    
    /**
    *   \brief Flags to enable/disable CRC checks.
    */
    typedef enum {
        DS2438_CRC_CHECK,       ///< Perform CRC Check
        DS2438_NO_CRC_CHECK     ///< Skip CRC Check
    } DS2438_CrcCheck;
    
    /**
    *   \brief Initializes the DS2438.
    *
    *   This function initializes the device by checking that
    *   the DS2438 is present on the 1-Wire bus.
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    */
    DS2438_ErrorCode DS2438_Init(void);
    
    /**
    *   \brief Check that the DS2438 is present on the bus.
    *
    *   This function checks that the DS2438 is present
    *   on the 1-Wire bus.
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    */
    DS2438_ErrorCode DS2438_DevIsPresent(void);
    
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
    DS2438_ErrorCode DS2438_ReadRawRom(uint8_t* rom);
    
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
    DS2438_ErrorCode DS2438_ReadSerialNumber(uint8_t* serial_number, DS2438_CrcCheck check);
    
    DS2438_ErrorCode DS2438_StartVoltageConversion(void);
    DS2438_ErrorCode DS2438_HasVoltageData(void);
    DS2438_ErrorCode DS2438_GetVoltageData(float* voltage);
    DS2438_ErrorCode DS2438_ReadVoltage(void);
    
    DS2438_ErrorCode DS2438_StartTemperatureConversion(void);
    DS2438_ErrorCode DS2438_HasTemperatureData(void);
    DS2438_ErrorCode DS2438_GetTemperatureData(float* temperature);
    DS2438_ErrorCode DS2438_ReadTemperature(void);
    
    DS2438_ErrorCode DS2438_EnableIAD(void);
    DS2438_ErrorCode DS2438_DisableIAD(void);
    
    DS2438_ErrorCode DS2438_EnableCA(void);
    DS2438_ErrorCode DS2438_DisableCA(void);
    
    DS2438_ErrorCode DS2438_GetCurrentData(float* current);

    DS2438_ErrorCode DS2438_ReadPage(uint8_t page_number, uint8_t* page_data);
    
#endif

/* [] END OF FILE */
