#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;
int main(int argc, char **argv)
{
	pid_t pid = fork();
	if(pid == 0)
	{
		for(int i = 1; i <= 5; i++)
		{
			printf("wait %ds\n", 6 - i);
			sleep(1);
		}
		abort();
	}
	else
	{
		int status;
		waitpid(-1, &status, 0);
		if(WIFSIGNALED(status))
		{
			printf("由 %d 号信号杀死\n", WTERMSIG(status));
		}
		else if(WIFEXITED(status))
		{
			printf("正常终止\n");
		}
	}
	return 0;
}