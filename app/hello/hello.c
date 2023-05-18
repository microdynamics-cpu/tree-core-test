#include <am.h>
#include <klib.h>
#include <klib-macros.h>

extern int drv_uart_getc();
int main(){
    putstr("Hello World!\n");

    while(1) 
    {
        int tmp;
        if((tmp = drv_uart_getc()) != -1) {
            printf("tmp: %c %d\n", tmp, tmp);
        }
    }
    return 0;
}
