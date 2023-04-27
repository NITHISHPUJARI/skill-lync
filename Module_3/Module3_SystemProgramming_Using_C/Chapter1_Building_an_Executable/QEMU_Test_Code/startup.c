/*--------------------------------------------------------------/
/  Startup Module for STM32F100 Microcontrollers                /
/                                                               /
/ * This module defines vector table, startup code, default     /
/   exception handlers, main stack and miscellanous functions.  /
/--------------------------------------------------------------*/

#include <stdint.h>

#define	VTOR		(*(volatile uint32_t*)0xE000E010)

extern uint32_t _flash_sdata;       // Defined in Linker file: _flash_sdata = LOADADDR(.data);
extern uint32_t _sram_sdata;
extern uint32_t _sram_edata;
extern uint32_t _sram_sbss;
extern uint32_t _sram_ebss;
extern uint32_t _sram_stacktop;     // Defined in Linker file : _sram_stacktop = ORIGIN(SRAM) + LENGTH(SRAM);

/*--------------------------------------------------------------------/
/ Declareations                                                       /
/--------------------------------------------------------------------*/

/* Section address defined in linker script */
extern long _sidata[], _sdata[], _edata[], _sbss[], _ebss[], _endof_sram[];
extern int main (void);

/* Exception/IRQ Handlers */

/* Exception/IRQ Handlers */
void   Reset_Handler (void)		__attribute__ ((noreturn, naked));
void   NMI_Handler(void) __attribute__ ((weak, alias ("IRQ_Trap")));
void   HardFault_Handler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   MemManage_Handler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   BusFault_Handler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   UsageFault_Handler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   SVC_Handler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   DebugMon_Handler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   PendSV_Handler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   SysTick_Handler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   WWDG_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   PVD_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   TAMPER_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   RTC_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   FLASH_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   RCC_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   EXTI0_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   EXTI1_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   EXTI2_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   EXTI3_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   EXTI4_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   DMA1_Channel1_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   DMA1_Channel2_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   DMA1_Channel3_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   DMA1_Channel4_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   DMA1_Channel5_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   DMA1_Channel6_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   DMA1_Channel7_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   ADC1_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   EXTI9_5_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   TIM1_BRK_TIM15_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   TIM1_UP_TIM16_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   TIM1_TRG_COM_TIM17_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   TIM1_CC_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   TIM2_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   TIM3_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   TIM4_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   I2C1_EV_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   I2C1_ER_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   I2C2_EV_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   I2C2_ER_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   SPI1_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   SPI2_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   USART1_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   USART2_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   USART3_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   EXTI15_10_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   RTCAlarm_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   CEC_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap"))); 
void   TIM6_DAC_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap")));
void   TIM7_IRQHandler(void)__attribute__ ((weak, alias ("IRQ_Trap"))); 


