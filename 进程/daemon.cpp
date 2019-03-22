#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <cstring>
#include <sys/stat.h>
#include <sys/time.h>
using namespace std;
void func(int sig)
{
	int fd = open("clock", O_CREAT | O_APPEND | O_RDWR, 0777);
	if(fd == -1)
	{
		perror("open error");
		exit(1);
	}
	time_t now;
	time(&now);
	char *s = ctime(&now);
	write(fd, s, strlen(s)+1);//不是sizeof！！！

	close(fd);
}
int main()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork error");
		exit(1);
	}
	if(pid > 0)
	{
		exit(1);
	}
	pid_t s_pid = setsid();
	if(s_pid == -1)
	{
		perror("setsid error");
		exit(1);
	}
	chdir("./");
	umask(0002);
	struct sigaction act;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGALRM, &act, NULL);

	struct itimerval it;
	it.it_interval.tv_sec = 1;
	it.it_interval.tv_usec = 0;
	it.it_value.tv_sec = 2;
	it.it_value.tv_usec = 0;
	setitimer(ITIMER_REAL, &it, NULL);

	close(STDIN_FILENO);		
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	while(1);
	return 0;
}
