#include "functions.h"

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <filename> <passes>\n", argv[0]);
		return EXIT_FAILURE;
	}

	const char *filename = argv[1];
	int passes = atoi(argv[2]);

	if (passes <= 0) {
		fprintf(stderr, "Number of passes must be a positive integer\n");
		return EXIT_FAILURE;
	}
	// Make rand depending on time so it is always different (hopefully)
	srand((unsigned)time(NULL));

	if (secureDelete(filename, passes) == EXIT_SUCCESS) {
		printf("File '%s' securely deleted with %d passes.\n", filename, passes);
	} else {
		fprintf(stderr, "Failed to securely delete file '%s'.\n", filename);
	}

	return EXIT_SUCCESS;
}
