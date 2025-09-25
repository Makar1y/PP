#include <stdio.h>

int main() {
    int n = 0, i;
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


    // Array for nums
    // 0 - for entered nums
    // 1 - for [MIN , MIN+(MAX-MIN)/3]
    // 2 - for [MIN+(MAX-MIN)/3 , MIN+(MAX-MIN)*2/3]
    // 3 - for [MIN+(MAX-MIN)*2/3 , MAX]
    double nums[n];


    // N nums entering
    i = 0;
    while (i < n) {
        printf("Enter number %d: ", i + 1);
        while (1) {
            if (scanf("%lf", &nums[i]) == 1 && getchar() == '\n') {
                break;
            } else {
                while (getchar() != '\n');
                printf("Error, try again: ");
            }
        }
        ++i;
    }



    // Preparing min, max
    i = 0;
    while (i < n) {
        if (i == 0)
            max = min = nums[i];
        else {
            if (max < nums[i])
                max = nums[i];
            else if (min > nums[i])
                min = nums[i];
        }
        ++i;
    }


    // Preparing Sum
    i = 0;
    while (i < n) {
        sum += nums[i];
        ++i;
    }


    // Preparing average
    average = sum / n;

    // Print Min and Max
    printf("\n\nMin: %lf    Max: %lf", min, max);
    printf("\nSum: %lf", sum);
    printf("\nAverage: %lf", average);

    return 0;
}