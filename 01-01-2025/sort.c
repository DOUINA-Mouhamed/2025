#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

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

void usageSort(int n, char *str[])
{
    if (n != 2) {
        printf("How to use:\n\n%s <input.csv>\n", str[0]);
        exit(84);
    }
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

int readNumbers(FILE *file, char **numbers)
{
    int count = 0;

    while (fscanf(file, "%99s", numbers[count]) != EOF) {
        count++;
        if (count >= MAX_LINES) {
            printf("Error: Exceeded maximum line limit (%d).\n", MAX_LINES);
            fclose(file);
            exit(84);
        }
    }

    fclose(file);
    return count;
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

void manageFile(char *inputFile)
{
    char outputFile[] = "sorted.csv";
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

    qsort(numbers, count, sizeof(char *), compareNumbers);
    writeFile(outputFile, numbers, count);
    freeMemory(numbers, count);
    printf("Sorting completed. Output written to %s\n", outputFile);
}

int main(int argc, char *argv[])
{
    usageSort(argc, argv);
    manageFile(argv[1]);

    return 0;
}
