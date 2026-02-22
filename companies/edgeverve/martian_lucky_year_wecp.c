/*

🛸 Martian Lucky Years
On Mars, certain digits are considered unlucky. The Martians have asked you to help them identify "Martian Lucky Years."
You are given:

An integer N — the starting year
An integer K — the number of unlucky digits
An integer array Arr of size K — containing the unlucky digits (each in range 0–9)

Your task is to find all years in the range [N, 20000] that are Martian Lucky, and return how many such years exist.
A year is Martian Lucky if every digit in the year is not present in Arr.

Input Format

The first line contains an integer N (1 ≤ N ≤ 20000) - the starting year
The second line contains an integer K (1 ≤ K ≤ 10) - the number of unlucky digits
The third line contains K space-separated integers representing the unlucky digits (each digit is between 0 and 9)

Output Format
Print all lucky years from N to 20000 on a single line, separated by spaces, followed by a new line with the total count of lucky years.
Constraints

1 ≤ N ≤ 20000
1 ≤ K ≤ 10
Each unlucky digit is between 0 and 9
Unlucky digits may not be unique in the input

*/

#include <stdio.h>
#include <stdlib.h>

#define LIM 20000

int isUnluckyDigit(int d, int K, int *Arr)
{
    for (int i = 0; i < K; i++) {
        if (Arr[i] == d)
            return 1;   // digit is forbidden
    }
    return 0;
}

int findLuckyYears(int N, int K, int *Arr)
{
    int count = 0;

    for (int year = N; year <= LIM ; year++) {
        int y = year;
        int bad = 0;

        while (y > 0) {
            int d = y % 10;

            if (isUnluckyDigit(d, K, Arr)) {
                bad = 1;
                break;
            }

            y /= 10;
        }

        if (!bad) {
            printf("%d ", year);
            count++;
        }
    }

    printf("\nTotal Lucky Years: %d\n", count);
    return count;
}

int main()
{
    int N, K;

    scanf("%d", &N);   // starting year
    scanf("%d", &K);   // number of forbidden digits

    int *Arr = (int *)malloc(K * sizeof(int));
    for (int i = 0; i < K; i++) {
        scanf("%d", &Arr[i]);
    }

    findLuckyYears(N, K, Arr);

    free(Arr);
    return 0;
}
