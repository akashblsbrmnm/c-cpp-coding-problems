#include <stdio.h>
#include <stdlib.h>

int my_power(int base, int exp);

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d", &a);
    scanf("%d", &b);
    int ret = my_power(a,b);
    printf("Result is %d\n", ret);
    return 0;
}

int my_power(int base, int exp)
{
    if (exp == 0) return 1;
    return (base * my_power(base, exp - 1));
}