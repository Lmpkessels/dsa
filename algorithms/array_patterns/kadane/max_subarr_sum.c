#include <stdio.h>

int max_subarr_sum(int arr[], int n);

int main(void)
{
    int arr[10] = {10, 11, 2, -4, 8, 6, 22, 3, 202, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", max_subarr_sum(arr, n));

    return 0;
}

// Find the max subarray sum of arr[n]
int max_subarr_sum(int arr[], int n)
{
    int i, j;
    int max_sum, curr_sum;

    max_sum = arr[0];

    // Loop from 0..n
    for (i = 0; i < n; i++) {
        curr_sum = 0;
        // Loop from j..n
        for (j = i; j < n; j++) {
            curr_sum = curr_sum + arr[j];
        }

        // Get the max sum
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
    }

    return max_sum;
}