#include <stdio.h>
#include "pico/stdlib.h"
#include "ov7670.h"

int main()
{
    stdio_init_all();

    _i2c_init();
    
    while (true) {
        sleep_ms(1000);
        printf("Product ID Number : %x\n",_product_id());
        printf("Product Version Number : %x\n",_product_version());
    }
}
