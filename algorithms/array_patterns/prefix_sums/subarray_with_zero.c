#include <stdio.h>
#include <stdbool.h>

// Check if the sum of a subarray equals 0
bool subarray_exists(int arr[], int n)
{
    // Loop from index 0...n
    for (int i = 0; i < n; i++) {
        int sum = arr[i]; // Check if an index equals 0
        if (sum == 0) {
            return true;
        }

        // Loop from index 1...n
        for (int j = i + 1; j < n; j++) {
            sum += arr[j]; // Add up each index to check if it equals 0
            if (sum == 0) {
                return true;
            }
        }
    }

    return false;
}

void print_result(int arr[], int n)
{   
    printf("If the subarray equals 0, then true is printed else false:\n");
    if (subarray_exists(arr, n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

int main(void)
{
    int arr[4] = {2, 3, -5, 1};

    int n;

    n = sizeof(arr) / sizeof(arr[0]);
    
    print_result(arr, n);

    int arr_one[4] = {4, 10, 2, 8};

    n = sizeof(arr_one) / sizeof(arr_one[0]);

    print_result(arr_one, n);

    return 0;
}