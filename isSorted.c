#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSorted(int* arr, int n)
{
    if(n == 1 || n == 0) return true;

    for(int i=1; i<n; i++)
    {
        if(arr[i - 1] > arr[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int arr[] = {1, 2, 4, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("No. of elemets: %d\n", n);
    if(isSorted(arr, n) == 1)
    {
        printf("The array is sorted.\n");
    } else {
        printf("Array is not sorted.\n");
    }
    return 0;
}