#include <stdio.h>
 void test(int counter) {
    static int buffer[1024];  // Unused variable
    printf("Stack depth: %d\n", counter);
    test(counter + 1);
}
 
int main() {
    test(1);
    return 0;
}

