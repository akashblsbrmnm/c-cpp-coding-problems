#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Selcection sort
void printArray(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return;
}

void selectionSort(int* arr, int n)
{
    if(n==1 || n==0) return;

    for(int i=0; i<n; i++)
    {
        int min = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;

        }
    printArray(arr, n);

    }
    printf("Final Array is : \n");
    printArray(arr, n);
    return;
}

int main()
{
    int arr[] = {4, 6, 1, 7, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    return 0;
}