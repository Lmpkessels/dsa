#include <stdio.h>
#include <math.h>
#include <limits.h>

/* Max: returns the max value of either num1 or num2 depending
on which one is greater then */
int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

/* Max sum: returns the maximal sum of a window which is depending
on k. So if k = 3 then the indices used is 3 which makes the window 3 */
int max_sum(int arr[], int n, int k)
{
    int i, j, max_sum, current_sum;

    max_sum = INT_MIN;

    // Get the maximal sum
    for (i = 0; i < n - k + 1; i++) {
        current_sum = 0;
        for (j = 0; j < k; j++) {
            current_sum = current_sum + arr[i + j];
        }

        max_sum = max(current_sum, max_sum);
    }

    return max_sum;
}

int main(void)
{
    int arr[6] = {10, 11, 2, 0, 8, 22};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    printf("%d\n", max_sum(arr, n, k));
}