#include <stdio.h>

int main() {
    int a, b, c;

    // Welcome
    printf("Please enter 3 separated whole non negative numbers(a b c).\n");
    printf("There will be used to find F(c)=F(c-1) + F(c-2).\n");
    printf("Where F(0) = a and F(1) = b.\n\n");


    // Input
    printf("Please enter 3 whole numbers: ");
    while (1) {

        // Input
        while (scanf("%d %d %d", &a, &b, &c) != 3) {
            while (getchar() != '\n');
            printf("Error, please enter 3 whole numbers, like that - 'a b c'\n: ");
        };

        // Validation
        if ( (a >= 0) && (b >= 0) && (c >= 0) ) {
            break;
        } else {
            printf("\nError, all numbers must be non negative!\n\n");
            printf("Please enter 3 correct numbers: ");
        }
    }
    


    printf("\nNumbers entered successfully(a = %d, b = %d, c = %d).", a, b, c);

    int f[c+1];
    f[0] = a; f[1] = b;


    for (int i = 2; i <= c; ++i) {
        f[i] = f[i-1] + f[i-2];
    }


    // for (int i = 0; i <= c; ++i) {
    //     printf("\nF(%d) = %d", i, f[i]);
    // }


    // Print result
    printf("\n\nResult:");
    printf("\nF(c) = F(%d) = %d", c, f[c]);

    return 0;
}