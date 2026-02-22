#include <stdio.h>

int findClosestTriangularNumber(int T) {
    int next_natural_num = 1;
    int triangularNumber = 1;
    int last = 0;
    while(triangularNumber <= T) {
        last = triangularNumber;
        next_natural_num++;
        triangularNumber += next_natural_num;
    }
    return last;
}

int main() {
    int T =20;
    int result = findClosestTriangularNumber(T);
    printf("The closest triangular number to %d is %d\n", T, result);
    return 0;
}
