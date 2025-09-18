#include <stdio.h>

int main() {
    int n;

    printf("Please enter number: ");
    while (scanf("%d", &n) != 1 && getchar() != '\n') {
        while (getchar() != '\n');
        printf("Error, try again: ");
    }
    printf("\nNumber entered successfully.\n\n");




    int nums[n];

    for (int i = 0; i < n; i++) {
        printf("Enter %d number: ", i + 1);
        while (scanf("%d", &nums[i]) != 1 && getchar() != '\n') {
            while (getchar() != '\n');
            printf("Error, try again: ");
        }
    }




    int max, min;

    for (int i = 0; i < n; i++) {
        if (i == 0)
            max = nums[i], min = nums[i];
        else {
            if (max < nums[i])
                max = nums[i];
            else if (min > nums[i])
                min = nums[i];
        }
    }
    



    //



    printf("\n\nMin: %d    Max: %d", min, max);
    return 0;
}