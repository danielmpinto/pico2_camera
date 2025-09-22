#include <stdio.h>
#include <string.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ov7670.h"

// temp
#include "hardware/clocks.h"
#include "hardware/pwm.h"




int ov7670_product_version(){
   return ov7670_read_register(_OV7670_REG_VER);
} 

int ov7670_product_id(){
   return ov7670_read_register(_OV7670_REG_PID);
} 


int ov7670_write_register(uint8_t OV7670_I2C_ADDR, uint8_t OV7670_I2C_VALUE){
   // i2c write blocking
   uint8_t value = OV7670_I2C_VALUE;
   i2c_write_blocking(i2c0, OV7670_I2C_ADDR, &value, 2, false);
   return 1;
}


// verified
int ov7670_read_register(uint8_t reg){
   uint8_t buf;
   // i2c write blocking
   i2c_write_blocking(i2c0, OV7670_ADDR, &reg, 1, false);
   // i2c reads 
   i2c_read_blocking(i2c0, OV7670_ADDR, &buf, 1, false);

   return buf;

}




int ov7670_config(){

   // mclk clocking generation 16MHz
   gpio_set_function(OV7670_MCLK_PIN, GPIO_FUNC_PWM);
   uint slice_num = pwm_gpio_to_slice_num(OV7670_MCLK_PIN);
   uint channel = pwm_gpio_to_channel(OV7670_MCLK_PIN);


   uint32_t f_sys = clock_get_hz(clk_sys);

   // calc pwm
   uint32_t wrap = (f_sys / 16000000) - 1;  // 16 MHz
   pwm_set_clkdiv(slice_num, 1.0f)   ;
   pwm_set_wrap(slice_num, wrap);
   pwm_set_chan_level(slice_num, channel, (wrap + 1) / 2);

   // enables pwm
   pwm_set_enabled(slice_num, true);

   // mclk clocking generation 16MHz - ok


   // i2c config 
   i2c_init(i2c0, 100 * 1000);
   gpio_set_function(_OV7670_I2C_SDA_PIN, GPIO_FUNC_I2C);
   gpio_set_function(_OV7670_I2C_SCL_PIN, GPIO_FUNC_I2C);
   gpio_pull_up(_OV7670_I2C_SDA_PIN);
   gpio_pull_up(_OV7670_I2C_SCL_PIN);
   // i2c config - ok

   // camera reset
   gpio_init(OV7670_RESET_PIN);
   gpio_set_dir(OV7670_RESET_PIN, GPIO_OUT);

   gpio_put(OV7670_RESET_PIN, 0);
   sleep_ms(1);
   gpio_put(OV7670_RESET_PIN, 1);
   // reseta camera - ok

   // give time before testing registers
   sleep_ms(100);
   return 1;
}

// test camera basic registers
int ov7670_register_test(){
   int pid = ov7670_product_id();
   int ver = ov7670_product_version();
   printf("Product ID Number : %x\n",pid);
   printf("Product Version Number : %x\n",ver);
   if (pid == 0x76){
      return 1;
   } else {
      return 0;
   }
}