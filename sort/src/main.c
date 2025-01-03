#include <stdio.h>
#include <string.h>
#include "../lib/sort.h"

void usageSort(int argc, char *argv[])
{
    if (argc < 2 || argc > 3) {
        printf("Usage: %s <input.csv> [-r]\n", argv[0]);
        exit(84);
    }
}

int main(int argc, char *argv[])
{
    usageSort(argc, argv);

    int reverse = (argc == 3 && strcmp(argv[2], "-r") == 0);
    measureSortingTime(argv[1], reverse);

    return 0;
}
