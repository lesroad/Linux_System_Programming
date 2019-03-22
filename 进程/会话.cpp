#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;
int main()
{
	pid_t pid = fork();
	if(pid > 0)
	{
		printf("par sid = %d\n", getsid(0));
		printf("par pgid = %d\n", getpgid(0));
		printf("par pid = %d\n", getpid());
		
		wait(NULL);
	}
	else
	{
		printf("son sid = %d\n", getsid(0));
		printf("son pgid = %d\n", getpgid(0));
		printf("son ppid = %d\n", getppid());
		if(setsid() == -1)
		{
			perror("setsid error");
			exit(1);
		}
		else
		{
			printf("son pid = %d, ppid = %d, sid = %d, pgid = %d\n", getpid(), getppid()\
				, getsid(0), getpgid(0));
		}
	}
	return 0;
}