/*--------------------------------------------------------------------/
/ Exception Vector Table for STM32F100                                /
/--------------------------------------------------------------------*/
__attribute__ ((section(".vectors"), used))
void (* const  _exceptions[])(void) =
{
	(void (*)(void))((uint32_t)&_sram_stacktop),// Reset value of the Main Stack Pointer
	Reset_Handler, 
	NMI_Handler,                  /*!< NMI Handler                              */
	HardFault_Handler,            /*!< Hard Fault Handler                       */
	MemManage_Handler,            /*!< MPU Fault Handler                        */
	BusFault_Handler,             /*!< Bus Fault Handler                        */
	UsageFault_Handler,           /*!< Usage Fault Handler                      */
	0,0,0,0,                      /*!< Reserved                                 */
	SVC_Handler,                  /*!< SVCall Handler                           */
	DebugMon_Handler,             /*!< Debug Monitor Handler                    */
	0,                            /*!< Reserved                                 */
	PendSV_Handler,               /*!< PendSV Handler                           */
	SysTick_Handler,              /*!< SysTick Handler                          */
	/*----------External Exceptions---------------------------------------------*/
	WWDG_IRQHandler,              /*!<  0: Window Watchdog                      */
	PVD_IRQHandler,               /*!<  1: PVD through EXTI Line detect         */
	TAMPER_IRQHandler,            /*!<  2: Tamper                               */
	RTC_IRQHandler,               /*!<  3: RTC                                  */
	FLASH_IRQHandler,             /*!<  4: Flash                                */
	RCC_IRQHandler,               /*!<  5: RCC                                  */
	EXTI0_IRQHandler,             /*!<  6: EXTI Line 0                          */
	EXTI1_IRQHandler,             /*!<  7: EXTI Line 1                          */
	EXTI2_IRQHandler,             /*!<  8: EXTI Line 2                          */
	EXTI3_IRQHandler,             /*!<  9: EXTI Line 3                          */
	EXTI4_IRQHandler,             /*!< 10: EXTI Line 4                          */
	DMA1_Channel1_IRQHandler,     /*!< 11: DMA1 Channel 1                       */
	DMA1_Channel2_IRQHandler,     /*!< 12: DMA1 Channel 2                       */
	DMA1_Channel3_IRQHandler,     /*!< 13: DMA1 Channel 3                       */
	DMA1_Channel4_IRQHandler,     /*!< 14: DMA1 Channel 4                       */
	DMA1_Channel5_IRQHandler,     /*!< 15: DMA1 Channel 5                       */
	DMA1_Channel6_IRQHandler,     /*!< 16: DMA1 Channel 6                       */
	DMA1_Channel7_IRQHandler,     /*!< 17: DMA1 Channel 7                       */
	ADC1_IRQHandler,              /*!< 18: ADC1                                 */
	0,                            /*!< 19: USB High Priority or CAN1 TX         */
	0,                            /*!< 20: USB Low  Priority or CAN1 RX0        */
	0,                            /*!< 21: CAN1 RX1                             */
	0,                            /*!< 22: CAN1 SCE                             */
	EXTI9_5_IRQHandler,           /*!< 23: EXTI Line 9..5                       */
	TIM1_BRK_TIM15_IRQHandler,    /*!< 24: TIM1 Break and TIM15                 */
	TIM1_UP_TIM16_IRQHandler,     /*!< 25: TIM1 Update and TIM16                */
	TIM1_TRG_COM_TIM17_IRQHandler,/*!< 26: TIM1 Trigger and Commutation and TIM17        */
	TIM1_CC_IRQHandler,           /*!< 27: TIM1 Capture Compare                 */
	TIM2_IRQHandler,              /*!< 28: TIM2                                 */
	TIM3_IRQHandler,              /*!< 29: TIM3                                 */
	TIM4_IRQHandler,              /*!< 30: TIM4                                 */
	I2C1_EV_IRQHandler,           /*!< 31: I2C1 Event                           */
	I2C1_ER_IRQHandler,           /*!< 32: I2C1 Error                           */
	I2C2_EV_IRQHandler,           /*!< 33: I2C2 Event                           */
	I2C2_ER_IRQHandler,           /*!< 34: I2C2 Error                           */
	SPI1_IRQHandler,              /*!< 35: SPI1                                 */
	SPI2_IRQHandler,              /*!< 36: SPI2                                 */
	USART1_IRQHandler,            /*!< 37: USART1                               */
	USART2_IRQHandler,            /*!< 38: USART2                               */
	USART3_IRQHandler,            /*!< 39: USART3                               */
	EXTI15_10_IRQHandler,         /*!< 40: EXTI Line 15..10                     */
	RTCAlarm_IRQHandler,          /*!< 41: RTC Alarm through EXTI Line          */
	CEC_IRQHandler,               /*!< 42: HDMI-CEC                             */  
	0,0,0,0,0,0,                  /*!< Reserved                                 */
	0,0,0,0,0,                    /*!< Reserved                                 */ 
	TIM6_DAC_IRQHandler,           /*!< 54: TIM6 and DAC underrun                */
	TIM7_IRQHandler               /*!< 55: TIM7                                 */
};

/*---------------------------------------------------------------------/
/ Reset_Handler is the start-up code. It configures processor core,    /
/ system clock generator, memory controller, then initialize .data     /
/ and .bss sections and then start main().                             /
/---------------------------------------------------------------------*/
void Reset_Handler (void)
{
	/* Set interrupt vector table address */
	VTOR = (uint32_t)_exceptions;
    /* Copy the data segment from flash to sram */
    uint32_t *pSrc = &_flash_sdata;   
    uint32_t *pDest = &_sram_sdata;
    while(pDest < &_sram_edata)
    {
        *pDest = *pSrc;
        pDest++;
        pSrc++;
    }
    /* Zero initialize the bss segment in sram */
  	  pDest = &_sram_sbss;
    while(pDest < &_sram_ebss)
    {
        *pDest = 0;
        pDest++;
    }
	/* Start main() with MSP and privileged mode */
	main();
	  /* main() isn't supposed return 
    * - if it does, we need to identify this
    * for now, we'll loop infintely
    */
	for (;;) ;
}



/*--------------------------------------------------------------------/
/ Unexpected Exception/IRQ Trap                                       /
/--------------------------------------------------------------------*/

void Exception_Trap (void)
{
	for (;;) ;
}


void IRQ_Trap (void)
{
	for (;;) ;
}
