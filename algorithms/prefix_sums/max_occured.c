#include <stdio.h>

#define MAX_RANGE 1000 // Max storage for frequency of numbers being count

int max_occured(int *, int *, int);

int main(void)
{
    int arr1[10] = {
        2, 2, 1, 3, 4, 3, 3, 2, 6, 9,
    };

    int arr2[10] = {
        2, 1, 1, 3, 4, 3, 1, 2, 5, 7,
    };

    int n = sizeof(arr1) / sizeof(arr1[0]);

    printf("%d\n", max_occured(arr1, arr2, n));
}

// Get the frequency of max occuring integer
int max_occured(int arr1[], int arr2[], int n)
{
    int i, j;
    int freq[MAX_RANGE] = {0};

    // Update the frequence per index, the index is the integer
    // that's why j = arr1[i]
    for (i = 0; i < n; i++) {
        for (j = arr1[i]; j <= arr2[i]; j++) {
            freq[j]++;
        }
    }

    int max_freq = 0;
    int result = -1;

    for (int value = 0; value < MAX_RANGE; value++) {
        // Get the frequency of most occureing integer
        if (freq[value] > max_freq) {
            max_freq = freq[value];
            result = value;
        }
    }

    return result;
}