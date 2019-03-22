#include <stdio.h>
#include <unistd.h>
using namespace std;
int main()
{
	pid_t gid = getpgid(getpid());
	printf("%d\n", gid);
	return 0;
}