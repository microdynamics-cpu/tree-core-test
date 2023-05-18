#include <am.h>
#include <klib-macros.h>
#include <klib.h>

#define MEM_ADDR 0x80200000 // chiplink
// #define MEM_ADDR 0xFC000000
// #define MEM_ADDR 0x80020000
// #define SDRAM_ADDR 0xFCF00000
// #define ARR_SIZE (512 * 1024 * 1024 - 2 * 1024 * 1024)
#define ARR_SIZE (6 * 1024 * 1024)
// #define ARR_SIZE (2 * 1024)
// #define ARR_SIZE (30)
#define STEP 65536
// #define STEP 16
// #define STEP 1
// #define ARR_SIZE 0x10
// uint64_t mem_data[ARR_SIZE];
// uint64_t sdram_data[ARR_SIZE];

int main(const char *args)
{
    putstr("start test...\n");
    uint64_t *mem_data = (void *)(MEM_ADDR);
    // uint64_t *sdram_data = (void *)(SDRAM_ADDR);
    uint64_t len = ARR_SIZE / sizeof(uint64_t);
    for (int i = 0; i < len; ++i)
    {
       if (i % STEP == 0) {
            printf("[mem data][1] cnt: %d(%x), addr: %p\n", i, i, (mem_data + i));
        }
        mem_data[i] = i;
    }
    putstr("mem tests prepared\n");

    for (int i = 0; i < len; ++i)
    {
        if (i % STEP == 0) {
            printf("[mem data][2] cnt: %d(%x), addr: %p\n", i, i, (mem_data + i));
        }
        
        if (mem_data[i] != i) {
            printf("[mem data] i: %lx mem_data[i]: %lx xor: %lx addr: %p\n", i, mem_data[i], i ^ mem_data[i], (mem_data + i));
        }
        assert(mem_data[i] == i);
    }
    putstr("mem tests passed!!\n");

    // for (int i = 0; i < len; ++i)
    // {
    //     sdram_data[i] = i;
    // }
    // putstr("sdram tests prepared\n");

    // for (int i = 0; i < len; ++i)
    // {
    //     assert(sdram_data[i] == i);
    // }

    // putstr("sdram tests passed!!\n");
    // putstr("all tests passed!!\n");
    return 0;
}
