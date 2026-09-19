#include "ADXL_interface.h"

/*
    its a 3-axis sensing sensor 
    it uses i2c or SPI comeucation protocls to give x , y , z axis
    i downloaded it from https://electronicstree.com/new-adxl345-proteus-library/
    and i will do it in I2C mode
    in the data sheet to use i2c i need to tie CS to VCC for that
    figure 40 the CS has a BAR on it means its active low so connecting it to vcc makes it work
    then connect the ALT address or the SDO pin to ground (idk why relly) for the adrres to be 0x53
    then connect SDA with PD1 and SCL with PD0 

*/