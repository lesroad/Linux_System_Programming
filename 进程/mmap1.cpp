
//有血缘关系非匿名映射区

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
using namespace std;
int main(int argc, char **argv)
{
	int fd = open("1.txt", O_RDWR);
	int length = lseek(fd, 0, SEEK_END);
	void *ptr = mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(ptr == MAP_FAILED)
	{
		perror("mmap error");
		exit(1);
	}	
	pid_t pid = fork();
	if(pid == 0)
	{
		strcpy((char *)ptr, "有血缘关系非匿名映射区");
	}
	else
	{
		sleep(0.1);//因为非阻塞
		puts((char *)ptr);
		wait(NULL);
	}
	munmap(ptr, length);
	close(fd);
	return 0;
}