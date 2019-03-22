#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
using namespace std;
int main(int argc, char **argv)
{
	struct passwd *pw = getpwuid(getuid());
	printf("%s\n%s\n%d\n%d\n%s\n%s\n%s\n", pw->pw_name, \
	pw->pw_passwd, pw->pw_uid, pw->pw_gid, pw->pw_gecos, \
	pw->pw_dir, pw->pw_shell);
	return 0;
}