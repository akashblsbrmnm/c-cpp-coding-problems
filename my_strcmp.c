#include <stdio.h>

int my_strcmp(char *s1, char* s2)
{
	while(*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

int my_strncmp(char *s1, char* s2, int n)
{
	while(n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if(n == 0) return 0;
	return *s1 - *s2;
}

int main()
{
	if(my_strcmp("Apple", "APPLE") == 0)
	{
		printf("Both strings are equal\n");
	}
	else
	{
		printf("Both are not same\n");
	}
	

	if(my_strncmp("Apple", "Application", 3) == 0)
	{
		printf("Both strings are equal\n");
	}
	else
	{
		printf("Both are not same\n");
	}
	return 0;
}