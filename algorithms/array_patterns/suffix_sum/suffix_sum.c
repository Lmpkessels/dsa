#include <stdio.h>

/* Store the sum of the current index in arr[n] till
the end of arr[n] in suff_sum[n] */
int suffix_sum(int arr[], int suff_sum[], int n)
{
    int i, j;

    // Initialize suff_sum[i] with 0s
    for (i = 0; i < n; i++) {
        suff_sum[i] = 0;
    }

    // Initialize suff_sum[i] with the decremental 
    // sum of arr[j] going from, 0...n, 1...n, and so
    // on till the last index of the array
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            suff_sum[i] += arr[j];
        }
    }
}

int main(void)
{
    int arr[6] = {3, 2, 1, 5, 4, 6};
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int suff_sum[n];

    suffix_sum(arr, suff_sum, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", suff_sum[i]);
    }

    printf("\n");
}