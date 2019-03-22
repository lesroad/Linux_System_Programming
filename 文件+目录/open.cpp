#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	int fd;
	umask(0);
	fd = open("test",O_RDWR|O_CREAT,0666);
	if(fd < 0)
		perror("open");
	return 0;
}  

