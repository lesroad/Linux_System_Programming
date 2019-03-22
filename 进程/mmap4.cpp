
//无血缘关系非匿名映射区

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
	int fd = open("1", O_RDWR|O_CREAT, 0777);
	ftruncate(fd, 4096);
	int length = lseek(fd, 0, SEEK_END);
	void *ptr = mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(ptr == MAP_FAILED)
	{
		perror("mmap error");
		exit(1);
	}
	printf("%p\n", ptr);
	printf("%s\n", (char *)ptr);

	close(fd);
	munmap(ptr, length);
	return 0;
}

//mmap3先运行，mmap4在运行，与文件内容无关