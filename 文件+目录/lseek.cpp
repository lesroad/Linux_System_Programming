#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <fcntl.h>
using namespace std;
int main()
{
	char s[50] = "123";
	int id = open("1.txt", O_RDWR);
	read(id, s, 5);
	puts(s);
	lseek(id, 3, SEEK_CUR);
	read(id, s, 5);
	puts(s);
	
	return 0;
}