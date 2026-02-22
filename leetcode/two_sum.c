P#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int index;
} Number;

int compare(const void *a, const void *b) {
    return ((Number *)a)->num - ((Number *)b)->num;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    Number* numbers = (Number*) malloc(sizeof(Number) * numsSize);
    if (!numbers) return NULL;

    for (int i = 0; i < numsSize; i++) {
        numbers[i].num = nums[i];
        numbers[i].index = i;
    }

    qsort(numbers, numsSize, sizeof(Number), compare);

    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int curr_sum = numbers[left].num + numbers[right].num;

        if (curr_sum == target) {
            int* ret = (int*) malloc(2 * sizeof(int));
            ret[0] = numbers[left].index;
            ret[1] = numbers[right].index;
            *returnSize = 2;
            free(numbers);
            return ret;
        } else if (curr_sum > target) {
            right--;
        } else {
            left++;
        }
    }

    free(numbers);
    *returnSize = 0;
    return NULL;
}
