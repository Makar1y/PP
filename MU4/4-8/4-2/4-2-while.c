#include <stdio.h>

int main() {
    int a, b, c, module;

    // Welcome
    printf("Please enter 3 separated numbers(a b c).\n");
    printf("There will be used to find all positive whole numbers from the interval (a; b] that are divisible by the number c with a remainder of 1.\n\n");


    // Input
    printf("Please enter 3 whole numbers: ");
    while (1) {
        if ((scanf("%d %d %d", &a, &b, &c) == 3) && (getchar() == '\n')){
            break;
        } else {
            while (getchar() != '\n');
            printf("Error, please enter 3 whole numbers, like that - 'a b c'\n: ");
        }
    };

    // Errors handling
    if (c == 0) {
        printf("\nError, c = 0. Cant divide by zero!");
        return 0;
    }

    printf("\nNumbers entered successfully(a = %d, b = %d, c = %d).", a, b, c);



    // Printing results
    printf("\n\nResult:\n");
    printf("{");
    int i = 1, j = 0;
    while (a + i <= b) {
        // Sign correction
        if (i + a < 0) {
            module = -1;
        } else {
            module = 1;
        }

        if ( ((i + a) % c == module)) {
            if (j == 0)
                printf("%d", a + i);
            else
                printf(", %d", a + i);
            ++j;
        }
        ++i;
    }
    printf("}");

    return 0;
}