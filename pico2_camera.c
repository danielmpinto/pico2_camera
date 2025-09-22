#include <stdio.h>
#include "pico/stdlib.h"
#include "ov7670.h"
#include "hardware/clocks.h"





int main()
{
    stdio_init_all();
    ov7670_config();
    while (true) {
        sleep_ms(1000);
        printf("Product ID Number : %x\n",ov7670_product_id());
        printf("Product Version Number : %x\n",ov7670_product_version());
    }
}
