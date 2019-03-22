#include <stdio.h>
#include <signal.h>
#include <unistd.h>
using namespace std;
void func(int x)
{
	printf("此时按ctrl+c不会立即退出哦!\n");
	sleep(4);
}
int main(int argc, char **argv)
{
	struct sigaction act;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGINT);
	act.sa_flags = 0;
	sigaction(SIGQUIT, &act, NULL);
	while(1)
	{
		sleep(1);
		printf("hello\n");
	}
	return 0;
}