#include <stdio.h>
#include <string.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ov7670.h"
#include "hardware/clocks.h"
#include "hardware/pwm.h"



// # ov7670_rgb array
// Manual output format, RGB, use RGB565 and full 0-255 output range
uint8_t _OV7670_rgb[] = {    
        _OV7670_REG_COM7,
        _OV7670_COM7_RGB,
        _OV7670_REG_RGB444,
        0x00,
        _OV7670_REG_COM15,
        //  _OV7670_COM15_RGB565 | _OV7670_COM15_R00FF,
};

// # ov7670_rgb array
// Manual output format, YUV, use full output range
uint8_t _OV7670_yuv[] = {
        _OV7670_REG_COM7,
        _OV7670_COM7_YUV,
        _OV7670_REG_COM15,
        _OV7670_COM15_R00FF,
}; 

uint8_t _OV7670_inits[] = {
        _OV7670_REG_TSLB,
        _OV7670_TSLB_YLAST,  // No auto window
        _OV7670_REG_COM10,
        _OV7670_COM10_VS_NEG,  // -VSYNC (req by SAMD PCC)
        _OV7670_REG_SLOP,
        0x20,
        _OV7670_REG_GAM_BASE,
        0x1C,
        _OV7670_REG_GAM_BASE + 1,
        0x28,
        _OV7670_REG_GAM_BASE + 2,
        0x3C,
        _OV7670_REG_GAM_BASE + 3,
        0x55,
        _OV7670_REG_GAM_BASE + 4,
        0x68,
        _OV7670_REG_GAM_BASE + 5,
        0x76,
        _OV7670_REG_GAM_BASE + 6,
        0x80,
        _OV7670_REG_GAM_BASE + 7,
        0x88,
        _OV7670_REG_GAM_BASE + 8,
        0x8F,
        _OV7670_REG_GAM_BASE + 9,
        0x96,
        _OV7670_REG_GAM_BASE + 10,
        0xA3,
        _OV7670_REG_GAM_BASE + 11,
        0xAF,
        _OV7670_REG_GAM_BASE + 12,
        0xC4,
        _OV7670_REG_GAM_BASE + 13,
        0xD7,
        _OV7670_REG_GAM_BASE + 14,
        0xE8,
        _OV7670_REG_COM8,
        _OV7670_COM8_FASTAEC | _OV7670_COM8_AECSTEP | _OV7670_COM8_BANDING,
        _OV7670_REG_GAIN,
        0x00,
        _OV7670_COM2_SSLEEP,
        0x00,
        _OV7670_REG_COM4,
        0x00,
        _OV7670_REG_COM9,
        0x20,  // Max AGC value
        _OV7670_REG_BD50MAX,
        0x05,
        _OV7670_REG_BD60MAX,
        0x07,
        _OV7670_REG_AEW,
        0x75,
        _OV7670_REG_AEB,
        0x63,
        _OV7670_REG_VPT,
        0xA5,
        _OV7670_REG_HAECC1,
        0x78,
        _OV7670_REG_HAECC2,
        0x68,
        0xA1,
        0x03,  // Reserved register?
        _OV7670_REG_HAECC3,
        0xDF,  // Histogram-based AEC/AGC setup
        _OV7670_REG_HAECC4,
        0xDF,
        _OV7670_REG_HAECC5,
        0xF0,
        _OV7670_REG_HAECC6,
        0x90,
        _OV7670_REG_HAECC7,
        0x94,
        _OV7670_REG_COM8,
        _OV7670_COM8_FASTAEC
        | _OV7670_COM8_AECSTEP
        | _OV7670_COM8_BANDING
        | _OV7670_COM8_AGC
        | _OV7670_COM8_AEC,
        _OV7670_REG_COM5,
        0x61,
        _OV7670_REG_COM6,
        0x4B,
        0x16,
        0x02,  // Reserved register?
        _OV7670_REG_MVFP,
        0x07,  // 0x07,
        _OV7670_REG_ADCCTR1,
        0x02,
        _OV7670_REG_ADCCTR2,
        0x91,
        0x29,
        0x07,  // Reserved register?
        _OV7670_REG_CHLF,
        0x0B,
        0x35,
        0x0B,  // Reserved register?
        _OV7670_REG_ADC,
        0x1D,
        _OV7670_REG_ACOM,
        0x71,
        _OV7670_REG_OFON,
        0x2A,
        _OV7670_REG_COM12,
        0x78,
        0x4D,
        0x40,  // Reserved register?
        0x4E,
        0x20,  // Reserved register?
        _OV7670_REG_GFIX,
        0x5D,
        _OV7670_REG_REG74,
        0x19,
        0x8D,
        0x4F,  // Reserved register?
        0x8E,
        0x00,  // Reserved register?
        0x8F,
        0x00,  // Reserved register?
        0x90,
        0x00,  // Reserved register?
        0x91,
        0x00,  // Reserved register?
        _OV7670_REG_DM_LNL,
        0x00,
        0x96,
        0x00,  // Reserved register?
        0x9A,
        0x80,  // Reserved register?
        0xB0,
        0x84,  // Reserved register?
        _OV7670_REG_ABLC1,
        0x0C,
        0xB2,
        0x0E,  // Reserved register?
        _OV7670_REG_THL_ST,
        0x82,
        0xB8,
        0x0A,  // Reserved register?
        _OV7670_REG_AWBC1,
        0x14,
        _OV7670_REG_AWBC2,
        0xF0,
        _OV7670_REG_AWBC3,
        0x34,
        _OV7670_REG_AWBC4,
        0x58,
        _OV7670_REG_AWBC5,
        0x28,
        _OV7670_REG_AWBC6,
        0x3A,
        0x59,
        0x88,  // Reserved register?
        0x5A,
        0x88,  // Reserved register?
        0x5B,
        0x44,  // Reserved register?
        0x5C,
        0x67,  // Reserved register?
        0x5D,
        0x49,  // Reserved register?
        0x5E,
        0x0E,  // Reserved register?
        _OV7670_REG_LCC3,
        0x04,
        _OV7670_REG_LCC4,
        0x20,
        _OV7670_REG_LCC5,
        0x05,
        _OV7670_REG_LCC6,
        0x04,
        _OV7670_REG_LCC7,
        0x08,
        _OV7670_REG_AWBCTR3,
        0x0A,
        _OV7670_REG_AWBCTR2,
        0x55,
        _OV7670_REG_MTX1,
        0x80,
        _OV7670_REG_MTX2,
        0x80,
        _OV7670_REG_MTX3,
        0x00,
        _OV7670_REG_MTX4,
        0x22,
        _OV7670_REG_MTX5,
        0x5E,
        _OV7670_REG_MTX6,
        0x80,  // 0x40?
        _OV7670_REG_AWBCTR1,
        0x11,
        _OV7670_REG_AWBCTR0,
        0x9F,  // Or use 0x9E for advance AWB
        _OV7670_REG_BRIGHT,
        0x00,
        _OV7670_REG_CONTRAS,
        0x40,
        _OV7670_REG_CONTRAS_CENTER,
        0x80,  // 0x40?

};


