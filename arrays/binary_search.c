#include <stdio.h>

int binary_search(int arr[], int n, int key)
{
    int high = n - 1;
    int low = 0;
    while(low <=high)
    {
        int mid = low + ( high - low) / 2;

        if(arr[mid] == key)
            return mid;
        else if(key > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}