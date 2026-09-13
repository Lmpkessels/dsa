#include <stdio.h>
#include <stdbool.h>
#include "quick_sort.h"

bool four_sum(int arr[], int n, int target)
{
    int i, j, left, right, sum;

    // Sort the array such that working with left right becomes possible
    quick_sort(arr, 0, n - 1);

    for (i = 0; i < n - 3; i++) {
        for (j = i + 1; j < n - 2; j++) {
            left = i + 1;
            right = n - 1;
            
            // Search for a sum of for that will hit the target
            while (left < right) {
                sum = arr[i] + arr[j] + arr[left] + arr[right];

                // Return true when for added up indices equal the target
                if (sum == target) {
                    return true;
                }

                /* Move to the righ when the sum is < the target
                else move to the right */
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                }
            }
        }
    }

    return false;
}

int main(void)
{
    int arr[6] = {4, 1, 5, 3, 2, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    int tar = 13;

    // Returns True
    if (for_sum(arr, n, tar)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    tar = 200;

    // Returns False
    if (for_sum(arr, n, tar)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}