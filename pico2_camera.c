#include <stdio.h>
#include "pico/stdlib.h"
#include "ov7670.h"

// observations:
// use 4.7Kohm pullups on SDA and SCL lines




int main()
{
    stdio_init_all();
    // ov7670 shutdown, theorically not needed
    ov7670_shutdown();
    ov7670_config();

    // cam.size = OV7670_SIZE_DIV16;
    // cam.colorspace = OV7670_COLOR_YUV;
    // cam.flip_y = True;
    // # cam.test_pattern = OV7670_TEST_PATTERN_COLOR_BAR_FADE;

    // buf = bytearray(2 * cam.width * cam.height);
    // char string[] = " .:-=+*#%@";

    // width = cam.width;
    // row = bytearray(2 * width);

    // sys.stdout.write("\033[2J");

    while (true) {
        // cam.capture(buf)
        // for j in range(cam.height):
        //     sys.stdout.write(f"\033[{j}H")
        //     for i in range(cam.width):
        //         row[i * 2] = row[i * 2 + 1] = chars[buf[2 * (width * j + i)] * (len(chars) - 1) // 255]
        //     sys.stdout.write(row)
        //     sys.stdout.write("\033[K")
        // sys.stdout.write("\033[J")
        sleep_ms(50);
    }
}
