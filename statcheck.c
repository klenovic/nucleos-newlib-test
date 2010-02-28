#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdarg.h>

void bb_error_msg_and_die(const char *s, ...)
{
        va_list p;

        va_start(p, s);
//        bb_verror_msg(s, p, NULL);
	fprintf(stderr,"%s",s);
        va_end(p);
//        xfunc_die();
	exit(1);
}

struct dnode {
	const char *name;       /* the dir entry name */
	const char *fullname;   /* the dir entry name */
	struct dnode *next;     /* point at the next node */
	int fname_allocated;
	struct stat dstat;      /* the file stat info */
};

// Die if we can't allocate size bytes of memory.
void* xmalloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL && size != 0) {
		bb_error_msg_and_die("No memory");
		exit(1);
	}

	return ptr;
}

int main( int argc, char *argv[] ) {
	DIR *pDIR;
	struct dirent *pDirEnt;
	struct stat st;
	struct dnode *cur;

	/* Open the current directory */
	pDIR = opendir(argv[1]);

	if (pDIR == NULL) {
		fprintf(stderr, "%s %d: opendir() failed (%s)\n",
			__FILE__, __LINE__, strerror( errno ));
		exit(-1);
	}
	chdir(argv[1]);
	/* Get each directory entry from pDIR and print its name */
	pDirEnt = readdir(pDIR);
	while (pDirEnt != NULL) {
		pDirEnt = readdir(pDIR);

		if (!pDirEnt)
			break;

		if (lstat(pDirEnt->d_name, &st) == -1) {
			perror("stat");
			continue;
		}

		switch (S_IFMT & st.st_mode) {
		case S_IFLNK: /* symbolic link */
			printf("%s is link\n",pDirEnt->d_name);
			break;
		case S_IFREG: /* regular */
			printf("%s is regular\n",pDirEnt->d_name);
			break;
		case S_IFBLK: /* block special */
			printf("%s is block\n",pDirEnt->d_name);
			break;
		case S_IFDIR: /* directory */
			printf("%s is directory\n",pDirEnt->d_name);
			break;
		case S_IFCHR: /* character special */
			printf("%s is character special\n",pDirEnt->d_name);
			break;
		case S_IFIFO: /* this is a FIFO */
			printf("%s is fifo\n",pDirEnt->d_name);
			break;
		default:
			printf("%s is unknown\n",pDirEnt->d_name);
			break;
		}

	}
	putchar('\n');

	cur = xmalloc(sizeof(*cur));
	cur->fullname = pDirEnt->d_name;
	cur->name = pDirEnt->d_name;
	cur->dstat = st;

	/* Release the open directory */
	closedir( pDIR );

	return 0;
}
