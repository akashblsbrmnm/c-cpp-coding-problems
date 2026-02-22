#include <stdio.h>

int main()
{
    for(int i=1; i<=100; i++)
    {
        int fizz = (i % 3 == 0);
        int buzz = (i % 5 == 0);

        if(fizz && buzz)
        {
            printf("FizzBuzz");
        }
        else if(fizz)
        {
            printf("Fizz");
        }
        else if(buzz)
        {
            printf("Buzz");
        }
        else
        {
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}