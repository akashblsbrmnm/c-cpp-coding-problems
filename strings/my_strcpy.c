#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_strcpy(char *dest, char*src);
void my_strncpy(char* dest, char* src, int size);

int main()
{
    char dest_string[100];
    char src_string[] = "Apple";
	char *dest_string_n = malloc(strlen(src_string) + 1);

    my_strcpy(dest_string, src_string);
	my_strncpy(dest_string_n, src_string, sizeof(dest_string_n));
    printf("String: %s\n", dest_string);
    printf("String: %s\n", dest_string_n);
	free(dest_string_n);
    
    return 0;
}

void *my_strcpy(char *dest, char*src)
{
	while(*src!='\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
}

void my_strncpy(char* dest, char* src, int n)
{
	while(n && *src!='\0')
	{
		*dest++ = *src++;
		n--;
	}
	*dest = '\0';
}
