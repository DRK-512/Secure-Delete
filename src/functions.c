
#include "functions.h"

long getFileSize(FILE *file) {
	fseek(file, 0L, SEEK_END);
	long size = ftell(file);
	fseek(file, 0L, SEEK_SET);
	return size;
}

// this overrites the file with random data
void overwriteFile(FILE *file, long size, int passes) {
	unsigned char *randomData = malloc(size);
	if (randomData == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	for (int pass = 0; pass < passes; pass++) {
		// Generate random data
		for (long i = 0; i < size; i++) {
			randomData[i] = rand() % 256;
		}

		// Write random data to the file
		fwrite(randomData, 1, size, file);
		fflush(file);
		fseek(file, 0L, SEEK_SET); // Reset the file position to the beginning for the next pass
	}

	free(randomData);
}

// here we open the file, and overwrite it
int secureDelete(const char *filename, int passes) {
	// Open the file in binary mode
	// this ensures we have the exact data without modifications
	FILE *file = fopen(filename, "rb+");
	if (file == NULL) {
		perror("Error opening file");
		return EXIT_FAILURE;
	}

	long size = getFileSize(file);

	// Overwrite the file with random data multiple times
	overwriteFile(file, size, passes);

	// close then delete the file
	fclose(file);
	if (remove(filename) != 0) {
		perror("Error deleting file");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
