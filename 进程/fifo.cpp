#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <fcntl.h>
using namespace std;
int main(int argc, char **argv)
{	
	char s[] = "hello lesroad";
	int fd = open("myfifo", O_WRONLY);
	write(fd, s, sizeof(s));
	close(fd);
	return 0;
}