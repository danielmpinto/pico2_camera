#include <stdio.h>
#include "pico/stdlib.h"
#include "ov7670.h"

// observations:
// use 4.7Kohm pullups on SDA and SCL lines


typedef struct {
    uint8_t size;
    uint8_t colorspace;
    bool flip_y;
    uint8_t test_pattern;
    uint16_t width;
    uint16_t height;
} ov7670_config_t;


ov7670_config_t cam;

#define WIDTH 40
#define HEIGHT 30

int main()
{
    stdio_init_all();
    // ov7670 shutdown, theorically not needed
    ov7670_shutdown();
    ov7670_config();

    // Configuração da câmera
    cam.size = OV7670_SIZE_DIV16;
    cam.colorspace = OV7670_COLOR_YUV;
    cam.flip_y = true;
    // cam.test_pattern = OV7670_TEST_PATTERN_COLOR_BAR_FADE; // opcional

    // Buffers estáticos (máximo: 640x480 RGB565 = 2 * 640 * 480 = 614400 bytes)
    static uint8_t buf[2 * WIDTH * HEIGHT];   // buffer principal
    static uint8_t row[2 * WIDTH];         // buffer para uma linha

    // Tabela de caracteres para ASCII-art
    const char chars[] = " .:-=+*#%@";

    // Uso
    uint16_t width  = cam_width(cam.size);
    uint16_t height = cam_height(cam.size);

    // Limpar terminal (sequência ANSI)
    printf("\033[2J");
    while (true) {
        
    sleep_ms(50);
    }
}
