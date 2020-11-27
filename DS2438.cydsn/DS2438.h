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
    #include "DS2438_Defines.h"
    
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
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    */
    uint8_t DS2438_ReadRawRom(uint8_t* rom, uint8_t crc_check);
    
    /**
    *   \brief Read 48-bit Serial Number from ROM.
    *
    *   This function reads the 64-bit lasered ROM of the DS2438
    *   and returns the serial number contained in it 
    *   in the array passed in as parameter to the function.
    *   \param serial_number pointer to array where raw ROM data will be saved.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_ReadSerialNumber(uint8_t* serial_number, uint8_t crc_check);
    
    // ===========================================================
    //                  VOLTAGE CONVERSION FUNCTIONS
    // ===========================================================
    
    /**
    *   \brief Start voltage conversion.
    *
    *   This function starts a voltage conversion by sending the
    *   appropriate command to the DS2438.
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    */
    uint8_t DS2438_StartVoltageConversion(void);
    
    /**
    *   \brief Check if voltage conversion completed.
    *
    *   This function checks if a voltage conversion has been completed
    *   by reading the appropriate bit in the Status/Configuration register.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_HasVoltageData(uint8_t crc_check);
    
    /**
    *   \brief Get voltage data.
    *
    *   This function gets the voltage data from the DS2438.
    *   \param voltage pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_GetVoltageData(float* voltage, uint8_t crc_check);
    
    /**
    *   \brief Get voltage data in raw format.
    *
    *   This function gets the voltage data from the DS2438 in raw 
    *   format. Conversion must be performed later.
    *   \param voltage pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_GetRawVoltageData(uint16_t* voltage, uint8_t crc_check);
    
    /**
    *   \brief Read voltage data.
    *
    *   This function is a blocking function that starts a voltage conversion,
    *   wait until new voltage data are available, and gets the voltage data from 
    *   the DS2438 converting it in float format.
    *   \param voltage pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_ReadVoltage(float* voltage, uint8_t crc_check);
    
    /**
    *   \brief Read raw voltage data.
    *
    *   This function is a blocking function that starts a voltage conversion,
    *   wait until new voltage data are available, and gets the voltage data from 
    *   the DS2438 in raw format. Conversion must be performed later.
    *   \param voltage pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_ReadRawVoltage(uint16_t* voltage, uint8_t crc_check);
    
    /**
    *   \brief Select input source for A/D conversion.
    *
    *   This function sets the input source for the A/D conversion of the DS2438.
    *   \param input_source #DS2438_INPUT_VDD for battery input, #DS2438_INPUT_VAD for VAD pin.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed when reading scratchpad.
    */
    uint8_t DS2438_SelectInputSource(uint8_t input_source, uint8_t crc_check);
    
    // ===========================================================
    //                  TEMPERATURE CONVERSION FUNCTIONS
    // ===========================================================
    
    /**
    *   \brief Start temperature conversion.
    *
    *   This function starts a new temperature conversion.
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    */
    uint8_t DS2438_StartTemperatureConversion(void);
    
    /**
    *   \brief Check if temperature conversion is complete. 
    *
    *   This function checks if temperature conversion is complete
    *   by reading the appropriate bit in the Status/Configuration register.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_HasTemperatureData(uint8_t crc_check);
    
    /**
    *   \brief Get temperature data in float format.
    *
    *   This function is gets the temperature data from the DS2438 in float format.
    *   It is a non-blocking function since it does not wait for the 
    *   completion of the conversion, that must be started prior to calling this function.
    *   \param temperature pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_GetTemperatureData(float* temperature, uint8_t crc_check);
    
    /**
    *   \brief Get temperature data in raw format.
    *
    *   This function is gets the temperature data from the DS2438 in raw format.
    *   It is a non-blocking function since it does not wait for the 
    *   completion of the conversion, that must be started prior to calling this function.
    *   \param temperature pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_GetRawTemperatureData(uint16_t* temperature, uint8_t crc_check);
    
    /**
    *   \brief Read temperature data in float format.
    *
    *   This function is a blocking function that starts a temperature conversion,
    *   wait until new temperature data are available, and gets the temperature data from 
    *   the DS2438 in float format.
    *   \param temperature pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_ReadTemperature(float* temperature, uint8_t crc_check);
    
    /**
    *   \brief Read raw temperature data.
    *
    *   This function is a blocking function that starts a temperature conversion,
    *   wait until new temperature data are available, and gets the temperature data from 
    *   the DS2438 in raw format. Conversion must be performed later.
    *   \param temperature pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_ReadRawTemperature(uint16_t* temperature, uint8_t crc_check);
        
    // ===========================================================
    //              CURRENT AND ACCUMULATORS FUNCTIONS
    // ===========================================================
    
    /**
    *   \brief Read current data in float format.
    *
    *   This function gets the current data in float format. A positive current
    *   means that the battery is being charged, while a negative current
    *   means that current is flowing out of the battery. In order to correctly
    *   convert the current value from raw to float format, the true value of
    *   the sense resistor must be set in the #DS2347_SENSE_RESISTOR macro.
    *   \param current pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_GetCurrentData(float* current, uint8_t crc_check);
    
    /**
    *   \brief Read current data in raw format.
    *
    *   This function gets the current data in raw format. No conversion is
    *   performed in this function, therefore this must be later done by the
    *   user using the appropriate value of sense resistor.
    *   \param current pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAILED if CRC check failed.
    */
    uint8_t DS2438_GetRawCurrentData(float* current, uint8_t crc_check);

    // ===========================================================
    //                  CONFIGURATION FUNCTIONS
    // ===========================================================
    uint8_t DS2438_EnableIAD(void);
    uint8_t DS2438_DisableIAD(void);
    
    uint8_t DS2438_EnableCA(void);
    uint8_t DS2438_DisableCA(void);
    
    // ===========================================================
    //                  LOW LEVEL UNCTIONS
    // ===========================================================
    uint8_t DS2438_ReadPage(uint8_t page_number, uint8_t* page_data);
    uint8_t DS2438_WritePage(uint8_t page_number, uint8_t* page_data);
    
    uint8_t DS2438_ComputeCrc(const uint8_t *data, uint8_t len);
    uint8_t DS2438_CheckCrcValue(uint8_t* data, uint8_t len, uint8_t crc_value);

#endif

/* [] END OF FILE */
