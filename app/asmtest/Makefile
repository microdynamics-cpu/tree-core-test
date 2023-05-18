.PHONY: all

GCC = riscv64-linux-gnu-
AS = $(GCC)as
LD = $(GCC)ld
OBJDUMP = $(GCC)objdump
OBJCOPY = $(GCC)objcopy
LDFLAGS += -T flash.ld
APP ?= hello
APP_ALL = $(APP)-asm

all: $(APP).s
	$(AS) $(APP).s -o $(APP_ALL).o
	$(LD) $(LDFLAGS) $(APP_ALL).o -o $(APP_ALL).elf
	$(OBJDUMP) -d $(APP_ALL).elf > $(APP_ALL).txt
	$(OBJCOPY) -S -O binary $(APP_ALL).elf $(APP_ALL).bin

clean:
	rm -rf $(APP_ALL).elf $(APP_ALL).txt $(APP_ALL).bin
