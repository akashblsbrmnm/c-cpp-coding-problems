#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF 5
int main()
{
    
    const char* append = "$ [USD]";
    char str[MAX_BUFF];

    printf("Enter the amount: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = '\0';

    char *total_amnt = malloc( sizeof(char) * ( strlen(str) + strlen(append) + 1) );
    if(total_amnt == NULL)
    {
        printf("Error in allocating memory for total_amnt.\n");
        return -1;
    }

    // snprintf(total_amnt, ( strlen(str) + strlen(append) + 1 ), "%s%s", str, append);
    strcpy(total_amnt, str);
    strcat(total_amnt, append);
    
    printf("The total amount is: %s\n", total_amnt);

    if(total_amnt != NULL && strlen(total_amnt) > 0)
    {
        free(total_amnt);
        total_amnt = NULL;
    }
    return 0;
}