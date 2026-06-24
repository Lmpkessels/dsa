/* Two pointers makes use of two indices, these are used to
access a data structure (in this case an array) to find a target

In this use case two pointers is used in two sum */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Two sum: find the target in an array
//
// If found return True, else False
bool two_sum(int arr[], int target, int n)
{
    int left, right;

    left = 0;
    right = n - 1;

    // Work towards the middle till the target is found
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            return true;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}

int main(void)
{
    int arr[6] = {2, 5, 13, 22, 28, 30};
    int target = 50;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Prints True
    if (two_sum(arr, target, n)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    target = 100;

    // Prints False
    if (two_sum(arr, target, n)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}