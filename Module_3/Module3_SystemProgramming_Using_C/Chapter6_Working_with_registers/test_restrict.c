// C program to use restrict keyword.
#include <stdio.h>

void copyArray(int n, int *restrict p, int *restrict q)
{
	while (n-- > 0)
	{
		*p++ = *q++;
	}
}

void FuncCopyArray(int n, int *p, int *q)
{
	while (n-- > 0)
	{
		*p++ = *q++;
	}
}

int main(void)
{
	int Arr[5] = {0, 1, 2, 3, 4};
	int DestArr[5];
	int DestArr2[5];
	int ArrElements = 5;

	// // Copy Arr to DestArr:
	// FuncCopyArray(ArrElements, DestArr, Arr);
	// copyArray(ArrElements, DestArr2, Arr);
	
	// printf("Display Data:\r\n");
	// for (int i = 0; i < ArrElements; i++)
	// {
	// 	printf("Arr[%d] = %d\tDestArr[%d] = %d\t DestArr2[%d] = %d\r\n", i, Arr[i], i, DestArr[i], i, DestArr2[i]);
	// }

	return 0;
}
