.global _start
_start:
# UART_INIT:
    lui	a4,0x10000
    lbu	a5,3(a4) # 10000003 <_entry_offset+0x10000003>
    ori	a5,a5,-128
    andi	a5,a5,255
    sb	a5,3(a4)
    li	a5,13
    sb	a5,0(a4)
    li	a5,3
    sb	a5,3(a4)
DATA_INIT:
    li a0, 72
    li s0, 0x0
    li s1, 0xf
LOOP:
    addi s0, s0, 1
    jal ra, PUTC
    ble s0, s1, LOOP
END:
    j END

PUTC:
    lui a4,0x10000
WHILE:
    lbu	a5,5(a4) # 10000005 <_start-0x1ffffffb>
    andi a5,a5,32
    beqz a5, WHILE
    sb a0,0(a4)
    ret

