#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int num = 1;
static const int max = 50;

void* print_odd(void* args)
{
    while (1)
    {
        pthread_mutex_lock(&mut);

        while (num <= max && num % 2 == 0)
            pthread_cond_wait(&cond, &mut);

        if (num > max) {
            pthread_mutex_unlock(&mut);
            return NULL;
        }

        printf("Odd: %d\n", num++);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mut);
    }
}

void* print_even(void* args)
{
    while (1)
    {
        pthread_mutex_lock(&mut);

        while (num <= max && num % 2 != 0)
            pthread_cond_wait(&cond, &mut);

        if (num > max) {
            pthread_mutex_unlock(&mut);
            return NULL;
        }

        printf("Even: %d\n", num++);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mut);
    }
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, print_odd, NULL);
    pthread_create(&t2, NULL, print_even, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}


// Compile : gcc -Wall odd_even.c -pthread -o odd_even

/*
// Simplified Version

Version 1:

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int num = 1;
int max = 50;

void* print_odd(void* args)
{
	while(num <= max)
	{
		pthread_mutex_lock(&mut);
		
		while(num % 2 == 0)
			pthread_cond_wait(&cond, &mut);
		
		if(num <= max)
			printf("Odd: %d\n", num++);
		
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mut);
	}
	return NULL;
}

void* print_even(void* args)
{
	while(num <= max)
	{
		pthread_mutex_lock(&mut);
		while(num % 2 != 0)
			pthread_cond_wait(&cond, &mut);
		
		if(num <= max)
			printf("Even: %d\n", num++);
		
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mut);
	}
	return NULL;
}

int main() 
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, print_odd, NULL);
	pthread_create(&t2, NULL, print_even, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}

*/