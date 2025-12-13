#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int main() 
{
    int x = 7, y=90;
    swap(&x, &y);
    printf("x = %d\t y= %d\n", x, y);
}