#include <stdio.h>

// Defining a struct
typedef struct 
{
    int day; // Object within struct
    int month;
    int year;
} Date;

int main(void)
{
    Date today; // Declaring struct today

    printf("Enter day, month, year: ");
    // Retrieving values
    scanf("%d %d %d", &today.day, &today.month, &today.year);

    printf("%d/%d/%d\n",
        today.day, // Accessing values
        today.month,
        today.year
    );

    return 0;
}