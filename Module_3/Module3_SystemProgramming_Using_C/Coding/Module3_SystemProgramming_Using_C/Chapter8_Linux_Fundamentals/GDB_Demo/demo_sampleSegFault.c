#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t get_len( const char *s )
{
  return strlen( s );
}

int main( int argc, char *argv[] )
{
  const char *a = NULL;

  printf( "size of a = %lu\r\n", get_len(a) );

  return 0;
}