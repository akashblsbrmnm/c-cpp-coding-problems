bool isValid(char* s) {
    if(s == NULL || *s == '\0') return false;
    int n = strlen(s);

    char stack[n];
    int top = -1;
    for(int i=0; i<n; i++)
    {
        char c = s[i];

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
    return (top == -1);
}