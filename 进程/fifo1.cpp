#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <fcntl.h>
using namespace std;
int main(int argc, char **argv)
{	
	char s[20];
	int fd = open("myfifo", O_RDONLY);
	int len = read(fd, s, sizeof(s));
	s[len] = 0;
	close(fd);
	puts(s);
	return 0;
}