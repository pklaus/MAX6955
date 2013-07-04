/*
 * MAX6955
 * Copyright 2013 Philipp Klaus
 */

#include "MAX6955.h"

#include "Arduino.h"
#include "Wire.h"

MAX6955::MAX6955(char id)
{
    _id = (id & 0x0F) | 0x60;
    // this is the same as
    // _id = _id & B1111 | B1100000;
}
void MAX6955::init()
{
    Wire.begin();
    // ↓ 0x00 = No decode for any digit
    //   0xFF = hexadecimal decode for all digits
    write(max6955_reg_decodeMode, 0xFF); // no decode!
    // ↓ 0x00 =  1/16 (min on)  2.5 mA typical segment current
    //   0x0F = 15/16 (max on) 37.5 mA
    write(max6955_reg_globalIntensity, 0x0F);
    // ↓ 0x00 display only digit 0
    //   0x07 display all digits 0-7
    write(max6955_reg_scanLimit, 0x07);
    // ↓ 0x00: Shutdown
    //   0x01: Normal operation
    //   0x20: Blink timing counters reset at I2C ack
    //   0x00: Global intensity
    //   0x40: Individual intensity settings
    //write(max6955_reg_configuration, 0x21);
    write(max6955_reg_configuration, 0x01);
    // ↓ 0xFF = digits 0-7 are 14-segment digits
    //   0x00 = digits 0-7 are 16- or 7-segment digits
    write(max6955_reg_digitType, 0x00);
    // ↓ 0x00 = Display Test Off
    write(max6955_reg_displayTest, 0x00);
}

int MAX6955::write(char command, char data){
    Wire.beginTransmission(_id);
    Wire.write(command);
    Wire.write(data);
    Wire.endTransmission();
}
 
void MAX6955::clear(){
  for(int i = max6955_reg_digit0; i <= max6955_reg_digit7a; i++)
    write(i, 0x00);
}

