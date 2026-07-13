#include <stdio.h>

/* Gets the max sum that can be achieved by adding up the
indices of subarrays, in this case 0..4 1..4 2..4, so 3
subarrays exist */
int max_subarray_sum(int arr[], int n)
{
    int i, j, curr_sum, max_sum;

    max_sum = arr[0];

    // Loop from 0..4 starting point for subarray
    for (i = 0; i < n; i++) {
        curr_sum = 0;

        // Loop from i..n ending point for subarray
        for (j = i; j < n; j++) {
            curr_sum = curr_sum + arr[j];
        }

        // Get the maximum sum
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
    }

    return max_sum;
}

int main(void)
{
    int arr[4] = {3, 4, 1, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", max_subarray_sum(arr, n));
}