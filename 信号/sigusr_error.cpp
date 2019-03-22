//用信号实现父子进程交替数数(间隔1s)

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
using namespace std;
int num = 1;
bool flag = 0;
void fatherdo(int x)
{
	printf("par : %d\n", num);
	num += 2;
	sleep(1);
	flag = 1;
}
void childdo(int x)
{
	printf("son : %d\n", num);
	num += 2;
	sleep(1);
	flag = 1;
}
int main()
{
	pid_t pid = fork();
	if(pid > 0)
	{
		sleep(1);
		struct sigaction act;
		act.sa_handler = fatherdo;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		sigaction(SIGUSR2, &act, NULL);

		fatherdo(1);
		while(1)
		{
			if(flag)
			{
				kill(pid, SIGUSR1);
				flag = 0;
			}
		}

	}
	else
	{
		num = 2;
		struct sigaction act;
		act.sa_handler = childdo;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		sigaction(SIGUSR1, &act, NULL);
		while(1)
		{
			if(flag)
			{
				kill(getppid(), SIGUSR2);
				flag = 0;
			}
		}
	}
	return 0;
}