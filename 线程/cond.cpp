#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
using namespace std;
pthread_mutex_t mutex;
pthread_cond_t cond;
struct produce
{
	int num;
	struct produce *next;
};
struct produce *head = NULL;
void *producer(void *arg)
{
	while(1)
	{
		struct produce *x = (struct produce *)malloc(sizeof(struct produce));
		x->num = rand()%20;
		printf("producer %d \n", x->num);
		//头插法
		pthread_mutex_lock(&mutex);
		x->next = head;
		head = x;
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
		sleep(rand()%3);
	}
	
}
void *customer(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		while(head == NULL)
		{
			pthread_cond_wait(&cond, &mutex);
		}
		struct produce *temp = head;
		int x = head->num;
		head = head->next;
		pthread_mutex_unlock(&mutex);
		free(temp);
		printf("customer %d\n", x);
		sleep(rand()%3);
	}
}
int main()
{
	srand(time(0));
	pthread_t pid, cid;
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);

	pthread_create(&pid, NULL, producer, NULL);
	pthread_create(&cid, NULL, customer, NULL);

	pthread_join(pid, NULL);
	pthread_join(cid, NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	return 0;
}