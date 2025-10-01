#include <stdio.h>

int main() {
    int a, b, c;
    int w_break = 0;

    // Welcome
    printf("Please enter 3 separated whole non negative numbers(a b c).\n");
    printf("There will be used to find F(c)=F(c-1) + F(c-2).\n");
    printf("Where F(0) = a and F(1) = b.\n\n");


    // Input
    printf("Please enter 3 whole numbers: ");
    while1: {
        while2: {
            if ((scanf("%d %d %d", &a, &b, &c) == 3) && (getchar() == '\n')){
                w_break = 1;
            } else {
                while3:
                if (getchar() != '\n') goto while3;
                printf("Error, please enter 3 whole numbers, like that - 'a b c'\n: ");
            }
        }
        if (!w_break) goto while2;
        w_break = 0;

        // Validation
        if ( (a >= 0) && (b >= 0) && (c >= 0) ) {
            w_break = 1;
        } else {
            printf("\nError, all numbers must be non negative!\n\n");
            printf("Please enter 3 correct numbers: ");
        }
    }
    if (!w_break) goto while1;
    


    printf("\nNumbers entered successfully(a = %d, b = %d, c = %d).", a, b, c);

    int f[c+1];
    f[0] = a; f[1] = b;

    int i = 2;
    for1: {
        f[i] = f[i-1] + f[i-2];
        ++i;
    }
    if (i <= c) goto for1;

    // for (int i = 0; i <= c; ++i) {
    //     printf("\nF(%d) = %d", i, f[i]);
    // }


    // Print result
    printf("\n\nResult:");
    printf("\nF(c) = F(%d) = %d", c, f[c]);

    return 0;
}