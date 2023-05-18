#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#define FB_ADDR 0x1c000000
#define VGA_CTRL_ADDR 0x10002000
#define VGA_FB_ADDR 0x81000000
#define VGA_REG_CTRL *((volatile uint32_t *)(VGA_CTRL_ADDR))
#define VGA_REG_BASE *((volatile uint32_t *)(VGA_CTRL_ADDR + 4))
#define VGA_REG_OFST *((volatile uint32_t *)(VGA_CTRL_ADDR + 8))

int main()
{
    // putstr("config VGA module\n");
    // VGA_REG_CTRL = 0;
    // VGA_REG_BASE = VGA_FB_ADDR;
    // VGA_REG_OFST = VGA_FB_ADDR - FB_ADDR;

    *(uint32_t *)(VGA_CTRL_ADDR) = 0;
    volatile uint32_t write_mode = *(uint32_t *)(VGA_CTRL_ADDR);
    printf("mode: %d\n", write_mode);

    *(uint32_t *)(VGA_CTRL_ADDR + 4) = VGA_FB_ADDR;
    *(uint32_t *)(VGA_CTRL_ADDR + 8) = VGA_FB_ADDR - FB_ADDR;

    volatile uint32_t write_base = *(uint32_t *)(VGA_CTRL_ADDR + 4);
    printf("base: %d\n", write_base);

    volatile uint32_t write_ofst = *(uint32_t *)(VGA_CTRL_ADDR + 8);
    printf("offset: %d\n", write_ofst);

    // putstr("config end\n");
    return 0;
}
