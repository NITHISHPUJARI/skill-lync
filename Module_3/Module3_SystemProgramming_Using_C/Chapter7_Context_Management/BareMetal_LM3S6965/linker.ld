/* This linkerscript is derived from the memory layout of TI Stellaris LM3S6965
 * Refer Refer: http://www.ti.com/lit/ds/symlink/lm3s6965.pdf Table 2-4
 */

MEMORY {
        FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K
        SRAM  (rw) : ORIGIN = 0x20000000, LENGTH = 64K
}

STACK_SIZE = 0xFA00; /* 64kB */

/* Section Definitions */
SECTIONS {
        . = 0x00000000;
        .text : {
            KEEP(*(.vectors))
            *(.startup)
            *(.text)
            *(.rodata)
            . = ALIGN(4);
            _etext = .;
        } > FLASH
        
        .data : {
            . = ALIGN(4);
            _sram_sdata = .;
            *(.data);
            . = ALIGN(4);
            _sram_edata = .;
        } > SRAM AT > FLASH

        _flash_sdata = LOADADDR(.data);

        .bss (NOLOAD):{
            . = ALIGN(4);
            _sram_sbss = .;
            *(.bss)
            *(COMMON)
            . = ALIGN(4);
            _sram_ebss = .;
        } > SRAM

        .stack (NOLOAD) :
        {
            . = . + STACK_SIZE;
        } > SRAM

        _sram_stacktop = ORIGIN(SRAM) + LENGTH(SRAM);
}
