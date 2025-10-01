#include <stdio.h>

int main() {
    int n = 0;
    int i = 0;
    double max = 0, min = 0, sum = 0, average = 0;


    printf("Please enter positive number n, then n real numbers.\n");
    printf("Program will print n nums Min and Max values, Sum and Average.\n\n");


    // Entering number n
    printf("Please enter number n: ");
    do {
        do {
            if (scanf("%d", &n) == 1 && getchar() == '\n') {
                break;
            } else {
                do ; while (getchar() != '\n');
                printf("!!! Error, enter whole number: ");
            }
        } while (1);

        if (n < 0) {
            printf("!!! Error, how you enter %d numbers?\n", n);
            printf("    Number must be positive: ");
        } else if (n == 0) {
            printf("!!! Error, how will the program find the results if no numbers will be entered?\n");
            printf("    Number must be positive: ");            
        }
    } while(n <= 0);


    printf("\nNumber n=%d entered successfully.\n", n);
    printf("Now enter %d numbers.\n\n", n);


    // Array for entered nums
    double nums[n];


    // N nums entering
    do {
        printf("Enter number %d: ", i + 1);
        do {
            if (scanf("%lf", &nums[i]) == 1 && getchar() == '\n') {
                break;
            } else {
                do ; while (getchar() != '\n');
                printf("Error, try again: ");
            }
        } while (1);
        ++i;
    } while (i < n);



    // Preparing min, max
    i = 0;
    do {
        if (i == 0)
            max = min = nums[i];
        else {
            if (max < nums[i])
                max = nums[i];
            else if (min > nums[i])
                min = nums[i];
        }
        ++i;
    } while(i < n);


    // Preparing Sum
    i = 0;
    do {
        sum += nums[i];
        ++i;
    } while( i < n);


    // Preparing average
    average = sum / n;

    // Print Min and Max
    printf("\n\nMin: %lf    Max: %lf", min, max);
    printf("\nSum: %lf", sum);
    printf("\nAverage: %lf", average);

    return 0;
}