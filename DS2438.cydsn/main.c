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
    DS2438_EnableIAD();
    DS2438_EnableCA();
    DS2438_EnableShadowEE();
    
    if (DS2438_DevIsPresent() == DS2438_OK)
    {
        uint8_t serial_number[6];
        if ( DS2438_ReadSerialNumber(serial_number, DS2438_CRC_CHECK) == DS2438_OK)
        {
            sprintf(msg, "0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\r\n", serial_number[0], serial_number[1],
                                                                                serial_number[2], serial_number[3],
                                                                                serial_number[4], serial_number[5]);
            debug_print(msg);
        }
        else
        {
            debug_print("CRC Check failed when reading serial number\r\n");
        }
        
        for (uint8_t page = 0; page < 7; page++)
        {
           uint8_t page_data[9];
            DS2438_ReadPage(page, page_data);    
            sprintf(msg, "0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\r\n", page_data[0], page_data[1],
                                                                                page_data[2], page_data[3],
                                                                                page_data[4], page_data[5],
                                                                                page_data[6], page_data[7]);
            debug_print(msg);
        }
    }
    else
    {
        debug_print("Could not find device\r\n");
    }
    
    DS2438_SelectInputSource(DS2438_INPUT_VOLTAGE_VDD, DS2438_NO_CRC_CHECK);
    DS2438_EnableIAD();
    DS2438_EnableCA();
    DS2438_EnableShadowEE();
    for (uint8_t page = 0; page < 7; page++)
    {
       uint8_t page_data[9];
        DS2438_ReadPage(page, page_data);    
        sprintf(msg, "0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\r\n", page_data[0], page_data[1],
                                                                            page_data[2], page_data[3],
                                                                            page_data[4], page_data[5],
                                                                            page_data[6], page_data[7]);
        debug_print(msg);
    }
    float voltage, temperature, current, capacity = 0;
    
    for(;;)
    {
        
        if (DS2438_ReadVoltage(&voltage, DS2438_CRC_CHECK) == DS2438_OK)
        {
            sprintf(msg, "Voltage: %d\r\n", (int)(voltage*1000));
            debug_print(msg);
            
        }
        else
        {
            debug_print("Could not read voltage\r\n");
        }
        
        if (DS2438_ReadTemperature(&temperature, DS2438_CRC_CHECK) == DS2438_OK)
        {
            sprintf(msg, "Temperature: %d\r\n", (int)(temperature*1000));
            debug_print(msg);
        }
        else
        {
            debug_print("Could not read temperature\r\n");
        }
        if (DS2438_GetCurrentData(&current, DS2438_CRC_CHECK) == DS2438_OK)
        {
            sprintf(msg, "mAmps: %d\r\n", (int)(current*1000));
            debug_print(msg);
            
        }
        else
        {
            debug_print("Could not read current\r\n");
        }
        if (DS2438_GetCapacity(&capacity, DS2438_CRC_CHECK) == DS2438_OK)
        {
            sprintf(msg, "Capacity: %d\r\n", (int)(capacity*1000));
            debug_print(msg);
            
        }
        else
        {
            debug_print("Could not read current\r\n");
        }
        for (uint8_t page = 0; page < 7; page++)
        {
           uint8_t page_data[9];
            DS2438_ReadPage(page, page_data);    
            sprintf(msg, "0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\r\n", page_data[0], page_data[1],
                                                                                page_data[2], page_data[3],
                                                                                page_data[4], page_data[5],
                                                                                page_data[6], page_data[7]);
            debug_print(msg);
        }
        CyDelay(1000);
        
    }
}


/* [] END OF FILE */
