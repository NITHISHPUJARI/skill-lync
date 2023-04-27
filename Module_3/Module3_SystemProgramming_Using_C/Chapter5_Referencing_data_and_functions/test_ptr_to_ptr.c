#include <stdio.h>
 
int main () {

   int  var;
   int  *ptr;
   int  **pptr;

   var = 4000;

   /* take the address of var */
   ptr = &var;

   /* take the address of ptr using address of operator & */
   pptr = &ptr;

   /* take the value using pptr */
   printf("Value of var = %d\r\n", var );
   printf("Value available at *ptr = %d\r\n", *ptr );
   printf("Value available at **pptr = %d\r\n", **pptr);

   return 0;
}