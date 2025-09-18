#include <stdio.h>
#include "pico/stdlib.h"
#include "ov7670_driver"

int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
