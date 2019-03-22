#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
using namespace std;
int main(int argc, char **argv)
{	
	int fd[2];
	pipe(fd);
	pid_t pid = fork();
	if(pid == 0)
	{
		dup2(fd[1], 1); //用管道写端代替标准写端
		close(fd[0]);   //必须要关闭，防止等待数据阻塞
		execlp("ps", "ps", "au", NULL);
		perror("execlp error");
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[1]);
		execlp("grep", "grep", "bash", NULL);
		perror("execlp error");
	}
	return 0;
}