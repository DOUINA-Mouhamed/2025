#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/sort.h"

void manageFile(char *inputFile)
{
    char outputFile[] = "sorted.csv";
    char **numbers = NULL;
    int count = 0;

    FILE *inFile = openFile(inputFile, "r");
    numbers = readNumbersDynamic(inFile, &count);

    qsort(numbers, count, sizeof(char *), compareNumbers);
    writeFile(outputFile, numbers, count);
    freeMemory(numbers, count);

    printf("Sorting completed. Output written to %s\n", outputFile);
}

int compareNumbers(const void *a, const void *b)
{
    const char *num1 = *(const char **)a;
    const char *num2 = *(const char **)b;

    size_t len1 = strlen(num1);
    size_t len2 = strlen(num2);

    if (len1 != len2) {
        return len1 - len2;
    }
    return strcmp(num1, num2);
}

FILE *openFile(char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("Error opening file");
        exit(84);
    }
    return file;
}

char **readNumbersDynamic(FILE *file, int *count)
{
    int capacity = 1000; // Initial capacity
    char **numbers = malloc(capacity * sizeof(char *));
    if (numbers == NULL) {
        perror("Memory allocation failed");
        exit(84);
    }

    *count = 0;
    char buffer[MAX_LENGTH];
    while (fscanf(file, "%99s", buffer) != EOF) {
        if (*count >= capacity) {
            capacity *= 2; // Double the capacity
            numbers = realloc(numbers, capacity * sizeof(char *));
            if (numbers == NULL) {
                perror("Memory reallocation failed");
                exit(84);
            }
        }

        numbers[*count] = malloc((strlen(buffer) + 1) * sizeof(char));
        if (numbers[*count] == NULL) {
            perror("Memory allocation failed");
            exit(84);
        }

        strcpy(numbers[*count], buffer);
        (*count)++;
    }

    fclose(file);
    return numbers;
}

void writeFile(char *filename, char **numbers, int n)
{
    FILE *file = openFile(filename, "w");

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s\n", numbers[i]);
    }

    fclose(file);
}

void freeMemory(char **numbers, int count)
{
    for (int i = 0; i < count; i++) {
        free(numbers[i]);
    }
    free(numbers);
}
