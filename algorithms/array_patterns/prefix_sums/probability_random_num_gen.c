//C program to generate random numbers according to given frequency distribution
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_num_gen(int [], int [], int);

int main(void)
{
    int arr[3]  = {30, 40, 50};
    int freq[3] = {3, 2, 6};
    
    int i, n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", random_num_gen(arr, freq, n));

    return 0;
}

// Find ceiling: get the ceiling (the smallest value of the prefix array
// >= r)
int find_ceiling(int pref[], int r, int low, int high)
{
    int mid;

    while (low < high) {
        mid = (low + high) / 2;
        ((r > pref[mid]) ? (low = mid + 1) : (high = mid));
    }

    return ((pref[low] >= r) ? low : -1);
}

// Random number generator: uses probability to generate a random number
// the frequency of the number increases the probability of the number 
// chosen within the array arr[]
int random_num_gen(int arr[], int freq[], int n)
{
    int i, r;
    int pref[n];
    int indexc;
    
    // Fill frequency for calculating the sum 'r' for
    // probability 
    pref[0] = freq[0];
    for (i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + freq[i];
    }

    // Generate random number for probability
    r = (rand() % pref[n - 1]) + 1;

    // Find the ceiling and assign it to indexc
    indexc = find_ceiling(pref, r, 0, n - 1);

    return arr[indexc];
}