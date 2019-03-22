//错误的创建多线程方式
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;
void *p_main(void *arg)
{
	printf("第%d个线程id:%lu\n", *(int*)arg, pthread_self());
}
int main()
{
	pthread_t pid;
	for(int i = 0; i < 10; i++)
	{
		pthread_create(&pid, NULL, p_main, (void *)&i);
	}
	sleep(1);
	return 0;
}