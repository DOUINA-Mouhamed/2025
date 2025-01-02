#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

int compareNumbers(const void *a, const void *b);
int compareNumbersDescending(const void *a, const void *b);

FILE *openFile(char *filename, const char *mode);
int readNumbers(FILE *file, char **numbers);
void writeFile(char *filename, char **numbers, int n);
void freeMemory(char **numbers, int count);

void manageFile(char *inputFile); // Ensure this declaration exists
void manageFileReverse(char *inputFile);
void measureSortingTime(char *inputFile, int reverse);

#endif
