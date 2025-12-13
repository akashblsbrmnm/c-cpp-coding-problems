#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 1;
#define MAX_NUM 10

void* printOdd(void* arg) {
    while (count <= MAX_NUM) {
        if (count % 2 == 1) {
            printf("Odd: %d\n", count++);
        }
    }
    return NULL;
}

void* printEven(void* arg) {
    while (count <= MAX_NUM) {
        if (count % 2 == 0) {
            printf("Even: %d\n", count++);
        }
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, printOdd, NULL);
    pthread_create(&t2, NULL, printEven, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
