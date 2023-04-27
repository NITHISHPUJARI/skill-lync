#include <stdio.h>

// Members are not ordered
typedef struct
{
  char a;   // 1 byte
  int  b;   // 4 bytes
  char c;   // 1 byte
} temp1;

//Members are ordered
typedef struct 
{
  int  b;   // 4 bytes
  char a;   // 1 byte
  char c;   // 1 byte
} temp2;

int main()
{
  printf("sizeof(structure temp1) = %lu\r\n", sizeof(temp1));
  printf("sizeof(structure temp2) = %lu\r\n", sizeof(temp2));
  return 0;
}