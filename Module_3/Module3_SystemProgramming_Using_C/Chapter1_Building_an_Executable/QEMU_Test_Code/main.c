/*
 * main.c
 *  Project Setup: stm32vldiscovery, Cortex-M3 arch, STM32F100RBTx chip
 */
 #include <stdint.h>
// Message defines:
const char Hello_World_Msg[] 	= "Hello World!\r\n\0";

// Some Variables : 
int TickCount;					// Integer Variables
const int MaxTickCount = 1000;	// Constant Variable
static int MainProcStatus = 10; // Static Int Variable 

// Function prototype
int ProcTick(void);

/*************************************************
* Main code starts from here
*************************************************/
int32_t main(void)
{
	static int i;

	while(1)
	{
		//LOOP
		ProcTick();
	}
	// Should never reach here
	return 0;
}
int ProcTick(void){
	TickCount++;
	if (MaxTickCount < TickCount){
		TickCount = 0;
	}
}