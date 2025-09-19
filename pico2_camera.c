#include <stdio.h>
#include "pico/stdlib.h"
#include "ov7670.h"

int main()
{
    stdio_init_all();

    _i2c_init();
    
    while (true) {
        printf("Hello, i2c!\n");
        sleep_ms(1000);
    }
}
