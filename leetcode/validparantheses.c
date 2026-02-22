#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool validate_parantheses(char *str)
{
    int n = strlen(str);
    char stack[n];
    int top = -1;

    for(int i=0; i< n; i++)
    {
        char c = str[i];

        if(c == '(' || c == '{' || c == '[')
        {
            stack[++top] = c;
        }
        else
        {
            if(top == -1) return false;

            char top_c = stack[top--];
            if((c == ')' && top_c != '(') ||
               (c == ']' && top_c != '[') ||
               (c == '}' && top_c != '{'))
               {
                return false;
               }
        }
    }
    if(top == -1)
        return true;
    else
        return false;
}

int main()
{
    char s[1000];
    scanf("%s", s);

    if (validate_parantheses(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}