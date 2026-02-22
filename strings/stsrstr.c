#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char* my_strstr(const char* str, const char* key)
{

    for(const char *p = str; *p!='\0'; p++)
    {
        const char *h = p;
        const char *n = key;

        while(*h && *p && *h == *n)
        {
            h++;
            n++;
        }

        if(*n == '\0') return (char *)p;
    }

    return NULL;

}

char* remDup(char* str)
{
    bool freq[256] = { false };
    char* src = str;
    char* dest = str;

    while(*src)
    {
        char c = tolower((unsigned char)*src);
        if (!freq[(unsigned char)c])
        {
            freq[(unsigned char)c] = true;
            *dest = *src;
            dest++;
        }
        *src++;
    }
    *dest = '\0';
    return str;
}

char* my_strcpy(char* dest, const char* src)
{
    char* original_dest = dest;

    while (*src != '\0')
    {
        *dest++ = *src++;
    }
    *dest = '\0';

    return original_dest;
}

void printString(const char* str)
{
    for(const char*p = str; *p != '\0'; p++)
    {
        printf("%c", *p);
    }
    printf("\n");
}

void reverse_string(char *str)
{
    int left = 0;
    int right = strlen(str) - 1;

    while(left<right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        
        left++;
        right--;
    }
}

int main()
{
    char str[] = "Hello world";
    if(my_strstr(str, "Hao") != NULL)
    {
        printf("Found\n");
    }
    else{
        printf("Not found\n");
    }
    printString("Welcome :)");

    char str1[] = "ProgRamMing";
    printf("After removing duplicates: %s\n", remDup(str1));

    char str2[30];
    my_strcpy(str2, "hello");
    printf("After my_strcpy: %s\n", str2);

    return 0;
}