#include <stdio.h>

int isNearlyLucky(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int count = 0;
        int num = arr[i];
        while(num > 0) {
            int digit = num % 10;
            if(digit == 3 || digit == 4 || digit == 7) {
                count++;
            }
            num = num / 10;
        }
        if( count == 3 || count == 4 || count == 7) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

int main() {
    int arr[] = {7347, 120347, 447, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    isNearlyLucky(arr, n);
    return 0;
}