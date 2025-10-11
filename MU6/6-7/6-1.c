#include <stdio.h>

#define ERROR_NUMS 5

int input_errors = ERROR_NUMS;

int main() {
    int input;
    char last_char;
    unsigned factorial = 1;
    

    printf("Entre number and program will calculate factorial and also save result ot file out.txt.\n");

    // Input
    while (1) {
        if (input_errors <= 0) {
            printf("!!! Exit program(0 tries left)");
            return 1;
        }
        printf(": ");
        if ( (scanf("%d%c", &input, &last_char) == 2) && (last_char == '\n') ) {
            if (input >= 0) {
                printf("Number %d entred successfully.\n", input);
                break;
            } else { 
                printf("!!! Error, number must be positive.\n");
                --input_errors;
                printf("!!! Tries left: %d\n", input_errors);
            }
            
        } else {
            while (last_char != '\n') {
                scanf("%c", &last_char);
            }
            printf("!!! Error, please enter whole number.\n");
            last_char = '\0'; // Clearing \n to proper work with next input error.
            
            --input_errors;
            printf("!!! Tries left: %d\n", input_errors);
        }
    }

    // Factorial
    for (int i = 1; i <= input; ++i) {
        factorial *= i; 
    }

    // Result printing
    if (factorial >= input) {
        printf("\n!%d = %u\n", input, factorial);
    } else {
        printf("\nError during calculations.\n");
        return 1;
    }
    
    // Saving to file
    FILE *result;

    result = fopen("out.txt", "w");
    if (result != NULL) {
        fprintf(result, "Result: !%d = %u", input, factorial);
        printf("Result successfully saved to out.txt");

        fclose(result);
    } else {
        printf("Could not save result to file:(\n");
    }
    return 0;
}