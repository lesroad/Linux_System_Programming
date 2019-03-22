#include <stdio.h>
#include <unistd.h>
#include <cstring>
using namespace std;
int main(int argc, char **argv)
{
	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
	}
	pid_t pid = fork();
	if(pid == 0)
	{
		execl("./fork", "fork!", NULL);
	}
	for(int i = 6; i <= 10; i++)
	{
		printf("%d\n", i);
	}
	return 0;

}