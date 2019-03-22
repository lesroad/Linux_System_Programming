#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
using namespace std;
void func(int x)
{
	;
}
void mysleep(int n)
{
	struct sigaction act, oldact;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGALRM, &act, &oldact);
	alarm(n);
	int ret = pause();
	if(ret == -1 && errno == EINTR)
	{
		printf("sleep %ds\n", n);
	}
}
int main()
{
	while(1)
	{
		mysleep(1);
		
	}
	return 0;
}