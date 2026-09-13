#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "quick_sort.h"

#define max(a, b) ((a > b) ? a : b) // A is returned when greater then B
                                    // else B

int closest_to_zero(int arr[], int n)
{
    int i, x, left, right, middle, result, current;
    
    quick_sort(arr, 0, n - 1);

    result = INT_MAX;

    for (i = 0; i < n; i++) {
        left = i + 1;
        right = n - 1;

        x = arr[i];

        while (left <= right) {
            middle = (left + right) / 2;

            current = arr[middle] + x;

            // Return 0 if the current sum is already 0
            if (current == 0) {
                return 0;
            }

            // Find the closest to 0
            if (abs(current) < abs(result)) {
                result = current;
            } else if (abs(current) == abs(result)) {
                result = max(result, current);
            }

            /* If curr is less then 0 move to right
             if not move to left*/
            if (current < 0) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
    }

    return result;
}

int main(void)
{
    int arr[6] = {4, 10, 1, 9, 5, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", closest_to_zero(arr, n));
}