
//文件描述符进程通信

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
using namespace std;
int main()
{
	umask(0002);
	int fd = open("1", O_CREAT|O_RDWR|O_TRUNC, 0777);
	pid_t pid = fork();
	if(pid > 0)
	{
		char s[] = "hello lesroad!\n";
		write(fd, s, strlen(s));
		wait(NULL);
	}
	else
	{
		char s[100];
		sleep(1);
		lseek(fd, 0, SEEK_SET);
		int l = read(fd, s, sizeof(s));
		s[l] = 0;
		printf("son : %d\n", getpid());
		printf("son : %u\n", getpid());
		puts(s);
	}
	return 0;
}