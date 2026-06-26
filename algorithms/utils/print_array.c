#include <stdio.h>
#include "print_array.h"

// Prints the sorted array
void print_array(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}