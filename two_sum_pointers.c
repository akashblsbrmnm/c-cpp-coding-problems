#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

bool isTwoSum(int* arr,int sz, int sum, int* val1, int* val2)
{
    qsort(arr, sz, sizeof(int), compare);
    int* left = arr;
    int * right = arr + (sz - 1);

    while(left < right)
    {
        int current_sum = (*left + *right);
        if ( current_sum == sum)
        {
            *val1 = *left;
            *val2 = *right;
            return true;
        }
        else if(current_sum > sum)
        {
            right--;
        }
        else if( current_sum < sum)
        {
            left++;
        }
    }
    return false;
}


int main()
{
    int arr[] = {64, 18, 12, 02, 21};
    int sum = 14, val1, val2 ;
    int sz = sizeof(arr) / sizeof(arr[0]);

    if(isTwoSum(arr, sz, sum, &val1, &val2))
    {
        printf("Two Sum found for %d is [%d], [%d]\n ", sum, val1, val2);
        return 0;
    }
    else
    {
        printf("No combinations for two sum\n");
        exit(1);
    }
    return 0;
}