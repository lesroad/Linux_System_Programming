#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
using namespace std;
int main()
{
	printf("stdout 123\n");
	perror("stderr 456\n");
	fprintf(stdout, "789\n");
	fprintf(stderr, "les\n");
	return 0;
}