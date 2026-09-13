#include <stdio.h>

/* Find the equilibrium, so incrementally grow a left sum
and a right sum till the left sum equals the right sum, if
it doesn't happen return -1 */
int find_the_equilibrium(int arr[], int n) 
{
    int i, j, k, left_sum, right_sum;

    // Check the indexes and sum them up in a left sum subarray,
    // and right sum subarray till the equilibrium is found
    for (i = 0; i < n; i++) {
        // Get the left sum
        left_sum = 0;
        for (j = 0; j < i; j++) {
            left_sum += arr[j];
        }
        
        // Get the right sum
        right_sum = 0;
        for (k = i + 1; k < n; k++) {
            right_sum += arr[k];
        }

        if (left_sum == right_sum) {
            return i;
        }
    }

    return -1;
}

int main(void) 
{
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", find_the_equilibrium(arr, n));
}