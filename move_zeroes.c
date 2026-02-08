#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int num = nums[i];
            nums[i] = nums[count];
            nums[count] = num;
            count++;
        }
    }
}

// void moveZeroes(int* nums, int numsSize) {
//     int idx = 0;

//     // Move non-zero elements forward
//     for (int i = 0; i < numsSize; i++) {
//         if (nums[i] != 0) {
//             nums[idx++] = nums[i];
//         }
//     }

//     // Fill remaining idxitions with zero
//     while (idx < numsSize) {
//         nums[idx++] = 0;
//     }
// }

int main() {
    int nums[] = {73348, 0, 66106, -85359, 53996, 18849, 0, -6590, -53381, -86613, -41065, 83457, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, numsSize);

    printf("After moving zeroes:\n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
