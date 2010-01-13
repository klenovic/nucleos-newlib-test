/* test 3 - library routines rather than system calls */

#include <sys/types.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char buffer[PATH_MAX + 1];
  char *p;
  int i, m = 0xFFFF;

  if (geteuid() == 0 || getuid() == 0) {
	realpath(argv[0], buffer);
  	execl("/usr/bin/su", "/usr/bin/su", "-", "ast", "-c", buffer, NULL);
	printf("Test  3 cannot run as root; test aborted\n");
	exit(1);
  }

	if((p = getenv("HOME")) != NULL && *p == '/')
		printf("HOME=%s\n",p);

	if((p = getenv("PATH")) != NULL)
		printf("PATH=%s\n",p);

	if((p = getenv("LOGNAME")) != NULL)
		printf("LOGNAME=%s\n",p);

	p = getlogin();

	printf("getlogin=%s\n",p);

	return 0;
}
