#include <stdio.h>
#include <stdbool.h>
#include "quick_sort.h"

bool three_sum(int arr[], int n, int target)
{
    int i, left, right, requered_sum;

    quick_sort(arr, 0, n - 1);

    // Get the first index to check for the triplet
    for (i = 0; i < n - 2; i++) {
        left = i + 1;
        right = n - 1;

        /* 
        Subtract such that the target can be check with left, right
    
        e.g. 34 - 7 = 27 so if arr[left] + arr[right] == 27 then the
        triplet is found 
        */
        requered_sum = target - arr[i];
        while (left < right) {
            if (arr[left] + arr[right] == requered_sum) {
                return true;
            }

            // Move 1 step to the right when less then else 1 step left
            if (arr[left] + arr[right] < requered_sum) {
                left++;
            } else if (arr[left] + arr[right] > requered_sum) {
                right--;
            }
        }
    }

    return false;
}

int main(void)
{
    int arr[6] = {3, 5, 1, 9, 10, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    int tar = 20;

    // Returns True
    if (three_sum(arr, n, tar)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    tar = 200;

    // Returns False
    if (three_sum(arr, n, tar)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}