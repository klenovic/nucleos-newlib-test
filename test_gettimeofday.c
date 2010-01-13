#include <nucleos/time.h>
#include <nucleos/unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int sec = 0;
	struct timeval start, end;

	if (argc < 2) {
		printf("USAGE: %s seconds\n", argv[0]);
		return 1;
	}

	sec = atoi(argv[1]);

	gettimeofday(&start, NULL);
	sleep(sec);
	gettimeofday(&end, NULL);

	printf("The diffirence is %d usec\n", ((end.tv_sec * 1000000 + end.tv_usec)
		       - (start.tv_sec * 1000000 + start.tv_usec)));

	return 0;
}
