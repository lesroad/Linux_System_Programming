//验证线程共享全局变量

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;
int a = 1;
void *func(void *arg)
{
	printf("%d\n", a);
}
int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, func, NULL);
	a = 2;
	printf("%d\n", a);
	pthread_join(tid, NULL);
	return 0;
}