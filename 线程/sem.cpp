#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <queue>
using namespace std;
sem_t s1, s2;
queue<int>Q;
void *producer(void *arg)
{
	while(1)
	{
		int x = rand()%20;
		sem_wait(&s1);
		Q.push(x);
		sem_post(&s2);
		printf("producer:%d\n", x);
		//sleep(rand()%5);
	}
}
void *customer(void *arg)
{
	while(1)
	{
		sem_wait(&s2);
		printf("customer:%d\n", Q.front());
		Q.pop();
		sem_post(&s1);
		sleep(rand()%5);
	}
}
int main()
{
	srand(time(0));
	pthread_t p, c;
	sem_init(&s1, 0, 5);
	sem_init(&s2, 0, 0);

	pthread_create(&p, NULL, producer, NULL);
	pthread_create(&c, NULL, customer, NULL);

	sem_destroy(&s1);
	sem_destroy(&s2);

	pthread_join(p, NULL);
	pthread_join(c, NULL);
	return 0;
}