#include <stdio.h>

struct item1  
{  
  char a;   // 1 byte  
  char b;   // 1 byte  
  int c;    // 4 bytes   
};

struct item2  
{  
  char a;   // 1 byte  
  int c;    // 4 bytes  
  char b;   // 1 byte   
};

// To avoid the structure padding.
// Use the #pragma pack(1) directive 
#pragma pack(1)  
struct item3
{  
    char a;  // 1 byte
    char b;  // 1 byte
    int  c;  // 4 byte
};  

// By using attribute
struct item4  
{  
    char a;  // 1 byte
    char b;  // 1 byte
    int  c;  // 4 bytes
}__attribute__((packed));;


int main()  
{  
   struct item1 data1; // variable declaration of the item1 type..
   struct item2 data2; // variable declaration of the item2 type..
   struct item3 data3; // variable declaration of the item3 type..  
   struct item4 data4; // variable declaration of the item4 type..  

   // Displaying the size of the structure student.  
   printf("The size of the item1 structure = %ld\r\n", sizeof(data1));  
   printf("The size of the item2 structure = %ld\r\n", sizeof(data2));  
   printf("The size of the item3 structure = %ld\r\n", sizeof(data3));  
   printf("The size of the item4 structure = %ld\r\n", sizeof(data4));  
   return 0;  
}  