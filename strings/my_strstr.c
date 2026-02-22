#include <stdio.h>
#include <stdio.h>

char* my_strstr(const char* hay, const char* needle)
{
	if (!*needle) return (char*)hay;

	const char* h;
	const char* n;

	while (*hay)
	{
		h = hay;
		n = needle;

		while (*h && *n && *h == *n)
		{
			h++;
			n++;
		}

		if (!*n)
			return (char*)hay;

		hay++;
	}

	return NULL;
}

int main()
{
    char str1[] = "Hello world hehe";
    char str2[] = "world";
    
    char *ptr = my_strstr(str1, str2);
    if( ptr != NULL)
    {
        printf("str2 found: %s\n", ptr);
    }

    return 0;
}