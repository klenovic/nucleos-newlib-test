/* Comment on usage and program: ark!/mnt/rene/prac/os/unix/comment.changes */

/* "const.h", created by Rene Montsma and Menno Wilcke */

#include <sys/types.h>		/* type defs */
#include <sys/stat.h>		/* struct stat */
#include <sys/wait.h>
#include <errno.h>		/* the error-numbers */
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <utime.h>
#include <stdio.h>
#include <limits.h>

/*****************************************************************************
 *                              TEST                                         *
 ****************************************************************************/
int main(int argc, char *argv[])
{
	struct stat stbf1;
	int n;

	/* Try to creat a dir */
	if ((n = creat("dir", 040777)) != -1) {
		if (fstat(n, &stbf1) != 0)
			printf("fstat problem\n");
		else if (stbf1.st_mode != (mode_t) 0100777)
			printf("mode=%d\n", stbf1.st_mode);
	}
}
