#include <stdio.h>

int get_digits(int num) {
    int digits = 1;

    do {
        if ((num /= 10) > 0){
            ++digits;
        }
    } while (num);
    return digits;
}

int main() {
    int num = 1;
    int digits;
    int result_number, result_number_digits = 0;
    // int current_number = 0, current_number_digits = 0;


    printf("Please enter whole positive numbers one by one and ending with negative one.\n");
    printf("The program will display the largest number with the largest number of digits.\n\n");


    // Entering numbers
    do {
        printf("Please enter number: ");
        do {
            if (scanf("%d", &num) == 1 && getchar() == '\n')
                break;
            else {
                do ; while (getchar() != '\n');
                printf("!!! Error, please enter whole number: ");
            }
        } while(1);

        digits = get_digits(num);
        if (digits > result_number_digits || result_number < num){
            result_number = num;
            result_number_digits = digits;
        }
    } while (num > 0);


    printf("\nLargest number with maximum digits: %d\n", result_number);
    printf("Digits: %d", result_number_digits);

    return 0;
}