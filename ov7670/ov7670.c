#include <stdio.h>
#include <string.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ov7670.h"






int _product_version(){
   return _read_register(_OV7670_REG_VER);
} 

int _product_id(){
   return _read_register(_OV7670_REG_PID);
} 


int _write_register(int OV7670_I2C_ADDR, int OV7670_I2C_VALUE){
   // i2c write blocking
   uint8_t value = OV7670_I2C_VALUE;
   i2c_write_blocking(i2c_default, OV7670_I2C_ADDR, &value, 2, false);
   return 1;
}


int _read_register(int reg){
   uint8_t reg_addr = reg;
   uint8_t buf[6];
   // i2c write blocking
   i2c_write_blocking(i2c_default, OV7670_ADDR, &reg_addr, 1, true);
   // i2c reads 
   i2c_read_blocking(i2c_default, OV7670_ADDR, buf, 1, false);

   return buf[0];

}


int _i2c_init(){
   i2c_init(i2c_default, 100 * 1000);
   gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
   gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
   gpio_pull_up(4);
   gpio_pull_up(5);
   return 1;
}