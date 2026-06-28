#include <stdio.h>

/* 
Trap water checks if the left and right side are > then the
middle if so water can get trapped if not water cannot be hold 
*/
int trap_water(int arr[], int n)
{
    int i, j, left, right, result;

    for (i = 1; i < n - 1; i++) {
        left = arr[i];
        /* Check if the index on the left side of 
        I > I if so assign I to left */
        for (j = 0; j < n; j++) {
            if (arr[j] > left) {
                left = arr[j];
            }
        }

        right = arr[i];
        /* Check if the index on the right side of 
        I > I if so assign I to right */
        for (j = i + 1; j < n - 2; j++) {
            if (arr[j] > right) {
                right = arr[j];
            }
        }

        /* Depending on left being > right return left 
        or right and subtract arr[i] to get the result 
        sum of water that can be trapped */
        result += (left > right ? left : right) - arr[i];
    }

    return result;
}

int main(void)
{
    int arr[3] = {3, 6, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", trap_water(arr, n));
}