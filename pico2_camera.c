#include <stdio.h>
#include "pico/stdlib.h"
#include "ov7670.h"
#include "hardware/clocks.h"


// use 4.7Kohm pullups on SDA and SCL lines




int main()
{
    stdio_init_all();
    ov7670_config();
    ov7670_register_test();
    while (true) {
        sleep_ms(1000);

    }
}
