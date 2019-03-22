#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		fprintf(stderr, "input number error!\n");
		exit(1);
	}
	if(access(argv[1], F_OK) == 0) puts("exist");
	else
	{
		perror("no exist !");
		exit(1);
	}
	if(access(argv[1], R_OK) == 0) puts("can read");
	if(access(argv[1], W_OK) == 0) puts("can write");
	if(access(argv[1], X_OK) == 0) puts("can exec");
	
	return 0;
}