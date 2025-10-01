#include <stdio.h>

int get_digits(int num) {
    int digits = 1;

    gd_while: {
        if ((num /= 10) > 0){
            ++digits;
        }
    } if (num) goto gd_while;
    return digits;
}

int main() {
    int num = 1;
    int digits;
    int w_break = 0;
    int result_number, result_number_digits = 0;
    // int current_number = 0, current_number_digits = 0;


    printf("Please enter whole positive numbers one by one and ending with negative one.\n");
    printf("The program will display the largest number with the largest number of digits.\n\n");


    // Entering numbers
    while1: {
        printf("Please enter number: ");
        while2: {
            if (scanf("%d", &num) == 1 && getchar() == '\n')
                w_break = 1;
            else {
                while3:
                if (getchar() != '\n') goto while3;
                printf("!!! Error, please enter whole number: ");
            }
        } if (!w_break) goto while2; w_break = 0;

        digits = get_digits(num);
        if (digits > result_number_digits || result_number < num){
            result_number = num;
            result_number_digits = digits;
        }
    } if (num > 0) goto while1;


    printf("\nLargest number with maximum digits: %d\n", result_number);
    printf("Digits: %d", result_number_digits);

    return 0;
}