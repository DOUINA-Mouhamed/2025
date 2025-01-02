#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/sort.h"

int compareNumbersDescending(const void *a, const void *b)
{
    const char *num1 = *(const char **)a;
    const char *num2 = *(const char **)b;

    size_t len1 = strlen(num1);
    size_t len2 = strlen(num2);

    if (len1 != len2) {
        return len2 - len1;
    }
    return strcmp(num2, num1);
}

void manageFileReverse(char *inputFile)
{
    char outputFile[] = "reverse_sorted.csv";
    char **numbers = malloc(MAX_LINES * sizeof(char *));

    if (numbers == NULL) {
        perror("Memory allocation failed");
        exit(84);
    }

    for (int i = 0; i < MAX_LINES; i++) {
        numbers[i] = malloc(MAX_LENGTH * sizeof(char));
        if (numbers[i] == NULL) {
            perror("Memory allocation failed");
            freeMemory(numbers, i);
            exit(84);
        }
    }

    FILE *inFile = openFile(inputFile, "r");
    int count = readNumbers(inFile, numbers);

    qsort(numbers, count, sizeof(char *), compareNumbersDescending);
    writeFile(outputFile, numbers, count);
    freeMemory(numbers, count);
    printf("Reverse sorting completed. Output written to %s\n", outputFile);
}
