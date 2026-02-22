#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Brute-force logic
bool isTwoSum(int* arr,int sz, int sum, int* val1, int* val2, int* pos1, int* pos2)
{
    for(int i=0; i< sz; i++)
    {
        for(int j= i+1; j < sz;j++)
        {
            if( (arr[i] + arr[j]) == sum )
            {
                *val1 = arr[i];
                *val2 = arr[j];
                *pos1 = i;
                *pos2 = j;
                return true;
            }
        }
    }
    return false;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 7, val1, val2, pos1, pos2;
    int sz = sizeof(arr) / sizeof(arr[0]);

    if(isTwoSum(arr, sz, sum, &val1, &val2, &pos1, &pos2))
    {
        printf("Two Sum found for %d is [%d], [%d] at positions %d and %d respectively.\n ", sum, val1, val2, pos1, pos2);
        return 0;
    }
    else
    {
        printf("No combinations for two sum\n");
        exit(1);
    }
    return 0;
}