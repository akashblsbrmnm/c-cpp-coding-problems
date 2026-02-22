#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    
    if(x < y) return -1;
    if(x > y) return 1;
    return 0;
}

int longestConsecutive_qsort(int arr[], int n)
{
    if(n == 0) return 0;
    
    qsort(arr, n, sizeof(int), compare);

    int current = 1, longest = 1;

    for(int i= 1; i<n; i++) {
        if(arr[i] == arr[i - 1])
        {
            continue; // skip duplicates
        }
        else if(arr[i] == arr[i - 1] + 1)
        {
            current++;
        }
        else
        {
            if(current > longest)
                longest = current; // Save last longest subsequence
            current = 1;
        }
    }
   
   if(current > longest)
    longest = current;

    return longest;
}

int longestConsecutive_Hash(int arr[], int n)
{
    if(n == 0) return 0;
    int* freq_arr = (int *)calloc(MAX + 1, sizeof(int));
    if(!freq_arr)
        return -1;
    
    for(int i =0; i < n; i++) {
        if(arr[i])
            freq_arr[arr[i]] = 1;
    }
    
    int longest = 0;
    int current = 0;
    
    for(int i = 0; i<= MAX; i++) {
        if(freq_arr[i] == 1)
        {
            current++;
            if(current > longest) longest = current;
        }
        else
        {
            current = 0;
        }
    }
    return longest;
}

int main()
{
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Full scan result (Hash): %d\n", longestConsecutive_Hash(arr, n));
    printf("Longest consecutive subsequence length (qsort): %d\n", longestConsecutive_qsort(arr, n));

    return 0;
}
