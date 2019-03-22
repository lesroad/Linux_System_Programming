#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;
int main(int argc, char **argv)
{
	itimerval value;
	value.it_value.tv_sec = 2;
	value.it_value.tv_usec = 0;
	value.it_interval.tv_sec = 1;
	value.it_interval.tv_usec = 0;
	setitimer(ITIMER_REAL, &value, NULL);
	while(1)
	{
		printf("hello\n");
		sleep(1);
	}
	return 0;
}