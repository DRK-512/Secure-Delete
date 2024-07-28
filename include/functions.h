#ifndef FUNCTIONS
#define FUNCTIONS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int secureDelete(const char *filename, int passes); 
void overwriteFile(FILE *file, long size, int passes); 
long getFileSize(FILE *file); 

#endif
