//ifndef OV7670_h
//define OV7670_h
#ifndef OV7670_H
#define OV7670_H


#define _OV7670_I2C_SDA_PIN        8
#define _OV7670_I2C_SCL_PIN        9

#define MCLK_FREQUENCY             16  // MHz

#define MCLK_PIN                   20  // 

#define  OV7670_ADDR               0x21  // ov7670 address

#define _OV7670_REG_GAIN           0x00  // AGC gain bits 7:0 (9:8 in VREF)
#define _OV7670_REG_BLUE           0x01  // AWB blue channel gain
#define _OV7670_REG_RED            0x02  // AWB red channel gain
#define _OV7670_REG_VREF           0x03  // Vert frame control bits
#define _OV7670_REG_COM1           0x04  // Common control 1
#define _OV7670_COM1_R656          0x40  // COM1 enable R656 format
#define _OV7670_REG_BAVE           0x05  // U/B average level
#define _OV7670_REG_GbAVE          0x06  // Y/Gb average level
#define _OV7670_REG_AECHH          0x07  // Exposure value - AEC 15:10 bits
#define _OV7670_REG_RAVE           0x08  // V/R average level
#define _OV7670_REG_COM2           0x09  // Common control 2
#define _OV7670_COM2_SSLEEP        0x10  // COM2 soft sleep mode
#define _OV7670_REG_PID            0x0A  // Product ID MSB (read-only)
#define _OV7670_REG_VER            0x0B  // Product ID LSB (read-only)
#define _OV7670_REG_COM3           0x0C  // Common control 3
#define _OV7670_COM3_SWAP          0x40  // COM3 output data MSB/LSB swap
#define _OV7670_COM3_SCALEEN       0x08  // COM3 scale enable
#define _OV7670_COM3_DCWEN         0x04  // COM3 DCW enable
#define _OV7670_REG_COM4           0x0D  // Common control 4
#define _OV7670_REG_COM5           0x0E  // Common control 5
#define _OV7670_REG_COM6           0x0F  // Common control 6
#define _OV7670_REG_AECH           0x10  // Exposure value 9:2
#define _OV7670_REG_CLKRC          0x11  // Internal clock
#define _OV7670_CLK_EXT            0x40  // CLKRC Use ext clock directly
#define _OV7670_CLK_SCALE          0x3F  // CLKRC Int clock prescale mask
#define _OV7670_REG_COM7           0x12  // Common control 7
#define _OV7670_COM7_RESET         0x80  // COM7 SCCB register reset
#define _OV7670_COM7_SIZE_MASK     0x38  // COM7 output size mask
#define _OV7670_COM7_PIXEL_MASK    0x05  // COM7 output pixel format mask
#define _OV7670_COM7_SIZE_VGA      0x00  // COM7 output size VGA
#define _OV7670_COM7_SIZE_CIF      0x20  // COM7 output size CIF
#define _OV7670_COM7_SIZE_QVGA     0x10  // COM7 output size QVGA
#define _OV7670_COM7_SIZE_QCIF     0x08  // COM7 output size QCIF
#define _OV7670_COM7_RGB           0x04  // COM7 pixel format RGB
#define _OV7670_COM7_YUV           0x00  // COM7 pixel format YUV
#define _OV7670_COM7_BAYER         0x01  // COM7 pixel format Bayer RAW
#define _OV7670_COM7_PBAYER        0x05  // COM7 pixel fmt proc Bayer RAW
#define _OV7670_COM7_COLORBAR      0x02  // COM7 color bar enable
#define _OV7670_REG_COM8           0x13  // Common control 8
#define _OV7670_COM8_FASTAEC       0x80  // COM8 Enable fast AGC/AEC algo,
#define _OV7670_COM8_AECSTEP       0x40  // COM8 AEC step size unlimited
#define _OV7670_COM8_BANDING       0x20  // COM8 Banding filter enable
#define _OV7670_COM8_AGC           0x04  // COM8 AGC (auto gain) enable
#define _OV7670_COM8_AWB           0x02  // COM8 AWB (auto white balance)
#define _OV7670_COM8_AEC           0x01  // COM8 AEC (auto exposure) enable
#define _OV7670_REG_COM9           0x14  // Common control 9 - max AGC value
#define _OV7670_REG_COM10          0x15  // Common control 10
#define _OV7670_COM10_HSYNC        0x40  // COM10 HREF changes to HSYNC
#define _OV7670_COM10_PCLK_HB      0x20  // COM10 Suppress PCLK on hblank
#define _OV7670_COM10_HREF_REV     0x08  // COM10 HREF reverse
#define _OV7670_COM10_VS_EDGE      0x04  // COM10 VSYNC chg on PCLK rising
#define _OV7670_COM10_VS_NEG       0x02  // COM10 VSYNC negative
#define _OV7670_COM10_HS_NEG       0x01  // COM10 HSYNC negative
#define _OV7670_REG_HSTART         0x17  // Horiz frame start high bits
#define _OV7670_REG_HSTOP          0x18  // Horiz frame end high bits
#define _OV7670_REG_VSTART         0x19  // Vert frame start high bits
#define _OV7670_REG_VSTOP          0x1A  // Vert frame end high bits
#define _OV7670_REG_PSHFT          0x1B  // Pixel delay select
#define _OV7670_REG_MIDH           0x1C  // Manufacturer ID high byte
#define _OV7670_REG_MIDL           0x1D  // Manufacturer ID low byte
#define _OV7670_REG_MVFP           0x1E  // Mirror / vert-flip enable
#define _OV7670_MVFP_MIRROR        0x20  // MVFP Mirror image
#define _OV7670_MVFP_VFLIP         0x10  // MVFP Vertical flip
#define _OV7670_REG_LAEC           0x1F  // Reserved
#define _OV7670_REG_ADCCTR0        0x20  // ADC control
#define _OV7670_REG_ADCCTR1        0x21  // Reserved
#define _OV7670_REG_ADCCTR2        0x22  // Reserved
#define _OV7670_REG_ADCCTR3        0x23  // Reserved
#define _OV7670_REG_AEW            0x24  // AGC/AEC upper limit
#define _OV7670_REG_AEB            0x25  // AGC/AEC lower limit
#define _OV7670_REG_VPT            0x26  // AGC/AEC fast mode op region
#define _OV7670_REG_BBIAS          0x27  // B channel signal output bias
#define _OV7670_REG_GbBIAS         0x28  // Gb channel signal output bias
#define _OV7670_REG_EXHCH          0x2A  // Dummy pixel insert MSB
#define _OV7670_REG_EXHCL          0x2B  // Dummy pixel insert LSB
#define _OV7670_REG_RBIAS          0x2C  // R channel signal output bias
#define _OV7670_REG_ADVFL          0x2D  // Insert dummy lines MSB
#define _OV7670_REG_ADVFH          0x2E  // Insert dummy lines LSB
#define _OV7670_REG_YAVE           0x2F  // Y/G channel average value
#define _OV7670_REG_HSYST          0x30  // HSYNC rising edge delay
#define _OV7670_REG_HSYEN          0x31  // HSYNC falling edge delay
#define _OV7670_REG_HREF           0x32  // HREF control
#define _OV7670_REG_CHLF           0x33  // Array current control
#define _OV7670_REG_ARBLM          0x34  // Array ref control - reserved
#define _OV7670_REG_ADC            0x37  // ADC control - reserved
#define _OV7670_REG_ACOM           0x38  // ADC & analog common - reserved
#define _OV7670_REG_OFON           0x39  // ADC offset control - reserved
#define _OV7670_REG_TSLB           0x3A  // Line buffer test option
#define _OV7670_TSLB_NEG           0x20  // TSLB Negative image enable
#define _OV7670_TSLB_YLAST         0x04  // TSLB UYVY or VYUY, see COM13
#define _OV7670_TSLB_AOW           0x01  // TSLB Auto output window
#define _OV7670_REG_COM11          0x3B  // Common control 11
#define _OV7670_COM11_NIGHT        0x80  // COM11 Night mode
#define _OV7670_COM11_NMFR         0x60  // COM11 Night mode frame rate mask
#define _OV7670_COM11_HZAUTO       0x10  // COM11 Auto detect 50/60 Hz
#define _OV7670_COM11_BAND         0x08  // COM11 Banding filter val select
#define _OV7670_COM11_EXP          0x02  // COM11 Exposure timing control
#define _OV7670_REG_COM12          0x3C  // Common control 12
#define _OV7670_COM12_HREF         0x80  // COM12 Always has HREF
#define _OV7670_REG_COM13          0x3D  // Common control 13
#define _OV7670_COM13_GAMMA        0x80  // COM13 Gamma enable
#define _OV7670_COM13_UVSAT        0x40  // COM13 UV saturation auto adj
#define _OV7670_COM13_UVSWAP       0x01  // COM13 UV swap, use w TSLB[3]
#define _OV7670_REG_COM14          0x3E  // Common control 14
#define _OV7670_COM14_DCWEN        0x10  // COM14 DCW & scaling PCLK enable
#define _OV7670_REG_EDGE           0x3F  // Edge enhancement adjustment
#define _OV7670_REG_COM15          0x40  // Common control 15
#define _OV7670_COM15_RMASK        0xC0  // COM15 Output range mask
#define _OV7670_COM15_R10F0        0x00  // COM15 Output range 10 to F0
#define _OV7670_COM15_R01FE        0x80  // COM15              01 to FE
#define _OV7670_COM15_R00FF        0xC0  // COM15              00 to FF
#define _OV7670_COM15_RGBMASK      0x30  // COM15 RGB 555/565 option mask
#define _OV7670_COM15_RGB          0x00  // COM15 Normal RGB out
#define _OV7670_COM15_RGB565       0x10  // COM15 RGB 565 output
#define _OV7670_COM15_RGB555       0x30  // COM15 RGB 555 output
#define _OV7670_REG_COM16          0x41  // Common control 16
#define _OV7670_COM16_AWBGAIN      0x08  // COM16 AWB gain enable
#define _OV7670_REG_COM17          0x42  // Common control 17
#define _OV7670_COM17_AECWIN       0xC0  // COM17 AEC window must match COM4
#define _OV7670_COM17_CBAR         0x08  // COM17 DSP Color bar enable
#define _OV7670_REG_AWBC1          0x43  // Reserved
#define _OV7670_REG_AWBC2          0x44  // Reserved
#define _OV7670_REG_AWBC3          0x45  // Reserved
#define _OV7670_REG_AWBC4          0x46  // Reserved
#define _OV7670_REG_AWBC5          0x47  // Reserved
#define _OV7670_REG_AWBC6          0x48  // Reserved
#define _OV7670_REG_REG4B          0x4B  // UV average enable
#define _OV7670_REG_DNSTH          0x4C  // De-noise strength
#define _OV7670_REG_MTX1           0x4F  // Matrix coefficient 1
#define _OV7670_REG_MTX2           0x50  // Matrix coefficient 2
#define _OV7670_REG_MTX3           0x51  // Matrix coefficient 3
#define _OV7670_REG_MTX4           0x52  // Matrix coefficient 4
#define _OV7670_REG_MTX5           0x53  // Matrix coefficient 5
#define _OV7670_REG_MTX6           0x54  // Matrix coefficient 6
#define _OV7670_REG_BRIGHT         0x55  // Brightness control
#define _OV7670_REG_CONTRAS        0x56  // Contrast control
#define _OV7670_REG_CONTRAS_CENTER 0x57  // Contrast center
#define _OV7670_REG_MTXS           0x58  // Matrix coefficient sign
#define _OV7670_REG_LCC1           0x62  // Lens correction option 1
#define _OV7670_REG_LCC2           0x63  // Lens correction option 2
#define _OV7670_REG_LCC3           0x64  // Lens correction option 3
#define _OV7670_REG_LCC4           0x65  // Lens correction option 4
#define _OV7670_REG_LCC5           0x66  // Lens correction option 5
#define _OV7670_REG_MANU           0x67  // Manual U value
#define _OV7670_REG_MANV           0x68  // Manual V value
#define _OV7670_REG_GFIX           0x69  // Fix gain control
#define _OV7670_REG_GGAIN          0x6A  // G channel AWB gain
#define _OV7670_REG_DBLV           0x6B  // PLL & regulator control
#define _OV7670_REG_AWBCTR3        0x6C  // AWB control 3
#define _OV7670_REG_AWBCTR2        0x6D  // AWB control 2
#define _OV7670_REG_AWBCTR1        0x6E  // AWB control 1
#define _OV7670_REG_AWBCTR0        0x6F  // AWB control 0
#define _OV7670_REG_SCALING_XSC    0x70  // Test pattern X scaling
#define _OV7670_REG_SCALING_YSC    0x71  // Test pattern Y scaling
#define _OV7670_REG_SCALING_DCWCTR 0x72  // DCW control
#define _OV7670_REG_SCALING_PCLK_DIV 0x73 // DSP scale control clock divide
#define _OV7670_REG_REG74          0x74  // Digital gain control
#define _OV7670_REG_REG76          0x76  // Pixel correction
#define _OV7670_REG_SLOP           0x7A  // Gamma curve highest seg slope
#define _OV7670_REG_GAM_BASE       0x7B  // Gamma register base (1 of 15)
#define _OV7670_GAM_LEN            0x0F  // Number of gamma registers
#define _OV7670_R76_BLKPCOR        0x80  // REG76 black pixel corr enable
#define _OV7670_R76_WHTPCOR        0x40  // REG76 white pixel corr enable
#define _OV7670_REG_RGB444         0x8C  // RGB 444 control
#define _OV7670_R444_ENABLE        0x02  // RGB444 enable
#define _OV7670_R444_RGBX          0x01  // RGB444 word format
#define _OV7670_REG_DM_LNL         0x92  // Dummy line LSB
#define _OV7670_REG_LCC6           0x94  // Lens correction option 6
#define _OV7670_REG_LCC7           0x95  // Lens correction option 7
#define _OV7670_REG_HAECC1         0x9F  // Histogram-based AEC/AGC ctrl 1
#define _OV7670_REG_HAECC2         0xA0  // Histogram-based AEC/AGC ctrl 2
#define _OV7670_REG_SCALING_PCLK_DELAY 0xA2 // Scaling pixel clock delay
#define _OV7670_REG_BD50MAX        0xA5  // 50 Hz banding step limit
#define _OV7670_REG_HAECC3         0xA6  // Histogram-based AEC/AGC ctrl 3
#define _OV7670_REG_HAECC4         0xA7  // Histogram-based AEC/AGC ctrl 4
#define _OV7670_REG_HAECC5         0xA8  // Histogram-based AEC/AGC ctrl 5
#define _OV7670_REG_HAECC6         0xA9  // Histogram-based AEC/AGC ctrl 6
#define _OV7670_REG_HAECC7         0xAA  // Histogram-based AEC/AGC ctrl 7
#define _OV7670_REG_BD60MAX        0xAB  // 60 Hz banding step limit
#define _OV7670_REG_ABLC1          0xB1  // ABLC enable
#define _OV7670_REG_THL_ST         0xB3  // ABLC target
#define _OV7670_REG_SATCTR         0xC9  // Saturation control


