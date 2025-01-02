#include <time.h>
#include "../lib/sort.h"

void measureSortingTime(char *inputFile, int reverse)
{
    clock_t start, end;

    start = clock();
    if (reverse) {
        manageFileReverse(inputFile);
    } else {
        manageFile(inputFile);
    }
    end = clock();

    double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sorting time: %.6f seconds\n", elapsed_time);
}
