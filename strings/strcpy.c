#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

char* my_strcpy(char* dest, const char* src)
{
	const char *s = src;
	char* d = dest;
	
	while(*s)
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return dest;
}

int main()
{
	char str[] = "Hello";
    size_t size = 0;
    char *s = str;
    while(*s) {
        s++;
        size++;
    }
	char* destination = malloc(size + 1);
	
	my_strcpy(destination, str);
    printf("Copied string: %s\n", destination);
    free(destination);
    return 0;
}