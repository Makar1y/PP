#include <stdio.h>

int main() {
    int n = 0;
    int w_break = 0, i;
    double max = 0, min = 0, sum = 0, average = 0;


    printf("Please enter positive number n, then n real numbers.\n");
    printf("Program will print n nums Min and Max values, Sum and Average.\n\n");


    // Entering number n
    printf("Please enter number n: ");
    while1: {
        while2: {
            if (scanf("%d", &n) == 1 && getchar() == '\n') {
                w_break = 1;
            } else {
                while3:
                if (getchar() != '\n') goto while3;
                printf("!!! Error, enter whole number: ");
            }
        } if (!w_break) goto while2; w_break = 0;

        if (n < 0) {
            printf("!!! Error, how you enter %d numbers?\n", n);
            printf("    Number must be positive: ");
        } else if (n == 0) {
            printf("!!! Error, how will the program find the results if no numbers will be entered?\n");
            printf("    Number must be positive: ");            
        }
    } if (n <= 0) goto while1; w_break = 0;


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
    for1: {
        printf("Enter number %d: ", i + 1);
        while4: {
            if (scanf("%lf", &nums[i]) == 1 && getchar() == '\n') {
                w_break = 1;
            } else {
                while5:
                if (getchar() != '\n') goto while5;
                printf("Error, try again: ");
            }
        } if (!w_break) goto while4; w_break = 0;
        ++i;
    } if (i < n) goto for1;



    // Preparing min, max
    i = 0;
    for2: {
        if (i == 0)
            max = min = nums[i];
        else {
            if (max < nums[i])
                max = nums[i];
            else if (min > nums[i])
                min = nums[i];
        }
        ++i;
    } if (i < n) goto for2;


    // Preparing Sum
    i = 0;
    for3: {
        sum += nums[i];
        ++i;
    } if (i < n) goto for3;


    // Preparing average
    average = sum / n;

    // Print Min and Max
    printf("\n\nMin: %lf    Max: %lf", min, max);
    printf("\nSum: %lf", sum);
    printf("\nAverage: %lf", average);

    return 0;
}