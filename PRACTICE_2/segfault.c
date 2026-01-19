// Demonstrate and run a program to create a segfault.
#include <stdio.h>
int main()
{
    char* str = "Hello, World!";
    str[0] = 'h';
    printf("%s\n", str);
    return 0;
}
