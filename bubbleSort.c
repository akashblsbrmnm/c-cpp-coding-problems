#include <stdio.h>
#include <stdbool.h>

// Function to print array
void printArray(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return;
}

// Bubble sort function
void bubbleSort(int* arr, int n)
{
    bool swapped;

    for(int i = 0; i < n - 1; i++)
    {
        swapped = false;

        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        // Uncomment below line to see each pass
        printf("After pass %d: \n", i + 1);
        printArray(arr, n);

        // If no two elements were swapped in inner loop, array is sorted
        if(!swapped)
            break;
    }
}

int main()
{
    int arr[] = {4, 6, 1, 7, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
