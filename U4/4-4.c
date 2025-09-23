#include <stdio.h>

int LCM(int a, int b, int c) {
    int an = a, bn = b, cn = c;
    while (1)
    {
        if(an > bn)
            bn += b;
        if(bn > an)
            an += a;

        if(cn > bn)
            bn += b;
        if(bn > cn)
            cn += c;

        if(an > cn)
            cn += c;
        if(cn > an)
            an += a;

        if (an == bn && bn == cn && an == cn)
            return an;
    }
}

int GCD(int a, int b, int c) {
    int i;

    // Euclidean algorithm
    while (b != 0) {
        i = b;
        b = a % b;
        a = i;
    }

    while (c != 0) {
        i = c;
        c = a % c;
        a = i;
        printf("%d", a);
    }

    return a;
}


int main() {
    int a, b, c;

    // Welcome
    printf("Please enter 3 separated whole numbers(a b c).\n");
    printf("There will be used to find LCM(Least Common Multiple) and GCD(Greatest Common Divisor).\n\n");


    // Input
    printf("Please enter 3 whole numbers: ");
    while (scanf("%d %d %d", &a, &b, &c) != 3) {
        while (getchar() != '\n');
        printf("Error, please enter 3 whole numbers, like that - 'a b c'\n: ");
    };

    
    printf("\nNumbers entered successfully(a = %d, b = %d, c = %d).", a, b, c);

    printf("\n\nResult:");
    printf("\nGCD = %d", GCD(a, b, c));
    printf("\nLCM = %d", LCM(a, b, c));
    return 0;
}