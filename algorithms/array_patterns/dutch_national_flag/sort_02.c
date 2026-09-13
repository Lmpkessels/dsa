#include <stdio.h>

void sort_02(int [], int);

int main(void)
{
    int arr[] = {
        0, 2, 1, 0, 0, 2, 1, 1, 0, 2, 2, 2, 2, 1, 0
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    sort_02(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}

// sort_02: sorts an array of 0s 1s and 2s
void sort_02(int arr[], int n)
{
    int i;
    int count_0, count_1, count_2;

    count_0 = count_1 = count_2 = 0;

    // Count 0s, 1s, and 2s
    for (i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count_0++;
        } else if (arr[i] == 1) {
            count_1++;
        } else {
            count_2++;
        }
    }

    int indx = 0;
    // Sort 0s, 1s, 2s, and place them in order
    // 
    // Place 0s at the right indices
    for (i = 0; i < count_0; i++) {
        arr[indx++] = 0;
    }

    // Place 1s at the right indices
    for (i = 0; i < count_1; i++) {
        arr[indx++] = 1;
    }

    // Place 2s at the right indices
    for (i = 0; i < count_2; i++) {
        arr[indx++] = 2;
    }
}