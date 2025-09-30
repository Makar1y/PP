#include <stdio.h>
#include <math.h>

#define SIZE 99999

// 1 - prime
int prime_check(int num) {
    if (num == 1)
        return 0;
    
    float square_root = sqrtf((float)num);

    for (int i = 2; i <= square_root; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}


int main() {
    int input, found;
    int prime_nums = 0;
    int array[2][SIZE] = {0};

    printf("Please enter positive numbers one by one and ending with non positive one.\n");
    printf("Program will print all prime numbers.\n");

    // Input
    for (int i; input > 0 && i<SIZE; ++i) {
        printf("Please enter number: ");
        while(1) {
            if (scanf("%d", &input) == 1 && getchar() == '\n') {
                if (input > 0) {
                    printf("Number entered successfully.\n");
                    break;
                } else {
                    break;
                }
            }
            else {
                while (getchar() != '\n');
                printf("!!! Error, please enter whole number: ");
            }
        }


        if (input <= 0) {
            break;
        }

        array[0][i] = input;

        if (prime_check(input)) {
            for (int j = 0; j < prime_nums; ++j) {
                if (array[1][j] == input) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                array[1][prime_nums] = input;
                ++prime_nums;
            } found = 0;
        }
    }

    // Result printing
    if (prime_nums) {
        printf("\nFound %d results:\n", prime_nums);
        printf("{");
        for (int i = 0; i < prime_nums; ++i) {
            if (i != 0) {
                printf(", %d", array[1][i]);
            } else {
                printf("%d", array[1][i]);
            }
        }
        printf("}\n");
    } else {
        printf("Not found prime numbers:(\n");
    }

    return 0;
}