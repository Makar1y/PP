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
    int array[SIZE] = {0};

    printf("Please enter positive numbers one by one and ending with non positive one(max %d nums).\n", SIZE);
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

        if (prime_check(input)) {
            for (int j = 0; j < prime_nums; ++j) {
                if (array[j] == input) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                array[prime_nums] = input;
                ++prime_nums;
            } found = 0;
        }

        if (i == SIZE - 1) {
            printf("Bound limits.\n");
        }
    }



    // Result printing
    printf("\nFound results:\n");
    if (prime_nums) {
        printf("{");
        for (int i = 0; i < prime_nums; ++i) {
            if (i != 0) {
                printf(", %d", array[i]);
            } else {
                printf("%d", array[i]);
            }
        }
        printf("}\n");
    } else {
        printf("Not found prime numbers:(\n");
    }

    return 0;
}