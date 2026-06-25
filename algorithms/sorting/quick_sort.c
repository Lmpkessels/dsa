#include <stdio.h>
#include "quick_sort.h"

void swap(int *a, int *b);

/* Partition, gets the index of where pivot needs to be
placed */
int partition(int arr[], int low, int high)
{
    int pivot, i, j;

    pivot = arr[high];
    i = low - 1;

    /* Get the index for the partition and move indices
    less then the pivot to the left side */
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Pivot is placed on the correct index
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/* Sort the array trough recursion which works like a 
kind of loop that updates the state of the data-structure 
at every itteration */
void quick_sort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Swap a with b
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prints the sorted array
void print_sorted_arr(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}