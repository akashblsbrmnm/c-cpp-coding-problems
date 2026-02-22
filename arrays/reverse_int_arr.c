#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr;
    printf("Enter no. of elements: ");
    scanf("%d", &num);
    arr = (int *)malloc(sizeof(int) * num);
    for(int i=0; i< num; i++)
    {
        scanf("%d", arr + i);
    }

    for(int i = 0; i< num/2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[num - i -1];
        arr[num - i - 1] = tmp;
    }

    printf("Reversed array is:\n");
    for(int i = 0; i<num; i++)
    {
        printf("%d\t", *(arr +i));
    }
    printf("\n");
    return 0;
}