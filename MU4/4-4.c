#include <stdio.h>

int LCM(int a, int b, int c) {
    int an = a, bn = b, cn = c;

    if (!a){
        printf("\na = 0, cant find LCM"); return 0;
    } else if (!b){
        printf("\nb = 0, cant find LCM"); return 0;
    } else if (!c){
        printf("\nc = 0, cant find LCM"); return 0;
    }

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
        if (b == 0) {
            break;
        }
        i = b;
        b = a % b;
        a = i;
    }

    while (c != 0) {
        if ( c == 0 ) {
            break;
        }
        i = c;
        c = a % c;
        a = i;
    }

    return a;
}


int main() {
    int a, b, c;

    // Welcome
    printf("Please enter 3 separated whole natural numbers(a b c).\n");
    printf("There will be used to find LCM(Least Common Multiple) and GCD(Greatest Common Divisor).\n\n");


    // Input
    printf("Please enter 3 whole numbers: ");
    while (1) {
        if ((scanf("%d %d %d", &a, &b, &c) == 3) && (getchar() == '\n')){
            if (a >= 0 && b >= 0 && c >= 0)
                break;
            else {
                printf("Error, please enter 3 natural numbers: ");
            }
        } else {
            while (getchar() != '\n');
            printf("Error, please enter 3 whole numbers, like that - 'a b c'\n: ");
        }
    }

    
    printf("\nNumbers entered successfully(a = %d, b = %d, c = %d).", a, b, c);
    int lcm = LCM(a, b, c);
    int gcd = GCD(a, b, c);

    printf("\n\nResult:");
    printf("\nGCD = %d", gcd);
    if (lcm)
        printf("\nLCM = %d", lcm);
    return 0;
}