#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
int dfs(const char *path)
{
	int num = 0;
	DIR *pf = opendir(path);
	if(!pf)
	{
		perror("opendir error");
		exit(1);
	}
	struct dirent *dir;
	while( (dir = readdir(pf)) != NULL)
	{ 
		if( !strcmp(dir -> d_name, ".") || !strcmp(dir -> d_name, "..") )
			continue;
		if( dir -> d_type == DT_REG )
		{
			puts(dir -> d_name);
			num ++;
		}
		if(dir -> d_type == DT_DIR)
		{
			char root[1024];
			sprintf(root, "%s/%s", path, dir->d_name);
			num += dfs(root);
		}
	}
	closedir(pf);
	return num;
}
int main(int argc, char **argv)
{
	printf("%s 目录一共有%d个普通文件\n", argv[1], dfs(argv[1]));
	return 0;
}