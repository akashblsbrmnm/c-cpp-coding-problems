#include <stdio.h>
#include <string.h>

char* strrev(char* str)
{
    char* s = str;
    char* start = str;
    char* end = str + strlen(str) - 1;

    while(start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return s;
}

int main()
{
    char* (*fp)(char*) = strrev;
    char str[] = "Hey!";
    printf("Reversed string: %s\n", fp(str));
}