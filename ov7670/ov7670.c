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

      // mclk clocking temp
   gpio_set_function(MCLK_PIN, GPIO_FUNC_PWM);
   uint slice_num = pwm_gpio_to_slice_num(MCLK_PIN);
   uint channel = pwm_gpio_to_channel(MCLK_PIN);


   uint32_t f_sys = clock_get_hz(clk_sys);

   uint32_t wrap = (f_sys / 16000000) - 1;  // 16 MHz

   pwm_set_clkdiv(slice_num, 1.0f)   ;
   pwm_set_wrap(slice_num, wrap);
   pwm_set_chan_level(slice_num, channel, (wrap + 1) / 2);

   pwm_set_enabled(slice_num, true);

   // clock testado gerando 16 mhz 




   // i2c config 
   i2c_init(i2c0, 100 * 1000);
   gpio_set_function(_OV7670_I2C_SDA_PIN, GPIO_FUNC_I2C);
   gpio_set_function(_OV7670_I2C_SCL_PIN, GPIO_FUNC_I2C);
   gpio_pull_up(_OV7670_I2C_SDA_PIN);
   gpio_pull_up(_OV7670_I2C_SCL_PIN);

      //reseta camera
   // gpio_init(10);
   // gpio_set_dir(10, GPIO_OUT);

   // gpio_put(10, 0);
   // sleep_ms(1);
   // gpio_put(10, 1);

   
   for (uint8_t addr = 0; addr < 128; addr++) {
    int ret = i2c_write_blocking(i2c0, addr, NULL, 0, false);
    if (ret >= 0) {
        printf("Dispositivo encontrado no endereco 0x%02x\n", addr);
    }


}





   return 1;
}