#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE (7)

void clear_input_buffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Discard characters until newline or EOF
    }
}
int main()
{
    char input[BUFFER_SIZE];
    char pin[BUFFER_SIZE];
    int retry_count = 3;

    // Read PIN from file
    FILE *fp;
    fp = fopen("pin_db.txt", "r");
    if(fp == NULL)
    {
        perror("Error opening file\n");
        exit(1);
    }

    if(fgets(pin, sizeof(pin), fp) == NULL)
    {
        perror("Error reading from file.\n");
        fclose(fp);
        exit(1);
    }
    
    fclose(fp);

    pin[strcspn(pin, "\n")] = '\0';

    while(retry_count > 0)
    {
        printf("Enter PIN (5 Digits): ");
        if(fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading the input. Please try again. (Remaining tries: %d)\n", retry_count - 1);
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        // Check for valid input
        if(input[0] == '\0' || input[0] =='\n' || strlen(input) != 5)
        {
            if(retry_count == 1)
            {
                printf("Invalid input.\n");
            }
            else
            {
                printf("Invalid input. Please try again. (Remaining tries: %d)\n", retry_count - 1);
            }
            memset(input, 0, sizeof(input));
            --retry_count;
            clear_input_buffer();
            continue;
        }

        printf("Checking if the PIN is correct ...... \n");
        if(strcmp(input, pin) ==0)
        {
            printf("Access Granted. WELCOME\n");
            return 0;
        }
        else{
            printf("Incorrect PIN. (Remaining tries: %d)\n", retry_count - 1);
            --retry_count;
            continue;
        }
    }

    memset(pin, 0, sizeof(pin));
    memset(input, 0, sizeof(input));

    printf("input and pin is %s and %s\n", input!=NULL ? input : "NULL" , pin!=NULL ? pin : "NULL");
    return 0;
}