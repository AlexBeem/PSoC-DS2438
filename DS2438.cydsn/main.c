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
#include "DS2438.h"
#include "stdio.h"

#define DEBUG

#ifdef DEBUG

    #define DEBUG_TEST 1             
    
#else
    
    #define DEBUG_TEST 0
    
#endif

#define debug_print(fmt) do { if (DEBUG_TEST) UART_PutString(fmt); } while (0)

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_Start();
    debug_print("DS2438 Test\r\n");

    char msg[50];
    DS2438_Init();
    
    if (DS2438_DevIsPresent() == DS2438_OK)
    {
        debug_print("Device is present\r\n");
        
        uint8_t rom[8];
        if (DS2438_OK == DS2438_ReadRawRom(rom))
        {
            sprintf(msg, "0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\r\n", rom[0], rom[1],
                                                                                    rom[2], rom[3],
                                                                                    rom[4], rom[5],
                                                                                    rom[6], rom[7]);
            debug_print(msg);
            uint8_t serial_number[6];
            DS2438_ReadSerialNumber(serial_number, DS2438_NO_CRC_CHECK);
            sprintf(msg, "0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\r\n", serial_number[0], serial_number[1],
                                                                                    serial_number[2], serial_number[3],
                                                                                    serial_number[4], serial_number[5]);
            debug_print(msg);
        }
        else
        {
            debug_print("Could not read rom in raw mode\r\n");
        }
    }
    else
    {
        debug_print("Could not find device\r\n");
    }
    
    DS2438_StartTemperatureConversion();
    CyDelay(100);
    for (uint8_t page = 0; page < 8; page++)
    {
        uint8_t page_data[9];
        if( DS2438_ReadPage(page, page_data) == DS2438_OK )
        {
            sprintf(msg, "Read page %d\r\n", page);
            debug_print(msg);
            sprintf(msg, "0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\r\n", page_data[0],
                                                                                                page_data[1],
                                                                                                page_data[2],
                                                                                                page_data[3],
                                                                                                page_data[4],
                                                                                                page_data[5],
                                                                                                page_data[6],
                                                                                                page_data[7],
                                                                                                page_data[8]);
            debug_print(msg);
        }
        else
        {
            debug_print("Could not read page data\r\n");
        }
        
    }
    for(;;)
    {
        /* Place your application code here. */
        if (DS2438_StartTemperatureConversion() == DS2438_OK)
        {
            debug_print("Started temperature conversion\r\n");
            while(DS2438_HasTemperatureData() != DS2438_OK);
            debug_print("Temperature data available\r\n");
            float temperature;
            if (DS2438_GetTemperatureData(&temperature) == DS2438_OK)
            {
                sprintf(msg, "Temp: %d\r\n", (int)(temperature*1000));
                debug_print(msg);
            }
            else
            {
                debug_print("Could not read temperature data\r\n");
            }
        }
        else
        {
            debug_print("Could not start temperature conversion\r\n");
        }
        CyDelay(1000);
        if (DS2438_StartVoltageConversion() == DS2438_OK)
        {
            debug_print("Started voltage conversion\r\n");
            while(DS2438_HasVoltageData() != DS2438_OK);
            debug_print("Voltage data available\r\n");
            float voltage;
            if (DS2438_GetVoltageData(&voltage) == DS2438_OK)
            {
                sprintf(msg, "Volt: %d\r\n", (int)(voltage*1000));
                debug_print(msg);
            }
            else
            {
                debug_print("Could not read voltage data\r\n");
            }
        }
        else
        {
            debug_print("Could not start voltage conversion\r\n");
        }
        CyDelay(1000);
        float current;
        if (DS2438_GetCurrentData(&current) == DS2438_OK)
        {
            debug_print("Current data available\r\n");
            sprintf(msg, "mAmps: %d\r\n", (int)(current*1000));
            debug_print(msg);
            
        }
        else
        {
            debug_print("Could not start voltage conversion\r\n");
        }
        CyDelay(1000);
        
    }
}


/* [] END OF FILE */
