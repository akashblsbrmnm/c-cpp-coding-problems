#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int freq[10] = {0};
    char *str = (char *) malloc (1024 * sizeof(char));
    if(str == NULL) exit(EXIT_FAILURE);
    scanf("%s", str);
    
    for(int i=0; i< strlen(str); i++ )
    {
        // if(isdigit(str[i]))
        if( (str[i] - '0' >= 0) || (str[i] - '0' <= 9) )
        {
            freq[str[i] - '0'] ++;
        }
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", freq[i]);
    }
    printf("\n");
    return 0;
}
