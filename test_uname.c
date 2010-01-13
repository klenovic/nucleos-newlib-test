#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/fcntl.h>

int main(int argc, const char *argv[])
{
	struct utsname  uts;

	uname(&uts);
	printf( "Init: uts.sysname: %s\n", uts.sysname);
	printf( "Init: uts.nodename: %s\n", uts.nodename);
	printf( "Init: uts.release: %s\n", uts.release);
	printf( "Init: uts.version: %s\n", uts.version);
	printf( "Init: uts.machine: %s\n", uts.machine);
	printf( "Init: uts.domainame: %s\n", uts.domainname);
	puts("");

	return 0;
}
