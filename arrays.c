#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(int arr[], int n)
{
    printf("Printing arrays..\n");
    for(int i=0; i<n; i++)
    {
        printf("arr[%d] = %d\n",i, arr[i]);
    }
    return;
}

int findMissing(int arr[], int n)
{
    int sum = n * (n+1) / 2;
    int arr_sum =0;
    for(int i=0; i<n; i++)
    {
        arr_sum += arr[i];
    }
    return sum - arr_sum;
}

void fillZeroes(int arr[], int n)
{
    int index = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] != 0)
            arr[index++] = arr[i];
    }
    while(index < n)
    {
        arr[index++] = 0;
    }
}

void removeDuplicatesFromString(char str[])
{
    int index = 0;
    int len = strlen(str);
    int visited_freq[256] ={0};

    for(int i=0; i < len; i++)
    {
        if(visited_freq[str[i]] == 0)
        {
            str[index++] = str[i];
            visited_freq[str[i]] = 1;
        }
    }
    str[index] = '\0';
    printf("After removeDuplicatesFromString: %s\n", str);
}

int main()
{
    int arr[10] = {0};

    for (int i = 0; i< 10; i++)
    {
        if(i == 5) continue;
        arr[i] = i + 1;
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, n);
    printf("Missing element is: %d\n", findMissing(arr, n));
    char str[] = "programming";
    removeDuplicatesFromString(str);
    return 0;
}
