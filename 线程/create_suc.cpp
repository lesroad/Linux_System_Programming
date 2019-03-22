//正确的创建多线程方式
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;
void *p_main(void *arg)
{
	printf("第%ld个线程id:%lu\n", (long)arg, pthread_self());
}
int main()
{
	pthread_t pid[10];
	for(int i = 0; i < 10; i++)
	{
		pthread_create(&pid[i], NULL, p_main, (void *)i);
	}
	for(int i = 0; i < 10; i++)
	{
		pthread_join(pid[i], NULL);
	}
	return 0;
}