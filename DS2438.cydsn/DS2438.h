/**
 * \file DS2438.h
 * \brief DS2438 Library with 1-Wire interface. 
 *
 * This library allows to use the DS2438 device
 * on PSoC 3/5LP devices. The current implementation
 * only allows to have one single DS2438 in your system,
 * as all the functions perform a skip ROM command when
 * sending commands to the device. 
 *
*/

#ifndef __DS2438_H__
    #define __DS2438_H__
    
    #include "cytypes.h"
    #include "OneWire.h"
    #include "DS2438_Defs.h"
    
    /**
    *   \brief Initializes the DS2438.
    *
    *   This function starts the device by checking that
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
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
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
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
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
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
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
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
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
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
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
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
    */
    uint8_t DS2438_ReadRawVoltage(uint16_t* voltage, uint8_t crc_check);
    
    /**
    *   \brief Select input source for A/D conversion.
    *
    *   This function sets the input source for the A/D conversion of the DS2438.
    *   \param input_source selection of AD voltage source:
    *       - #DS2438_INPUT_VOLTAGE_VDD for battery input
    *       - #DS2438_INPUT_VAD for VAD pin
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAIL if CRC check failed when reading scratchpad.
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
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
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
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
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
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
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
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
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
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
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
    *   the sense resistor must be set in the #DS2348_SENSE_RESISTOR macro.
    *   \param current pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
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
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
    */
    uint8_t DS2438_GetRawCurrentData(uint16_t* current, uint8_t crc_check);
    
    /**
    *   \brief Read content of ICA register.
    *
    *   This function gets the current content of the ICA register,
    *   which is a 8-bit value representing the integration of the
    *   voltage across sense resistor over time..
    *   \param current pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
    */
    uint8_t DS2438_GetICA(uint8_t* ica, uint8_t crc_check);
    
    /**
    *   \brief Get remaining capacity of the battery.
    *
    *   This function converts the content of the ICA into
    *   remaining capacity according to the formula:
    *   \f$capacity = \dfrac{ICA}{2048\dotR_{sense}} \f$.
    *   \param capacity pointer to variable where voltage data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
    */
    uint8_t DS2438_GetCapacity(float* capacity, uint8_t crc_check);
    
    /**
    *   \brief Write threshold value for accumulator.
    *
    *   This function writes the new value to be used as a 
    *   threshold for the accumulator.
    *   If current conversion is enabled, it is temporarily
    *   disabled while writing the new threshold value.
    *   \param threshold the new threshold value to be written.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
    */
    uint8_t DS2438_WriteThreshold(uint8_t threshold);
    
    /**
    *   \brief Read threshold value for accumulator.
    *
    *   This function reads the current threshold value stored in
    *   the threshold register which is used to determine the
    *   functionality of the current accumlators.
    *   \param threshold pointer to variable where threshold data will be stored.
    *   \param crc_check #DS2438_CRC_CHECK to enable CRC check, #DS2438_NO_CRC_CHECK to disable CRC check
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    *   \retval #DS2438_CRC_FAIL if CRC check failed.
    */
    uint8_t DS2438_ReadThreshold(uint8_t* threshold, uint8_t crc_check);
    
    uint8_t DS2438_WriteOffset(int16_t offset);
    uint8_t DS2438_ReadOffset(uint8_t threshold);

    // ===========================================================
    //                  CONFIGURATION FUNCTIONS
    // ===========================================================
    
    /**
    *   \brief Enable current measurements and ICA.
    *
    *   If IAD is enabeld, current measurements will be taken at a rate
    *   of 36.41 Hz, and the results of the conversion can be retrieved
    *   using the #DS2438_GetCurrentData().
    *   \retval #DS2438_OK if no error was generated.
    *   \retval #DS2438_DEV_NOT_FOUND if no device was found on the bus.
    */
    uint8_t DS2438_EnableIAD(void);
    
    /**
    *   \brief Disable current measurements and ICA.
    *
    *   DIsable current conversion and ICA. No current conversion
    *   will be performed by the DS2438.
    *   \retval #DS2438_OK if no error was generated.
    *   \retval #DS2438_DEV_NOT_FOUND if no device was found on the bus.
    */
    uint8_t DS2438_DisableIAD(void);
    
    /**
    *   \brief Enable current accumulator.
    *
    *   If CA is enabled, bot charging current accumulator and discharging
    *   current accumulator are used. These registers store the total
    *   charging/discharging current the battery has encountered in
    *   its lifetime.
    *   \retval #DS2438_OK if no error was generated.
    *   \retval #DS2438_DEV_NOT_FOUND if no device was found on the bus.
    */
    uint8_t DS2438_EnableCA(void);
    
    /**
    *   \brief Disable current measurements and ICA.
    *
    *   Disable current conversion and ICA. No current conversion
    *   will be performed by the DS2438.
    *   \retval #DS2438_OK if no error was generated.
    *   \retval #DS2438_DEV_NOT_FOUND if no device was found on the bus.
    */
    uint8_t DS2438_DisableCA(void);
    
    /**
    *   \brief Enable shadow of data to EEPROM.
    *
    *   Enable shadow of CCA and DCA to EEPROM. When enabled, 
    *   CCA and DCA counters will be shadowed to EEPROM whenever
    *   their values change. This function has no effect it
    *   the CA are not enabled.
    *   \retval #DS2438_OK if no error was generated.
    *   \retval #DS2438_DEV_NOT_FOUND if no device was found on the bus.
    */
    uint8_t DS2438_EnableShadowEE(void);
    
    /**
    *   \brief Disable shadow of data to EEPROM.
    *
    *   Disable shadow of CCA and DCA to EEPROM. If battery
    *   becomes discharged, CCA/DCA data could be lost.
    *   \retval #DS2438_OK if no error was generated.
    *   \retval #DS2438_DEV_NOT_FOUND if no device was found on the bus.
    */
    uint8_t DS2438_DisableShadowEE(void);
    
    /**
    *   \brief Check if a copy from scratchpad to EEPROM is in progress.
    *
    *   This function checks whether a copy from scratchpad to
    *   EEPROM is currently in progress.
    *   \param copy set to 1 if copy in progress, 0 otherwise.
    *   \retval #DS2438_OK if no error was generated.
    *   \retval #DS2438_DEV_NOT_FOUND if no device was found on the bus.
    */
    uint8_t DS2438_CopyInProgress(uint8_t* copy);
    
    // ===========================================================
    //                  LOW LEVEL FUNCTIONS
    // ===========================================================
    
    /**
    *   \brief Read one page of data.
    *
    *   This function reads one page of data and return the read samples
    *   in the array passed in as parameter. This function issues a
    *   recall memory command, followed by a read scratchpage command
    *   and the page to be read.
    *   \param page_number the page to be read.
    *   \param page_data pointer to array where data will be stored.
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    */
    uint8_t DS2438_ReadPage(uint8_t page_number, uint8_t* page_data);
    
    /**
    *   \brief Write one page of data.
    *
    *   This function writes one page of data to the DS2438. This can be
    *   used to either configure bits in the registers or to write user bytes
    *   to the device in its EEPROM.
    *   \param page_number the page number to be written.
    *   \param page_data the data to be written to the page.
    *   \retval #DS2438_OK if device is present on the bus.
    *   \retval #DS2438_DEV_NOT_FOUND if device is not present on the bus.
    */
    uint8_t DS2438_WritePage(uint8_t page_number, uint8_t* page_data);
    
    /**
    *   \brief Compute CRC value based on Dallas specs.
    *
    *   This function computes the CRC value according to the
    *   specification of Dallas.
    *   \param data the data from which to compute the CRC value.
    *   \param len the length of the data.
    *   \return CRC value.
    */
    uint8_t DS2438_ComputeCrc(const uint8_t *data, uint8_t len);
    
    /**
    *   \brief Check if CRC value is equal to the expected one.
    *
    *   This function checks if the computed CRC value is equal
    *   to the expected one.
    *   \param data the data from which to compute the CRC value.
    *   \param len the length of the data.
    *   \param crc_value the expected CRC value.
    *   \retval #DS2438_OK if CRC is equal to the expected one.
    *   \retval #DS2438_CRC_FAIL if CRC is not equal to the expected one.
    */
    uint8_t DS2438_CheckCrcValue(uint8_t* data, uint8_t len, uint8_t crc_value);
    

#endif

/* [] END OF FILE */
