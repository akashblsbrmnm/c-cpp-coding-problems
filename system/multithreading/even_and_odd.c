#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_NUM 50

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int count = 1;

void* printOdd(void* arg) {
    while (count <= MAX_NUM) {
        pthread_mutex_lock(&lock);
        while (count % 2 == 0) { // Wait if even
            pthread_cond_wait(&cond, &lock);
        }
        if (count <= MAX_NUM) {
            printf("Odd Thread: %d\n", count);
            count++;
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* printEven(void* arg) {
    while (count <= MAX_NUM) {
        pthread_mutex_lock(&lock);
        while (count % 2 != 0) { // Wait if odd
            pthread_cond_wait(&cond, &lock);
        }
        if (count <= MAX_NUM) {
            printf("Even Thread: %d\n", count);
            count++;
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, printOdd, NULL);
    pthread_create(&t2, NULL, printEven, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}
