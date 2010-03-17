
#include <stdio.h>
#include <limits.h>
#include <nucleos/endpoint.h>

/* @nucleos: Fix it! */
#ifndef CONFIG_NR_PROCS
#define	CONFIG_NR_PROCS		100
#endif

int main(int argc, char *argv[])
{
	int g, p;

	printf("Test 39 ");
	fflush(stdout);

	for(g = 0; g <= _ENDPOINT_MAX_GENERATION; g++) {
		for(p = -MAX_NR_TASKS; p < NR_PROCS; p++) {
			endpoint_t e;
			int mg, mp;
			e = _ENDPOINT(g, p);
			mg = _ENDPOINT_G(e);
			mp = _ENDPOINT_P(e);
			if(mg != g || mp != p)  {
				printf("%d != %d || %d != %d\n", mg, g, mp, p);
				return 1;
			}
			if(g == 0 && e != p) {
				printf("%d != %d and g=0\n", e, p);
				return 1;
			}
			if(e == ENDPT_ANY || e == ENDPT_SELF || e == ENDPT_NONE) {
				printf("endpoint (%d,%d) is %d; ANY, SELF or NONE\n",
					g, p, e);
				return 1;
			}
		}
	}

	printf("ok\n");

	return 0;
}

