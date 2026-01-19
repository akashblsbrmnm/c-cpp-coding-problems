#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int i = 1;
static const int num = 50;

void* print_odd(void* args)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		while(i <= num && i %2 == 0)
		{
			pthread_cond_wait(&cond, &lock);
		}
		
		if(i > num)
		{
			pthread_cond_signal(&cond);
			pthread_mutex_unlock(&lock);
			return NULL;
		}

		printf("Odd = %d\n", i++);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&lock);
	}
}

void* print_even(void* args)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		while(i <= num && i % 2 != 0)
		{
			pthread_cond_wait(&cond, &lock);
		}
		
		if(i > num)
		{
			pthread_cond_signal(&cond);
			pthread_mutex_unlock(&lock);
			return NULL;
		}
		printf("Even = %d\n", i++);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&lock);
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
