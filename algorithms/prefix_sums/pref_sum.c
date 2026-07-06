#include <stdio.h>

/* Increment the sum with the next number in arr[] and
store them in pref_sum

starting with pref_sum[0] = arr[0] = 3, then, 
pref_sum[1] = pref_sum[0] + arr[1] = 5, and so on... */ 
int prefix_sum(int arr[], int pref_sum[], int n)
{
    pref_sum[0] = arr[0];

    for (int i = 1; i < n; i++) {
        pref_sum[i] = pref_sum[i - 1] + arr[i];
    }
}

int main(void)
{
    int arr[6] = {3, 2, 1, 5, 7, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    int pref_sum[n];

    prefix_sum(arr, pref_sum, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", pref_sum[i]);
    }

    printf("\n");
}