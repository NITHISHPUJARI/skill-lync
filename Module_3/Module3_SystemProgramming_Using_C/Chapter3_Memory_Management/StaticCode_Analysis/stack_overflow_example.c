
#include <stdio.h>

static void Func(char *ptrArr){
    char DataArry[1000]= "From Func";
    static int FuncCount = 0;
    FuncCount++;
    printf("%s[Instance : %d] Inside Func()\r\n", ptrArr,FuncCount);
    Func(DataArry);
}

int main(){
    char MainArr[100] = "From Main";
    Func(MainArr);
    return 0;
}