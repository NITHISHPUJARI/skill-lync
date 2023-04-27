#include <stdio.h>
int main()
{
	unsigned char DataArr[4] = {0x01, 0x00, 0x00, 0x00 };
    // char array is typecasted to an integer type.
    int DataInt = *(int *) DataArr; 
	printf("DataInt = %d\r\n", DataInt);
	return 0;
}
