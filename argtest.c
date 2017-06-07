#include <stdio.h>
#include <unistd.h>

/* 
 * Running program with argtest -f test.txt should yeild 2 arguments + 1 for program name
 */
int main(int argc, char** argv) {
	/* Start index and first param after exe file name */
	argc -= optind;
	argv += optind;

	while (argc != 0) {
		printf("Number of arguments: %i\n", argc);
		printf("Argument is: %s\n", argv[0]);

		argc -= optind;
		argv += optind;
	}
	return 0;
}
