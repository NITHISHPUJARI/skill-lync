#include <stdio.h>

// Simple representation of the date
struct Simpledate
{
    unsigned int Date;   // 4 Bytes
    unsigned int Month;  // 4 Bytes
    unsigned int Year;   // 4 Bytes
};


// Space optimized representation of the date
struct date
{
    // Date -> between 0 and 31,
    // so 5 bits are sufficient
    unsigned int Date : 5;
    //  Month has value between 0 and 15,
    // so 4 bits are sufficient
    unsigned int Month : 4;
    // Year
    unsigned int Year; // 4 Bytes
};

int main()
{
    printf("Simple Date representation\r\n");
    printf("Size of Simpledate is %lu bytes\n", sizeof(struct Simpledate));
    struct Simpledate Sdt = {31, 12, 2014};
    printf("Date is %d/%d/%d\r\n", Sdt.Date, Sdt.Month, Sdt.Year);

    printf("\r\n");
    
    printf("Bitfeild Date representation\r\n");
    printf("Size of date is %lu bytes\n", sizeof(struct date));
    struct date dt = {31, 12, 2014};
    printf("Date is %d/%d/%d\r\n", dt.Date, dt.Month, dt.Year);
    return 0;
}
