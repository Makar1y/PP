#include <stdio.h>

int main() {
    int a, b, c, module;
    int w_break = 0;

    // Welcome
    printf("Please enter 3 separated numbers(a b c).\n");
    printf("There will be used to find all positive whole numbers from the interval (a; b] that are divisible by the number c with a remainder of 1.\n\n");


    // Input
    printf("Please enter 3 whole numbers: ");
    while1:
    if ((scanf("%d %d %d", &a, &b, &c) == 3) && (getchar() == '\n')){
        w_break++;
    } else {
        while2:
        if (getchar() != '\n') goto while2;
        printf("Error, please enter 3 whole numbers, like that - 'a b c'\n: ");
    }
    if ( !w_break ) goto while1;

    // Errors handling
    if (c == 0) {
        printf("\nError, c = 0. Cant divide by zero!");
        return 0;
    }

    printf("\nNumbers entered successfully(a = %d, b = %d, c = %d).", a, b, c);



    // Sign correction
    if (c < 0) {
        module = -1;
    } else {
        module = 1;
    }

    // Printing results
    printf("\n\nResult:\n");
    printf("{");
    int i = 1, j = 0;
    for1:
    if ( ((i + a) % c == module) && (i + a >=0) ) {
        if (j == 0)
            printf("%d", a + i);
        else
            printf(", %d", a + i);
        ++j;
    }
    ++i;
    if (a + i <= b) goto for1;
    printf("}");

    return 0;
}