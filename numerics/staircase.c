#include <stdio.h>

void leftStaircase(int n);
void rightStaircase(int n);
void centeredStaircase(int n);

int main()
{
    int n = 0;
    printf("Enter height: ");
    scanf("%d", &n);
    leftStaircase(n);
    rightStaircase(n);
    centeredStaircase(n);
    return 0;
}

void leftStaircase(int n)
{
    printf("Left aligned staricase:\n");
    for(int i = 0; i<n; i++)
    {
        for(int h = 0; h <= i; h++)
        {
            printf("#");
        }
        printf("\n");
    }
}

void rightStaircase(int n)
{
    printf("Right aligned staricase:\n");
    for(int i = 1; i <= n; i++)
    {
        int hashes = i;
        int spaces = n -i;
        for(int s = 0; s < spaces; s++)
            printf(" ");
        
        for(int h = 0; h < hashes; h++)
            printf("#");

        printf("\n");
    }
}

void centeredStaircase(int n)
{
    printf("Centered aligned staricase:\n");
    for(int i = 1; i <= n; i++)
    {
        int hashes = (2*i) - 1;
        int spaces = n -i;
        for(int s = 0; s < spaces; s++)
            printf(" ");
        
        for(int h = 0; h < hashes; h++)
            printf("*");

        printf("\n");
    }
}