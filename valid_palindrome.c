bool isPalindrome(char* s) {
    if(s == NULL)
    {
        return false;
    }

    int n = strlen(s);
    int idx = 0;
    char *filtered = malloc(n + 1);

    for(int i=0; s[i] != '\0'; i++)
    {
        if(isalnum(s[i]))
        {
            filtered[idx++] = tolower(s[i]); 
        }
    }
    filtered[idx] = '\0';

    int start = 0;
    int end = strlen(filtered) - 1;

    while(start < end)
    {
        if(filtered[start] != filtered[end]){
            free(filtered);
            return false;
        }
        start++;
        end--;
    }
    free(filtered);
    return true;
}