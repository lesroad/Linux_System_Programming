#include <stdio.h>
#include <grp.h>
#include <unistd.h>
using namespace std;
int main(int argc, char **argv)
{
	struct group *gr = getgrgid(getgid());
	printf("%s\n%s\n%d\n", gr->gr_name, \
		gr->gr_passwd, gr->gr_gid);
	char ** mem = gr->gr_mem;
	while(*mem)
	{
		printf("%s\n", *mem);
		mem ++;
	}
	return 0;
}