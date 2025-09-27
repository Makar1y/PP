#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    int i = 0;
    double discriminant = 0, x1 = 0, x2 = 0;

    printf("Please enter 3 separated numbers(a b c).\n");
    printf("There will be used to find quadratic equation (ax^2 + bx + c = 0) results(if it exists).\n\n");


    // Input
    printf("Please enter 3 whole numbers: ");
    while1:
        if ((scanf("%d %d %d", &a, &b, &c) == 3) && (getchar() == '\n')){
            i = 1;
        } else {
            while2:
            if (getchar() != '\n') goto while2;
            printf("Error, please enter 3 whole numbers, like that - 'a b c'\n: ");
        }
    if ( !i ) goto while1;
    printf("\nNumbers entered successfully(a = %d, b = %d, c = %d).", a, b, c);

    
    if (a == 0 && b != 0) {
        x1 = -c/b;
        printf("\n\nResult:");
        printf("\nx = %lf", x1);
        return 0;
    } else if (a == 0 && b == 0) {
        printf("\n\nResult:");
        printf("\nx = R(real number)");
        return 0;
    }


    // Discriminant calculation
    discriminant = (b * b) - (4 * a * c);
    printf("\n\nDiscriminant = %lf", discriminant);

    // Two results
    if (discriminant > 0) {
        x1 = ( -b + sqrt(discriminant) ) / (2 * a);
        x2 = ( -b - sqrt(discriminant) ) / (2 * a);

        printf("\nThere are two results for quadratic equation with these numbers:\n");
        printf("x1 = %lf\n", x1);
        printf("x2 = %lf", x2);


    // One result
    } else if (discriminant == 0) {
        x1 = ( -b + sqrt(discriminant) ) / (2 * a);

        printf("\nThere are one result for quadratic equation with these numbers:\n");
        printf("x = %lf", x1);


    // Zero results
    } else if (discriminant < 0) {
        printf("\nThere are zero non complex results for quadratic equation with these numbers.");
    }

    return 0;
}