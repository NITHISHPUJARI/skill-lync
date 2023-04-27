#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] )
{
  int count = 0;
  for(int i = 0; i < 4; i++)
  {
    printf("Count Value: %d\r\n", count);
    count += 1;
  }
  return 0;
}