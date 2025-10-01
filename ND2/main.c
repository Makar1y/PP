#include <stdio.h>

int main() {
    int n = 0;
    int j1 = 0, j2 = 0, j3 = 0;
    int max = 0, min = 0;


    // Entering number n
    printf("Please enter how numbers will be used: ");
    while(n <= 0) {
        while (1) {
            if (scanf("%d", &n) == 1 && getchar() == '\n') {
                break;
            } else {
                while (getchar() != '\n');
                printf("!!! Error, enter whole number: ");
            }
        }

        if (n <= 0) {
            printf("!!! Error, number must be positive: ");
        }
    }


    printf("\nNumber n=%d entered successfully.\n", n);
    printf("Now enter %d numbers.\n\n", n);


    // Array for nums
    // 0 - for entered nums
    // 1 - for [MIN , MIN+(MAX-MIN)/3] nums
    // 2 - for [MIN+(MAX-MIN)/3 , MIN+(MAX-MIN)*2/3] nums
    // 3 - for [MIN+(MAX-MIN)*2/3 , MAX] nums
    int nums[4][n];


    // N nums entering
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        while (1) {
            if (scanf("%d", &nums[0][i]) == 1 && getchar() == '\n') {
                break;
            } else {
                while (getchar() != '\n');
                printf("Error, try again: ");
            }
        }
    }



    // Preparing min, max
    for (int i = 0; i < n; i++) {
        if (i == 0)
            max = min = nums[0][i];
        else {
            if (max < nums[0][i])
                max = nums[0][i];
            else if (min > nums[0][i])
                min = nums[0][i];
        }
    }
    


    // Preparing [MIN , MIN+(MAX-MIN)/3]
    //                       |
    //     ------------------
    //    |
    int nums12 = min + (max - min) / 3;

    for (int i = 0; i < n; i++) {
        if ( (min <= nums[0][i]) && (nums[0][i] <= nums12) ) {
            nums[1][j1] = nums[0][i];
            j1++;
        }
    }



    // Preparing [MIN+(MAX-MIN)/3 , MIN+(MAX-MIN)*2/3]
    //                 |                        |
    //     ------------                         |
    //    |                                     |
    int nums21 = min + (max - min) / 3; //      |
    int nums22 = min + (max - min) * 2 / 3; // -|

    for (int i = 0; i < n; i++) {
        if ( (nums21 <= nums[0][i]) && (nums[0][i] <= nums22) ) {
            nums[2][j2] = nums[0][i];
            j2++;
        }
    }



    // Preparing [MIN+(MAX-MIN)*2/3 , MAX]
    //                 |
    //     ------------
    //    |
    int nums31 = min + (max - min) * 2 / 3;

    for (int i = 0; i < n; i++) {
        if ( (nums31 <= nums[0][i]) && (nums[0][i] <= max) ) {
            nums[3][j3] = nums[0][i];
            j3++;
        }
    }



// --------------------- Result printing

    // Print Min and Max
    printf("\n\nMin: %d    Max: %d", min, max);


    // Print [MIN , MIN+(MAX-MIN)/3]
    printf("\n\n[MIN , MIN+(MAX-MIN)/3] [%d, %d]", min, min+(max-min)/3);
    printf("\n{");
    for (int i = 0; i < j1; i++)
        if (i == 0)
            printf("%d", nums[1][i]);
        else
            printf(", %d", nums[1][i]);
    printf("}");


    // Print [MIN+(MAX-MIN)/3 , MIN+(MAX-MIN)*2/3]
    printf("\n\n[MIN+(MAX-MIN)/3 , MIN+(MAX-MIN)*2/3] [%d, %d]", min+(max-min)/3, min+(max-min)*2/3);
    printf("\n{");
    for (int i = 0; i < j2; i++)
    if (i == 0)
            printf("%d", nums[2][i]);
        else
            printf(", %d", nums[2][i]);
    printf("}");


    // Print [MIN+(MAX-MIN)*2/3 , MAX]
    printf("\n\n[MIN+(MAX-MIN)*2/3 , MAX] = [%d, %d]", min+(max-min)*2/3, max);
    printf("\n{");
    for (int i = 0; i < j3; i++)
        if (i == 0)
            printf("%d", nums[3][i]);
        else
            printf(", %d", nums[3][i]);
    printf("}");

    return 0;
}