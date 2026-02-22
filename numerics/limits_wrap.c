#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int a = UINT_MAX;
    printf("UINT_MAX = %u\n", a);      // 4294967295
    printf("UINT_MAX + 1 = %u\n", a + 1); // 0 (Wraps around)

    unsigned int b = 0;
    printf("0 - 1 = %u\n", b - 1);     // 4294967295 (Wraps around)

    signed int c = INT_MAX;
    printf("INT_MAX = %d\n", INT_MAX);
    printf("INT_MIN = %d\n", INT_MIN);
    printf("SIGNED  -  INT_MAX + 1 = %d\n", c + 1);
    return 0;
}