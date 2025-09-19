#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hardware/i2c.h"




//teste
#define PI 3.142

void sayHello(){
   printf("Hello World\n");
}

int add(int a, int b){
   int result;
   result = a+b;
   return result;
}

double area(double radius){
   double areaofcircle = PI*pow(radius, 2);
   return areaofcircle;
}
// teste


int product_version(int x){
   return _read_register(_OV7670_REG_VER)
} 


int _write_register(int reg_addr, int value){
   int OV7670_I2C_ADDR = reg_addr;
   // i2c write blocking
   i2c_write_blocking(i2c_default, OV7670_I2C_ADDR, b, 2, false);
   i2c_read_blocking(i2c_default, OV7670_I2C_ADDR, b, 1, false);
   return 1;
}


int _read_register(int OV7670_I2C_ADDR){
   i2c_write_blocking(i2c_default, OV7670_I2C_ADDR, b, 2, false);

    // writes i2c with reg value b[0
    

    return b[0];

}