#include <stdio.h>   
  
int main ()  
{  
 
    int arr[10];  
    int pos, i, num;  
    printf (" \n Enter the number of elements in the array: \n ");  
    scanf (" %d", &num);  
      
    printf (" \n Enter %d elements in array: \n ", num);  
      
    for (i = 0; i < num; i++ )
    {   
        printf (" arr[%d] = ", i);  
        scanf (" %d", &arr[i]);  
    }  
      
    printf( " Define the position where you want to delete: \n ");  
    scanf (" %d", &pos);  
     
      
        for (i = pos - 1; i < num; i++)  
        {  
            arr[i] = arr[i+1]; 
        }  
          
        printf (" \n Final Array: \n");  
          
     
        for (i = 0; i< num - 1; i++)  
        {  
            printf (" arr[%d] = ", i);  
            printf (" %d \n", arr[i]);  
        }  
      
    return 0;  
}  
