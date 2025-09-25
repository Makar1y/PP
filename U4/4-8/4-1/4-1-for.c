#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    double discriminant, x1, x2;

    printf("Please enter 3 separated numbers(a b c).\n");
    printf("There will be used to find quadratic equation (ax^2 + bx + c = 0) results(if it exists).\n\n");


    // Input
    printf("Please enter 3 whole numbers: ");
    for ( ; 1; ) {
        if ((scanf("%d %d %d", &a, &b, &c) == 3) && (getchar() == '\n')){
            break;
        } else {
            for ( ; getchar() != '\n'; );
            printf("Error, please enter 3 whole numbers, like that - 'a b c'\n: ");
        }
    };
    printf("\nNumbers entered successfully(a = %d, b = %d, c = %d).", a, b, c);


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