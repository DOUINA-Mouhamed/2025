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
        return len2 - len1; // Descending order by length
    }
    return strcmp(num2, num1); // Descending lexicographical order
}

void manageFileReverse(char *inputFile)
{
    char outputFile[] = "reverse_sorted.csv";
    char **numbers = NULL;
    int count = 0;

    FILE *inFile = openFile(inputFile, "r");
    numbers = readNumbersDynamic(inFile, &count); // Dynamically read lines

    qsort(numbers, count, sizeof(char *), compareNumbersDescending); // Sort in reverse order
    writeFile(outputFile, numbers, count); // Write sorted output
    freeMemory(numbers, count); // Free allocated memory

    printf("Reverse sorting completed. Output written to %s\n", outputFile);
}
