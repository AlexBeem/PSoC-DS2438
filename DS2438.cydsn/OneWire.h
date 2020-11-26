/** 
 * \file OneWire.h
 * \brief Library for the OneWire communication interface.
 *
 * This interface allows to implement the OneWire communication
 * interface on PSoC 3/5LP devices. This implementation is based 
 * on what is reported by Maxim Integrated in their application
 * note on 1-Wire interface, that can be found at this
 * [link](https://www.maximintegrated.com/en/design/technical-documents/app-notes/1/126.html).
*/
#ifndef __ONEWIRE_H__
    #define __ONEWIRE_H__
    
    /**
    *   \brief Reset device on 1-Wire interface.
    *
    *   This function resets the devices connected 
    *   to the 1-Wire interface on the pin passed in
    *   as parameter to the function.
    *   \param pin 1-Wire interface pin. This value can be found in the Pin_aliases.h file
    *       in the Pin folder in the Generated source folder.
    *   \retval 1 if no device was found on 1-Wire interface
    *   \retval 0 if a device was found on 1-Wire interface
    */
    int OneWire_TouchReset(unsigned int pin);
    
    /**
    *   \brief Write a bit on 1-Wire interface.
    *   
    *   This function writes a single bit on the 1-Wire
    *   interface.
    *   \param pin 1-Wire interface pin. This value can be found in the Pin_aliases.h file
    *       in the Pin folder in the Generated source folder.
    *   \param bit the bit to be written.
    */
    void OneWire_WriteBit(unsigned int pin, int bit);
    
    /**
    *   \brief Read a bit on 1-Wire interface.
    *   
    *   This function reads a single bit on the 1-Wire
    *   interface.
    *   \param pin 1-Wire interface pin. This value can be found in the Pin_aliases.h file
    *       in the Pin folder in the Generated source folder.
    *   \return the bit that was read.
    */
    int OneWire_ReadBit(unsigned int pin);
    
    /**
    *   \brief Write a byte on 1-Wire interface.
    *   
    *   This function writes a byte on the 1-Wire
    *   interface.
    *   \param pin 1-Wire interface pin. This value can be found in the Pin_aliases.h file
    *       in the Pin folder in the Generated source folder.
    *   \param data the byte to be written.
    */
    void OneWire_WriteByte(unsigned int pin, int data);
    
    /**
    *   \brief Read a byte on 1-Wire interface.
    *   
    *   This function reads a byte on the 1-Wire
    *   interface.
    *   \param pin 1-Wire interface pin. This value can be found in the Pin_aliases.h file
    *       in the Pin folder in the Generated source folder.
    *   \return the byte that was read.
    */
    int OneWire_ReadByte(unsigned int pin);
    
    /**
    *   \brief Write a byte and read the sampled result.
    *
    *   This function writes a byte on the 1-Wire interface
    *   and read the sampled result.
    *   \param pin 1-Wire interface pin. This value can be found in the Pin_aliases.h file
    *       in the Pin folder in the Generated source folder.
    *   \param data the byte to be written.
    *   \return the data that was read.
    */
    int OneWire_TouchByte(unsigned int pin, int data);
    
    /**
    *   \brief Write a block of data and read the sampled result.
    *
    *   This function writes a block of bytes on the 1-Wire interface
    *   and read the sampled result.
    *   \param pin 1-Wire interface pin. This value can be found in the Pin_aliases.h file
    *       in the Pin folder in the Generated source folder.
    *   \param data the byte to be written.
    *   \param data_len the total number of bytes to be written. 
    *        The sampled values are stored in the same buffer
    */
    void OneWire_Block(unsigned int pin, unsigned char *data, int data_len);
    
    
    
#endif
/* [] END OF FILE */
