
//考察信号集大部分函数

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/wait.h>
using namespace std;
int main(int argc, char **argv)
{
	pid_t pid = fork();
	if(pid > 0)
	{
		sigset_t myset, pendset;
		sigaddset(&myset, SIGINT);//ctrl+c
		sigaddset(&myset, SIGQUIT);//ctrl+反斜杠
		sigaddset(&myset, SIGALRM);//alarm
		sigprocmask(SIG_BLOCK, &myset, NULL);
		itimerval new_value;
		new_value.it_value.tv_sec = 4;
		new_value.it_value.tv_usec = 0;
		new_value.it_interval.tv_sec = 4;
		new_value.it_interval.tv_usec = 0;
		setitimer(ITIMER_REAL, &new_value, NULL);
		//alarm(2);
		while(1)
		{
			sleep(1);
			sigpending(&pendset);
			printf("par:");
			for(int i = 1; i < 33; i++)
			{
				if(sigismember(&pendset, i))
					printf("1");
				else 
					printf("0");
			}
			puts("");
			waitpid(-1, NULL, WNOHANG);
		}
	}
	else
	{
		sigset_t pendset;
		while(1)
		{
			sleep(1);
			sigpending(&pendset);
			printf("son:");
			for(int i = 1; i < 33; i++)
			{
				if(sigismember(&pendset, i))
					printf("1");
				else 
					printf("0");
			}
			puts("");
		}
	}
	return 0;
}