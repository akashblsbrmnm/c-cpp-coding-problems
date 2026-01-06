#include <stdio.h>


char* my_strtok_char(char* str, char delim)
{
    static char* ptr = NULL;
    
    if(str != NULL)
        ptr = str;
    
    if(ptr == NULL)
        return NULL;
        
    while(*ptr && *ptr == delim)
        ptr++;
    
    if(*ptr=='\0')
        return NULL;
    
    char *token = ptr;
    while(*ptr && *ptr!= delim)
        ptr++;
    
    if(*ptr != '\0')
    {
        *ptr = '\0';
        ptr++;
    }
    return token;
}

char* my_strtok(char* str, const char* delim)
{
    static char* ptr = NULL;
    
    // If a new string is provided, reset ptr to the start of the string
    if(str != NULL)
        ptr = str;
    
    if(ptr == NULL)
        return NULL;
    
    // Skip over any leading delimiters in the string
    while(*ptr)
    {
        int is_delim = 0;
        for(int i = 0; delim[i] != '\0'; i++)
        {
            if(*ptr == delim[i])
            {
                is_delim = 1;
                break;
            }
        }
        if(!is_delim) break;  // Stop when we find a non-delimiter
        ptr++;  // Move to the next character
    }
    
    // If we've reached the end of the string, return NULL (no more tokens)
    if(*ptr == '\0')
        return NULL;
    
    // Save the current position as the start of the token
    char *token = ptr;
    
    // Continue until we find a delimiter, replace it with null terminator, and move ptr past it
    while(*ptr)
    {
        int is_delim = 0;
        for(int i = 0; delim[i] != '\0'; i++)
        {
            if(*ptr == delim[i])
            {
                is_delim = 1;
                break;
            }
        }
        if(is_delim)
        {
            *ptr = '\0';  // Null-terminate the current token
            ptr++;  // Move past the delimiter for the next token
            break;
        }
        ptr++;  // Move to the next character
    }
    return token;  // Return the current token
}

int main() {
    char str[] = "Hello, world! This is a test.";
    char *token = my_strtok(str, " ,.!");  // Tokenize based on space, comma, period, and exclamation

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = my_strtok(NULL, " ,.!");  // Continue tokenizing the same string
    }

    return 0;
}