// verified
// window settings for different sizes
// 640x480, 320x240, 160x120, 80x60, 40x30
int _window[5][4] = {
    {9, 162, 2, 2},  // SIZE_DIV1  640x480 VGA
    {10, 174, 0, 2},  // SIZE_DIV2  320x240 QVGA
    {11, 186, 2, 2},  // SIZE_DIV4  160x120 QQVGA
    {12, 210, 0, 2},  // SIZE_DIV8  80x60   ...
    {15, 252, 3, 2},  // SIZE_DIV16 40x30
 };   // window settings for different sizes 



 // defined all constants and registers





// get product version from camera
int ov7670_product_version(){
   return ov7670_read_register(_OV7670_REG_VER);
} 

// get product id from camera
int ov7670_product_id(){
   return ov7670_read_register(_OV7670_REG_PID);
} 

// write a register to ov7670
int ov7670_write_register(uint8_t OV7670_I2C_ADDR, uint8_t OV7670_I2C_VALUE){
   // i2c write blocking
   uint8_t value = OV7670_I2C_VALUE;
   i2c_write_blocking(i2c0, OV7670_I2C_ADDR, &value, 2, false);
   return 1;
}


// verified
// read a register from ov7670
int ov7670_read_register(uint8_t reg){
   uint8_t buf;
   // i2c write blocking -- needs to use nostop false, idont know why yet, prob. SCCB doesnt accept repeated start
   i2c_write_blocking(i2c0, OV7670_ADDR, &reg, 1, false);
   // i2c reads 
   i2c_read_blocking(i2c0, OV7670_ADDR, &buf, 1, false);

   return buf;

}

// configs camera, including i2c, reset and mclk pins
int ov7670_config(){

   // mclk clocking generation 16MHz
   gpio_set_function(OV7670_MCLK_PIN, GPIO_FUNC_PWM);
   uint slice_num = pwm_gpio_to_slice_num(OV7670_MCLK_PIN);
   uint channel = pwm_gpio_to_channel(OV7670_MCLK_PIN);


   uint32_t f_sys = clock_get_hz(clk_sys);

   // calc pwm
   uint32_t wrap = (f_sys / (OV7670_MCLK_FREQUENCY * 1000000)) - 1;  // 16 MHz
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

   // reset pin
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
   uint8_t pid = ov7670_product_id();
   uint8_t ver = ov7670_product_version();
   printf("Product ID Number : %x\n",pid);
   printf("Product Version Number : %x\n",ver);
   if (pid == 0x76){
      return 1;
   } else {
      return 0;
   }
}

int ov7670_register_writelist(){
   printf("Writing init registers...\n");

}
