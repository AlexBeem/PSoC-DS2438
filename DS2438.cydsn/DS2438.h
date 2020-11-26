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
    
    typedef enum {
        DS2438_OK,
        DS2438_DEV_NOT_FOUND,
        DS2438_CRC_FAIL,
        DS2438_ERROR
    } DS2438_ErrorCode;
    
    typedef enum {
        DS2438_CRC_CHECK,
        DS2438_NO_CRC_CHECK
    } DS2438_CrcCheck;
    
    /**
    *   \brief Initializes the DS2438
    */
    DS2438_ErrorCode DS2438_Init(void);
    DS2438_ErrorCode DS2438_DevIsPresent(void);
    DS2438_ErrorCode DS2438_ReadRawRom(uint8_t* rom);
    DS2438_ErrorCode DS2438_ReadSerialNumber(uint8_t* serial_number, DS2438_CrcCheck check);
    
    DS2438_ErrorCode DS2438_StartVoltageConversion(void);
    DS2438_ErrorCode DS2438_HasVoltageData(void);
    DS2438_ErrorCode DS2438_GetVoltageData(float* voltage);
    DS2438_ErrorCode DS2438_ReadVoltage(void);
    
    DS2438_ErrorCode DS2438_StartTemperatureConversion(void);
    DS2438_ErrorCode DS2438_HasTemperatureData(void);
    DS2438_ErrorCode DS2438_GetTemperatureData(float* temperature);
    DS2438_ErrorCode DS2438_ReadTemperature(void);
    
    DS2438_ErrorCode DS2438_ReadPage(uint8_t page_number, uint8_t* page_data);
    
#endif

/* [] END OF FILE */
