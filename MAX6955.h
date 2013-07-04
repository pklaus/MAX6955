/*
 * MAX6955
 * Copyright 2013 Philipp Klaus
 */

#ifndef _MAX6955_H_
#define _MAX6955_H_

#include "Arduino.h"
#include "Wire.h"

/*
 * Check Table 4. Connection Scheme for Sixteen 7-Segment Digits
 * for information on how to connect the 7-Segment Digits.
 *
 * Information on how to use I2C on Arduino Due:
 * http://forum.arduino.cc/index.php?topic=132981.0
 * You must provide 1.5k pullup resistors if using SCL1 and SDA1
 */


#define max7219_reg_shutdown    0x0c
#define max7219_reg_displayTest 0x0f

#define max6955_reg_noOp            0x00
#define max6955_reg_decodeMode      0x01
#define max6955_reg_globalIntensity 0x02
#define max6955_reg_scanLimit       0x03
#define max6955_reg_configuration   0x04
#define max6955_reg_gpioData        0x05
#define max6955_reg_portConfiguration 0x06
#define max6955_reg_displayTest     0x07
#define max6955_reg_digitType       0x0C

#define max6955_reg_intensity10     0x10
#define max6955_reg_intensity32     0x11
#define max6955_reg_intensity54     0x12
#define max6955_reg_intensity76     0x13
#define max6955_reg_intensity10a    0x14
#define max6955_reg_intensity32a    0x15
#define max6955_reg_intensity54a    0x16
#define max6955_reg_intensity76a    0x17

#define max6955_USE_GLOBAL          0x00
#define max6955_USE_DISCRETE        0x40
#define max6955_RUN                 0x01
#define max6955_SHUTDOWN            0x00

#define max6955_reg_digit0          0x60
#define max6955_reg_digit1          0x61
#define max6955_reg_digit2          0x62
#define max6955_reg_digit3          0x63
#define max6955_reg_digit4          0x64
#define max6955_reg_digit5          0x65
#define max6955_reg_digit6          0x66
#define max6955_reg_digit7          0x67
#define max6955_reg_digit0a         0x68
#define max6955_reg_digit1a         0x69
#define max6955_reg_digit2a         0x6A
#define max6955_reg_digit3a         0x6B
#define max6955_reg_digit4a         0x6C
#define max6955_reg_digit5a         0x6D
#define max6955_reg_digit6a         0x6E
#define max6955_reg_digit7a         0x6F

class MAX6955{
    public:
        /* 
         * @param sda pin for I2C SDA
         * @param scl pin for I2C SCL
         * @param driver I2C device address
         */
        //MAX6955();
        MAX6955(char id);   
        void init();   
        int write(char command, char data);
        void clear(void);

        
    private:
        int _id;
};



#endif

