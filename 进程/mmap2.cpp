
//有血缘关系匿名映射区

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
	int length = 4096;
	void *ptr = mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANON, -1, 0);
	if(ptr == MAP_FAILED)
	{
		perror("mmap error");
		exit(1);
	}	
	pid_t pid = fork();
	if(pid == 0)
	{
		strcpy((char *)ptr, "有血缘关系匿名映射区");
	}
	else
	{
		sleep(0.1);//因为非阻塞
		puts((char *)ptr);
		wait(NULL);
	}
	munmap(ptr, length);
	return 0;
}