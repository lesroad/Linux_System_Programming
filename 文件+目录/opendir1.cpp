#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

using namespace std;
void dfs(char *path)
{
	DIR *od = opendir(path);
	if(!od)
	{
		perror("opendir error");
		exit(1);
	}
	struct dirent *rd;
	while(rd = readdir(od), rd)
	{
		if(!rd)
		{
			perror("readdir error");
			exit(1);
		}
		if(!strcmp(rd->d_name, ".") || !strcmp(rd->d_name, "..")) continue;
		printf("file name %s\n", rd->d_name);
		if(rd->d_type == DT_REG) puts("reg file");
		else if(rd->d_type == DT_DIR)
		{
			char s[1024];
			sprintf(s, "%s/%s", path, rd->d_name);
			dfs(s);
		}
		else puts("no reg and dir file");
	}
	closedir(od);
}
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		fprintf(stderr, "input number error!\n");
		exit(1);
	}
	dfs(argv[1]);
	

	return 0;
}