#define _OV7670_REG_LAST = _OV7670_REG_SATCTR  // Maximum register address

// // # ov7670_rgb array
// // Manual output format, RGB, use RGB565 and full 0-255 output range
// uint8_t _OV7670_rgb[] = { 
    
//         _OV7670_REG_COM7,
//         _OV7670_COM7_RGB,
//         _OV7670_REG_RGB444,
//         0,
//         _OV7670_REG_COM15,
//         _OV7670_COM15_RGB565 | _OV7670_COM15_R00FF,
    
// };



// // # ov7670_rgb array
// // Manual output format, YUV, use full output range
// uint8_t _OV7670_yuv[] = {
//         _OV7670_REG_COM7,
//         _OV7670_COM7_YUV,
//         _OV7670_REG_COM15,
//         _OV7670_COM15_R00FF,
// };    

// _OV7670_init = bytes(
//     [
//         _OV7670_REG_TSLB,
//         _OV7670_TSLB_YLAST,  // No auto window
//         _OV7670_REG_COM10,
//         _OV7670_COM10_VS_NEG,  // -VSYNC (req by SAMD PCC)
//         _OV7670_REG_SLOP,
//         0x20,
//         _OV7670_REG_GAM_BASE,
//         0x1C,
//         _OV7670_REG_GAM_BASE + 1,
//         0x28,
//         _OV7670_REG_GAM_BASE + 2,
//         0x3C,
//         _OV7670_REG_GAM_BASE + 3,
//         0x55,
//         _OV7670_REG_GAM_BASE + 4,
//         0x68,
//         _OV7670_REG_GAM_BASE + 5,
//         0x76,
//         _OV7670_REG_GAM_BASE + 6,
//         0x80,
//         _OV7670_REG_GAM_BASE + 7,
//         0x88,
//         _OV7670_REG_GAM_BASE + 8,
//         0x8F,
//         _OV7670_REG_GAM_BASE + 9,
//         0x96,
//         _OV7670_REG_GAM_BASE + 10,
//         0xA3,
//         _OV7670_REG_GAM_BASE + 11,
//         0xAF,
//         _OV7670_REG_GAM_BASE + 12,
//         0xC4,
//         _OV7670_REG_GAM_BASE + 13,
//         0xD7,
//         _OV7670_REG_GAM_BASE + 14,
//         0xE8,
//         _OV7670_REG_COM8,
//         _OV7670_COM8_FASTAEC | _OV7670_COM8_AECSTEP | _OV7670_COM8_BANDING,
//         _OV7670_REG_GAIN,
//         0x00,
//         _OV7670_COM2_SSLEEP,
//         0x00,
//         _OV7670_REG_COM4,
//         0x00,
//         _OV7670_REG_COM9,
//         0x20,  // Max AGC value
//         _OV7670_REG_BD50MAX,
//         0x05,
//         _OV7670_REG_BD60MAX,
//         0x07,
//         _OV7670_REG_AEW,
//         0x75,
//         _OV7670_REG_AEB,
//         0x63,
//         _OV7670_REG_VPT,
//         0xA5,
//         _OV7670_REG_HAECC1,
//         0x78,
//         _OV7670_REG_HAECC2,
//         0x68,
//         0xA1,
//         0x03,  // Reserved register?
//         _OV7670_REG_HAECC3,
//         0xDF,  // Histogram-based AEC/AGC setup
//         _OV7670_REG_HAECC4,
//         0xDF,
//         _OV7670_REG_HAECC5,
//         0xF0,
//         _OV7670_REG_HAECC6,
//         0x90,
//         _OV7670_REG_HAECC7,
//         0x94,
//         _OV7670_REG_COM8,
//         _OV7670_COM8_FASTAEC
//         | _OV7670_COM8_AECSTEP
//         | _OV7670_COM8_BANDING
//         | _OV7670_COM8_AGC
//         | _OV7670_COM8_AEC,
//         _OV7670_REG_COM5,
//         0x61,
//         _OV7670_REG_COM6,
//         0x4B,
//         0x16,
//         0x02,  // Reserved register?
//         _OV7670_REG_MVFP,
//         0x07,  // 0x07,
//         _OV7670_REG_ADCCTR1,
//         0x02,
//         _OV7670_REG_ADCCTR2,
//         0x91,
//         0x29,
//         0x07,  // Reserved register?
//         _OV7670_REG_CHLF,
//         0x0B,
//         0x35,
//         0x0B,  // Reserved register?
//         _OV7670_REG_ADC,
//         0x1D,
//         _OV7670_REG_ACOM,
//         0x71,
//         _OV7670_REG_OFON,
//         0x2A,
//         _OV7670_REG_COM12,
//         0x78,
//         0x4D,
//         0x40,  // Reserved register?
//         0x4E,
//         0x20,  // Reserved register?
//         _OV7670_REG_GFIX,
//         0x5D,
//         _OV7670_REG_REG74,
//         0x19,
//         0x8D,
//         0x4F,  // Reserved register?
//         0x8E,
//         0x00,  // Reserved register?
//         0x8F,
//         0x00,  // Reserved register?
//         0x90,
//         0x00,  // Reserved register?
//         0x91,
//         0x00,  // Reserved register?
//         _OV7670_REG_DM_LNL,
//         0x00,
//         0x96,
//         0x00,  // Reserved register?
//         0x9A,
//         0x80,  // Reserved register?
//         0xB0,
//         0x84,  // Reserved register?
//         _OV7670_REG_ABLC1,
//         0x0C,
//         0xB2,
//         0x0E,  // Reserved register?
//         _OV7670_REG_THL_ST,
//         0x82,
//         0xB8,
//         0x0A,  // Reserved register?
//         _OV7670_REG_AWBC1,
//         0x14,
//         _OV7670_REG_AWBC2,
//         0xF0,
//         _OV7670_REG_AWBC3,
//         0x34,
//         _OV7670_REG_AWBC4,
//         0x58,
//         _OV7670_REG_AWBC5,
//         0x28,
//         _OV7670_REG_AWBC6,
//         0x3A,
//         0x59,
//         0x88,  // Reserved register?
//         0x5A,
//         0x88,  // Reserved register?
//         0x5B,
//         0x44,  // Reserved register?
//         0x5C,
//         0x67,  // Reserved register?
//         0x5D,
//         0x49,  // Reserved register?
//         0x5E,
//         0x0E,  // Reserved register?
//         _OV7670_REG_LCC3,
//         0x04,
//         _OV7670_REG_LCC4,
//         0x20,
//         _OV7670_REG_LCC5,
//         0x05,
//         _OV7670_REG_LCC6,
//         0x04,
//         _OV7670_REG_LCC7,
//         0x08,
//         _OV7670_REG_AWBCTR3,
//         0x0A,
//         _OV7670_REG_AWBCTR2,
//         0x55,
//         _OV7670_REG_MTX1,
//         0x80,
//         _OV7670_REG_MTX2,
//         0x80,
//         _OV7670_REG_MTX3,
//         0x00,
//         _OV7670_REG_MTX4,
//         0x22,
//         _OV7670_REG_MTX5,
//         0x5E,
//         _OV7670_REG_MTX6,
//         0x80,  // 0x40?
//         _OV7670_REG_AWBCTR1,
//         0x11,
//         _OV7670_REG_AWBCTR0,
//         0x9F,  // Or use 0x9E for advance AWB
//         _OV7670_REG_BRIGHT,
//         0x00,
//         _OV7670_REG_CONTRAS,
//         0x40,
//         _OV7670_REG_CONTRAS_CENTER,
//         0x80,  // 0x40?
//     ]
// )

// _window = [
//     [9, 162, 2, 2],  // SIZE_DIV1  640x480 VGA
//     [10, 174, 0, 2],  // SIZE_DIV2  320x240 QVGA
//     [11, 186, 2, 2],  // SIZE_DIV4  160x120 QQVGA
//     [12, 210, 0, 2],  // SIZE_DIV8  80x60   ...
//     [15, 252, 3, 2],  // SIZE_DIV16 40x30
// ]
// // end registers

// //endif

int ov7670_config(void);

int ov7670_product_version(void);

int ov7670_product_id(void);

int ov7670_write_register(uint8_t OV7670_I2C_ADDR, uint8_t OV7670_I2C_VALUE);

int ov7670_read_register(uint8_t OV7670_I2C_ADDR);




#endif