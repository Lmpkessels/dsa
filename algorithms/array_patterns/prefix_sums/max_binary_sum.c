#include <stdio.h>

#define max(a,b) ((a) > (b) ? (a) : (b)) // Returns the greatest

int max_binary_sum(int [], int [], int);

int main(void)
{
    int arr1[10] = {
        0, 1, 0, 1, 0, 1, 0, 1, 0
    };

    int arr2[10] = {
        1, 0, 0, 1, 1, 0, 1, 0, 1
    };

    int n = sizeof(arr1) / sizeof(arr1[0]);

    printf("%d\n", max_binary_sum(arr1, arr2, n));
}

// Return the equal sum of the maxim subarray
int max_binary_sum(int arr1[], int arr2[], int n)
{
    int max_sum = 0;

    // Loop till the end of the array
    for (int i = 0; i < n; i++) {
        int equilibrium_sum1 = 0, equilibrium_sum2 = 0;

        // Loop for the subarray
        for (int j = i; j < n; j++) {
            // Get the sum of the subarray
            equilibrium_sum1 += arr1[j];
            equilibrium_sum2 += arr2[j];
            
            // Check if the subarrays are equal, if so update max_sum
            if (equilibrium_sum1 == equilibrium_sum2) {
                max_sum = max(max_sum, j - i + 1);
            }
        }
    }

    return max_sum;
}