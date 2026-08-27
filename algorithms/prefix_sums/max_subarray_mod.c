#include <stdio.h>

#define INTS_IN_ARR_BUFF 100 // Max amount of integers allowed in arr
#define max(a, b) ((a) > (b) ? (a) : (b)) // Return the max value

int max_sub_mod(int [], int, int);

int main(void)
{
    int arr[INTS_IN_ARR_BUFF] = {3, 3, 9, 9, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    int m = 7;

    printf("%d\n", max_sub_mod(arr, m, n));
}

// Get the max modulo of the subarray
int max_sub_mod(int arr[], int m, int n)
{
    int i, j;
    int max_mod, sum;

    max_mod = 0;
    for (i = 0; i < n; i++) {
        sum = 0;
        
        for (j = i; j < n; j++) {
            sum += arr[j];
            
            max_mod = max(max_mod, sum % m);
        }
        
    }

    return max_mod;
}