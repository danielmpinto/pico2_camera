#include <stdio.h>
#include "pico/stdlib.h"
#include <ov7670.h>

int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
        add(1, 2);
    }
}
