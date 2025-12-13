#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("Integer Types:\n");
    printf("  INT_MIN       = %d\n", INT_MIN);
    printf("  INT_MAX       = %d\n", INT_MAX);

    printf("  UINT_MAX      = %u\n", UINT_MAX);
    
    printf("  LONG_MIN      = %ld\n", LONG_MIN);
    printf("  LONG_MAX      = %ld\n", LONG_MAX);

    printf("  ULONG_MAX     = %lu\n", ULONG_MAX);
    
    printf("  CHAR_MIN      = %d\n", CHAR_MIN);
    printf("  CHAR_MAX      = %d\n", CHAR_MAX);
    printf("  UCHAR_MAX     = %u\n", UCHAR_MAX);

    printf("\nFloating Point Types:\n");
    printf("  FLT_MIN       = %e\n", FLT_MIN);
    printf("  FLT_MAX       = %e\n", FLT_MAX);
    printf("  DBL_MIN       = %e\n", DBL_MIN);
    printf("  DBL_MAX       = %e\n", DBL_MAX);
    printf("  LDBL_MIN      = %Le\n", LDBL_MIN);
    printf("  LDBL_MAX      = %Le\n", LDBL_MAX);

    return 0;
}
