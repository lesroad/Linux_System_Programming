#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
int main()
{
	struct stat file;
	if(stat("stdout", &file) == -1)
	{
		perror("stat error");
		exit(1);
	}
	printf("user id : %d\n", file.st_uid);
	printf("group id : %d\n", file.st_gid);
	if(S_ISREG(file.st_mode)) puts("is reg file");
	else puts("no reg file");
	if(file.st_mode & S_IRUSR) puts("can read");
	if(file.st_mode & S_IWUSR) puts("can write");
	if(file.st_mode & S_IXUSR) puts("can exec");
	return 0;
}