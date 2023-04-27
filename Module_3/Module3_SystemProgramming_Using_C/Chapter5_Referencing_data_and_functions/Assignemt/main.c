#include <stdint.h>
#include "irq.h"
#include "nvic.h"
#include "sysctl.h"
#include "systick.h"
#include "uart_drv.h"
#include "serial_print.h"
#include "StateMachine.h"

/* Current State :*/
static volatile int CurrentEvent;

// Create new state machine object
stateMachine_t stateMachine;

// Main Timer Callback:
void main_timer_proc()
{
    serial_puts("main_timer_proc()-> Callback Called!!\r\n");
    serial_puts("State is now -:");
    serial_puts(StateMachine_GetStateName(stateMachine.currState));
    serial_puts("\r\n");
}

// This Function Change the CurrentEvent on timer callback.
void StateMachineTimerProc()
{
    serial_puts("StateMachineTimerProc()-> Callback Called!!\r\n");

    // Change Event
    switch (CurrentEvent)
    {
    case EV_BUTTON_PUSHED:
        CurrentEvent = EV_TIME_OUT;
        serial_puts("EV_TIME_OUT\r\n");
        break;
    case EV_TIME_OUT:
    case EV_ANY:
    case EV_NONE:
        CurrentEvent = EV_BUTTON_PUSHED;
        serial_puts("EV_BUTTON_PUSHED\r\n");
        break;
    }
    StateMachine_RunIteration(&stateMachine, CurrentEvent);
}

int main(void)
{
    const char *start_msg = "\r\nApp Started\r\n";
    uint32_t clk_cfg1, clk_cfg2;

    // Init thr Statemachine:
    StateMachine_Init(&stateMachine);

    // Init the Current Event:
    CurrentEvent = EV_TIME_OUT;

    // Register the timer callback :
    Register_TimerCallback(&StateMachineTimerProc);

    /* Registert he timer Callback */
    Register_TimerCallback(&main_timer_proc);

    /* Let's now re-enable the interrupts*/
    irq_master_enable();

    /* Also, let's also turn on the UART0 interrupt */
    nvic_irq_enable(IRQ_UART0);

    /* Set the system clock to the PLL with the main oscillator as the source
     * with the crystal frequency set to 8 MHz.
     * Divide the PLL output clock frquency by a factor of 12.
     * Turn off the (unused) internal oscillator. This is to configure a system clock of 16.67 MHz.
     */
    clk_cfg1 = (SYSCTL_PLL_SYSCLK | SYSCTL_RCC_USESYSDIV | SYSCTL_RCC_SYSDIV_11 |
                SYSCTL_RCC_XTAL_8MHZ | SYSCTL_RCC_OSCSRC_MOSC | SYSCTL_RCC_IOSCDIS);
    clk_cfg2 = 0;

    sysctl_setclk(clk_cfg1, clk_cfg2);

    /* Let's set systick period to be 0.5 seconds =>
     * system clock frequency divided by 2.
     */
    systick_set_period_ms(500u);

    /* Let's enable the systick timer and it's interrupt */
    systick_irq_enable();
    systick_enable();

    /* Configure the uart to a baud-rate of 115200 */
    uart_init(UART_BAUD_115200);

    serial_puts(start_msg);

    serial_putchar('.');
    serial_putchar('.');
    serial_putchar('.');

    serial_puts("\r\nControl Handed to State Machine & Timer...\r\n");

    while (1)
        ;

    return 0;
}
