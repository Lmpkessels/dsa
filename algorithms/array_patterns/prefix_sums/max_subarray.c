#include <stdio.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b)) // Return the greatest

// Find the subarray size for the max sum
int max_subarray_size(int arr[], int n, int k) 
{
    int answer = -1;

    for (int i = 1; i <= n; i++) {
        int max_sum = INT_MIN;

        // Get the subarrays
        for (int j = 0; j < n - i + 1; j++) {
            
            int sum = 0;
            // Get the sum of all subarrays
            for (int l = j; l < j + i; l++) {
                sum += arr[l];
            }

            // Assign the max sum
            max_sum = MAX(max_sum, sum);
        }

        if (max_sum <= k) {
            answer = MAX(answer, i);
        }
    }

    return answer;
}

int main(void)
{
    int arr[4] = {1, 2, 3, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 8;

    printf("%d\n", max_subarray_size(arr, n, k));
}