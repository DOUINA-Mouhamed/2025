#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length for each line (number as string)
#define MAX_LENGTH 100

// Function to compare numbers in ascending order
int compareNumbers(const void *a, const void *b);

// Function to compare numbers in descending order
int compareNumbersDescending(const void *a, const void *b);

// Open a file with the specified mode
FILE *openFile(char *filename, const char *mode);

// Dynamically read numbers from a file, returning an array of strings
// and updating the count of numbers read
char **readNumbersDynamic(FILE *file, int *count);

// Write sorted numbers to a file
void writeFile(char *filename, char **numbers, int n);

// Free dynamically allocated memory for numbers
void freeMemory(char **numbers, int count);

// Manage file for normal (ascending) sorting
void manageFile(char *inputFile);

// Manage file for reverse (descending) sorting
void manageFileReverse(char *inputFile);

// Measure sorting time for both ascending and descending sorts
void measureSortingTime(char *inputFile, int reverse);

#endif
