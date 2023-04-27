#include <stdio.h>
#include <stdint.h>

// Sample usage on hardware with actual usage with Device Register:
// Uart0 UARTCTL Reg Addr for device register map 
#define UART0_UARTCTL_REG (*((volatile uint32_t*)  0x4000C030))

// Structure defining the register UARTCTL:
typedef struct
{
    unsigned int UARTEN     : 1;    // UARTEN   Bit  0
    unsigned int SIREN      : 1;    // SIREN    Bit 1
    unsigned int SIRLP      : 1;    // SIRLP    Bit 2
    unsigned int reserved1  : 4;    // Reserved Bits 3: 6
    unsigned int LBE        : 1;    // LBE      Bit 7
    unsigned int TXE        : 1;    // TXE      Bit 8
    unsigned int RXE        : 1;    // RXE      Bit 9
    unsigned int reserved2  : 22;   // Reserved Bits 10 : 31
} UARTCTL_BITS;

// Union of Int and Structure Reg Bits 
typedef union
{
    unsigned int UARTCTL_Reg;
    UARTCTL_BITS BitsRep;
} UARTCTL_reg_t;

// Print 32 Bit binary representation:
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");

    printf("\r\n");
}

int main()
{
    UARTCTL_reg_t RegData;
    printf("Bitfeild Device Register : UARTCTL\r\n");
    printf("Size of UARTCTL_reg_t = %lu bytes\n", sizeof(UARTCTL_reg_t));
    
    printf("\r\n");
    
    // Reset the value of register union:
    RegData.UARTCTL_Reg = 0;
    printf("Reset Value of RegData.UARTCTL_Reg\r\n");
    printf("RegData.UARTCTL_Reg =\t0b");
    bin(RegData.UARTCTL_Reg);
    
    printf("\r\n");

    // Set the bits 9, 8 & 0​
    RegData.BitsRep.RXE = 1;
    RegData.BitsRep.TXE = 1;
    RegData.BitsRep.UARTEN = 1;

    printf("After setting bits 9, 8, 0 Value of RegData.UARTCTL_Reg\r\n");
    printf("RegData.UARTCTL_Reg =\t0b");
    bin(RegData.UARTCTL_Reg);

    // Sample usage on hardware with actual usage with Device Register:
    // To write the new data to Device register:
    // Use the pointer defination we got from previous section:
    UART0_UARTCTL_REG = RegData.UARTCTL_Reg; 

    return 0;
}