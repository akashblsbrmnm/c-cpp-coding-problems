#include <stdio.h>
#include <stdlib.h>

int power(int base, int exp)
{
    if(exp == 0) return 1;

    if(exp == 1) return base;

    return base * power(base, exp-1);
}

int main()
{
    int ret = power(2,5);
    printf("Power of 2^5 is: %d\n", ret);
}