#include <stdio.h>
void add(int a, int b)
{
	printf("Addition is %d\r\n", a+b);
}
void subtract(int a, int b)
{
	printf("Subtraction is %d\r\n", a-b);
}
void multiply(int a, int b)
{
	printf("Multiplication is %d\r\n", a*b);
}

int main()
{
	// fun_ptr_arr is an array of function pointers
	void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
	unsigned int ch, a = 15, b = 10;

    printf("Variable values:\r\n a = %d\r\n b = %d\r\n",a, b);

	printf("Enter Choice:\r\n 0 -> Addition\r\n 1 -> Subtract\r\n 2 -> Multiply\r\n");
	scanf("%d", &ch);
    printf("Choice = %d\r\n", ch);
	if (ch > 2) return 0;

	(*fun_ptr_arr[ch])(a, b);

	return 0;
}
