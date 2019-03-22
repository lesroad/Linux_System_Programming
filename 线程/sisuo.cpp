//实现两个线程死锁
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;
pthread_mutex_t mutex1, mutex2;
void *func(void *arg)
{
	pthread_mutex_lock(&mutex2);
	printf("zi\n");
	pthread_mutex_lock(&mutex1);
	pthread_mutex_unlock(&mutex2);
}
int main()
{
	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);
	pthread_t tid;
	pthread_create(&tid, NULL, func, NULL);
	pthread_mutex_lock(&mutex1);
	printf("zhu\n");
	pthread_mutex_lock(&mutex2);
	pthread_mutex_unlock(&mutex1);
	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
	pthread_join(tid, NULL);
	return 0;
}