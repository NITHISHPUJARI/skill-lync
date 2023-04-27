#include <stdio.h>

int main()
{
    int Fred[72] = {0};
    size_t x;
    for (x = 0; x < 84; ++x)
    {
        Fred[x] = x;
    }
}