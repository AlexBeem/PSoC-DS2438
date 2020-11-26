# PSoC DS2438 Library
This repository contains the code required to interface a PSoC 5 LP microcontroller to a DS2438 Smart Battery Monitor. 

## Setup
My current setup for testing purposes is based on a custom PCB which I designed. On this PCB I've placed a [CY8CKIT-059](https://www.cypress.com/documentation/development-kitsboards/cy8ckit-059-psoc-5lp-prototyping-kit-onboard-programmer-and) PSoC 5LP prototyping kit and a [DS2438](https://www.maximintegrated.com/en/products/power/battery-management/DS2438.html). The PCB is powered from a LiPo battery, and the DS2438 is used to monitor the battery status.

### Hardware connections
The DQ pin of the DS2438 is connected to Pin 1.4 of the PSoC Kit through a 2.2kOhm resistor. I use a FT232 IC to communicate over a USB port, but if you want you can the USB-UART bridge of the KitProg by just changing the UART pins to 12.6 for UART_RX and 12.7 for UART_TX.

## TODO
- The current implementation works with only one DS2438 device on the 1-Wire interface, as the SKIP_ROM commands are issued with read/write transactions. An update is required to make this library work with multiple DS2438 devices connected to the same 1-Wire interface.

## References
[DS2438 Datasheet](https://datasheets.maximintegrated.com/en/ds/DS2438.pdf)