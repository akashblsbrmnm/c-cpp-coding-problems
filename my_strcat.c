#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strcat(char* dest, const char* src)
{
    char *ptr = dest;
    while(*ptr)
    {
        ptr++;
    }

    while(*src)
    {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}

int main()
{
    char dest[] = "hello";
    char src[] = "world";

    my_strcat(dest, src);
    printf("concatenated buffer: %s\n", dest);
    return 0;
}