#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check_if_anagrams(char *, char *);

int main(void)
{
    char str1[] = "Hello";
    char str2[] = "eHlol";

    if (check_if_anagrams(str1, str2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}

// Compare is needed for qsort
int compare(const void *a, const void *b)
{
    return (*(char *)a)  - (*(char *)b);
}

// Sort both str1 and str2 than check if they're anagrams (
// if they both contain the same characters in frequency)
bool check_if_anagrams(char *str1, char *str2)
{
    if (strlen(str1) != strlen(str2)) { return false; }

    qsort(str1, strlen(str1), sizeof(char), compare);
    qsort(str2, strlen(str2), sizeof(char), compare);

    return strcmp(str1, str2) == 0;
}