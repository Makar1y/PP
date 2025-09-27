#include <stdio.h>

int main() {
    int n = 0;
    double max = 0, min = 0, sum = 0, average = 0;


    printf("Please enter positive number n, then n real numbers.\n");
    printf("Program will print n nums Min and Max values, Sum and Average.\n\n");


    // Entering number n
    printf("Please enter number n: ");
    while(n <= 0) {
        while (1) {
            if (scanf("%d", &n) == 1 && getchar() == '\n') {
                break;
            } else {
                while (getchar() != '\n');
                printf("!!! Error, enter whole number: ");
            }
        }

        if (n < 0) {
            printf("!!! Error, how you enter %d numbers?\n", n);
            printf("    Number must be positive: ");
        } else if (n == 0) {
            printf("!!! Error, how will the program find the results if no numbers will be entered?\n");
            printf("    Number must be positive: ");            
        }
    }


    printf("\nNumber n=%d entered successfully.\n", n);
    printf("Now enter %d numbers.\n\n", n);


    // Array for entered nums
    double nums[n];


    // N nums entering
    for (int i = 0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        while (1) {
            if (scanf("%lf", &nums[i]) == 1 && getchar() == '\n') {
                break;
            } else {
                while (getchar() != '\n');
                printf("Error, try again: ");
            }
        }
    }



    // Preparing min, max
    for (int i = 0; i < n; ++i) {
        if (i == 0)
            max = min = nums[i];
        else {
            if (max < nums[i])
                max = nums[i];
            else if (min > nums[i])
                min = nums[i];
        }
    }


    // Preparing Sum
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
    }


    // Preparing average
    average = sum / n;

    // Print Min and Max
    printf("\n\nMin: %lf    Max: %lf", min, max);
    printf("\nSum: %lf", sum);
    printf("\nAverage: %lf", average);

    return 0;
}