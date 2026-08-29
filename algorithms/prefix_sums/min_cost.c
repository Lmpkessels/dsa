#include <stdio.h>
#include <stdlib.h>

int min_cost_coins(int [], int, int); 

int main(void)
{
    int coins[4] = {4, 7, 2, 1};

    int n = sizeof(coins) / sizeof(coins[0]);

    int k = 3;

    printf("%d\n", min_cost_coins(coins, k, n));
}

// Compare a with b so qsort knows which number comes first
int compare(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) {
        return -1;
    } 
    
    if (x > y) {
        return 1;
    }

    return 0;
}

// Min cost coins: returns the minimum cost after receiving 'k' 
// for acquiring all 'n' coins
//
// 'k' serves as the amount of free coins that can be received after buying
// 1 coin
int min_cost_coins(int coins[], int n, int k)
{
    qsort(coins, n, sizeof(int), compare);

    // Get the amount of coins needed to acquire all coins
    int coins_needed = (n + k) / (k + 1);

    int min_cost = 0;
    for (int i = 0; i < coins_needed; i++) {
        // Update the minimum cost for as many coins are needed to get
        // all coins
        min_cost += coins[i];
    }

    return min_cost;
}