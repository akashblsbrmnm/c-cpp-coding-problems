#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

unsigned int num = 1;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond =  PTHREAD_COND_INITIALIZER;

void* printOdd(void* args)
{
    while (num <=10)
    {
        pthread_mutex_lock(&lock);
        while(num % 2 == 0)
        {
            pthread_cond_wait(&cond, &lock);
        }
        if( num %2 != 0) {
            printf("Odd thread: %u\n",num++);
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&lock);

    }
    return NULL;
}

void* printEven(void* args)
{
    while (num <=10)
    {
        pthread_mutex_lock(&lock);
        while(num % 2 != 0)
        {
            pthread_cond_wait(&cond, &lock);
        }
        if( num %2 == 0) {
            printf("Odd thread: %u\n",num++);
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&lock);

    }
    return NULL;
}


int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, printOdd, NULL);
    pthread_create(&thread2, NULL, printEven, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

}