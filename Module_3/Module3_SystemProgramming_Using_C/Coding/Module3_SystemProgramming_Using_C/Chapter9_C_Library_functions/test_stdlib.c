#include <stdio.h>
#include <stdlib.h> // Standard Lib include

// compare function used for search and sort function
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void f1(void)
{
    printf("Function 1\r\n");
}

void f2(void)
{
    printf("Function 2\r\n");
}

int main()
{
    printf("Conversion Functions:\r\n");
    printf("---------atof-----------------\r\n");
    char str[10] = "3.14";
    printf("The value is %f\r\n", atof(str));
    printf("------------------------------\r\n");

    printf("---------atoi-----------------\r\n");
    char str1[10] = "55";
    printf("The value is %d\r\n", atoi(str1));
    printf("------------------------------\r\n");

    printf("---------atol-----------------\r\n");
    char str2[10] = "55345323";
    printf("The value is %ld\r\n", atol(str2));
    printf("------------------------------\r\n");

    printf("---------atoll-----------------\r\n");
    char str3[20] = "55345323218721";
    printf("The value is %lld\r\n", atoll(str3));
    printf("------------------------------\r\n");

    printf("---------strtod---------------\r\n");
    char str4[20] = "123 Random string";
    char *endptr;
    printf("The value is %lf\r\n", strtod(str4, &endptr));
    printf("String is %s\r\n", endptr);
    printf("------------------------------\r\n");

    printf("---------strtoll--------------\r\n");
    char str6[30] = "123456789";
    printf("The value is %lld\r\n", strtoll(str6, NULL, 10));
    printf("------------------------------\r\n");

    printf("---------strtoul--------------\r\n");
    char str7[30] = "123456789";
    printf("The value is %lu\r\n", strtoul(str7, NULL, 10));
    printf("------------------------------\r\n");

    printf("---------strtoull-------------\r\n");
    char str8[30] = "123456789";
    printf("The value is %llu\n", strtoull(str8, NULL, 10));
    printf("------------------------------\r\n");

    printf("\r\nSearch Function:\r\n");
    printf("---------bsearch--------------\r\n");
    int arr[] = {34, 45, 23, 56, 12};
    int key = 23;
    int *i;

    i = (int *)bsearch(&key, arr, 5, sizeof(int), cmp);
    if (i != NULL)
        printf("Found\r\n");
    else
        printf("Not found\r\n");
    printf("------------------------------\r\n");

    printf("\r\nSort Function:\r\n");
    printf("---------qsort----------------\r\n");
    int x[] = {34, 45, 23, 56, 12};
    int j;

    qsort(x, 5, sizeof(int), cmp);
    for (j = 0; j < 5; j++)
        printf("%d\r\n", x[j]);
    printf("------------------------------\r\n");

    printf("\r\nMathematical Function:\r\n");
    printf("---------abs------------------\r\n");
    printf("abs(-1) = %d\r\n", abs(-1));
    printf("------------------------------\r\n");

    printf("---------labs-----------------\r\n");
    printf("labs(-12345678912) = %ld\r\n", labs(-12345678912));
    printf("------------------------------\r\n");

    printf("---------llabs---------------\r\n");
    printf("llabs(-1234567891212344) = %lld\r\n", llabs(-1234567891212344));
    printf("------------------------------\r\n");

    printf("---------div------------------\r\n");
    div_t resultDiv;
    resultDiv = div(5, 3);
    printf("The result of division of 5 and 3\r\n%d is quotient and %d is the remainder\r\n", resultDiv.quot, resultDiv.rem);
    printf("------------------------------\r\n");

    printf("---------ldiv-----------------\r\n");
    ldiv_t resultLdiv;
    resultLdiv = ldiv(551245155, 3541525);
    printf("The result of division is\r\n%ld is quotient and %ld is the remainder\r\n", resultLdiv.quot, resultLdiv.rem);
    printf("------------------------------\r\n");

    printf("\r\nProcess Controll:\r\n");
    printf("---------atexit---------------\r\n");
    printf("Hello\r\n");
    atexit(f1);
    atexit(f2);
    printf("------------------------------\r\n");

    printf("---------exit-----------------\r\n");
    printf("Done with Demo Bye Bye!!\r\n");
    exit(0);
    printf("After quick exit\r\n");

    return 0;
}
