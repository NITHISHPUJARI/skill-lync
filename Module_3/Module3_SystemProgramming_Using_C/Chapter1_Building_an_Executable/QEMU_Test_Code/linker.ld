/*
******************************************************************************
**
** @file        : linker.ld
**
**  Abstract    : Linker script for STM32VLDISCOVERY Board embedding STM32F100RBTx Device from stm32f1 series
**                      128Kbytes FLASH
**                      8Kbytes RAM
**
**                Set heap size, stack size and stack location according
**                to application requirements.
**
**                Set memory bank area and size if external memory is used
**
**  Target      : STMicroelectronics STM32
**
**  Distribution: The file is distributed as is, without any warranty
**                of any kind.
**
******************************************************************************
** @attention
**
** Copyright (c) 2023 STMicroelectronics.
** All rights reserved.
**
** This software is licensed under terms that can be found in the LICENSE file
** in the root directory of this software component.
** If no LICENSE file comes with this software, it is provided AS-IS.
**
******************************************************************************
*/


MEMORY {
        FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
        SRAM  (rw) : ORIGIN = 0x20000000, LENGTH = 8K
}

STACK_SIZE = 0x1F40; /* 8kB */

/* Section Definitions */
SECTIONS {
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
