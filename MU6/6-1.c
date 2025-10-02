#include <stdio.h>

int main() {
    int input;
    char last_char;
    unsigned factorial = 1;

    printf("Entre number and program will calculate factorial and also save result ot file out.txt.\n");

    // Input
    while (1) {
        printf(": ");
        if ( (scanf("%d%c", &input, &last_char) == 2) && (last_char == '\n') ) {
            if (input > 0) {
                printf("Number %d entred successfully.\n", input);
                break;
            } else { 
                printf("!!! Error, number must be positive.\n");
            }
            
        } else {
            while (last_char != '\n') {
                scanf("%c", &last_char);
            }
            printf("!!! Error, please enter whole number.\n");
        }
    }

    // Factorial
    for (int i = 1; i <= input; ++i) {
        factorial *= i; 
    }

    // Result printing
    printf("%u", factorial);
    if (factorial > input) {
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