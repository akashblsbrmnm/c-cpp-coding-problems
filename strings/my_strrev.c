#include <stdio.h>
#include <stdbool.h>

void string_reverse(char *s)
{
	char* end = s;
	char* start = s;
	while (*end != '\0') end++;
	end--;

	while(s < end)
	{
		char temp = *s;
		*s = *end;
		*end = temp;
		s++;
		end--;
	}
	printf("The reverse string is: %s\n", start);
	return;
}

void reverse_string(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        // Swap characters at start and end
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move pointers towards the center
        start++;
        end--;
    }
}


bool is_palindrome(char *s)
{
	char* end = s;
	while(*end != '\0') end++;
	end--;
	while(s < end)
	{
		if(*s != *end) return false;
		s++;
		end--;
	}
	return true;
}

int main()
{
    char str[] = "malayalam";
    string_reverse(str);
    if(is_palindrome(str) == true)
    {
        printf("string is palindrome.\n");
    }
    else
    {
        printf("The string is not palindrome.\n");
    }
    return 0;
}