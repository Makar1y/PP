#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000

// return random number from [a, b]
double r_num(double a, double b) {

    return (b - a) * ((double)rand() / RAND_MAX ) + a;
}

int main() {
    double array[SIZE] = {0};
    double a, b;
    int c;

    srand(time(NULL));

    //
    printf("Please enter numbers a, b, c to generate c random elements from [a, b].\n");
    printf("a and b real numbers and c whole natural number.\n");
    printf("(a b c): ");
    while (1)
    {
        if (scanf("%lf%lf%d", &a, &b, &c) == 3 && getchar() == '\n') {
            if (c < 0 || c > 1000) {
                printf("Error, please enter natural c number that not greater than 1000.\n");
                printf("(a b c): ");
            } else {
                printf("Numbers entered successfully, a=%lf b=%lf c=%d.\n", a, b, c);
                break;
            }
        } else {
            while (getchar() != '\n');
            printf("Error, please enter 3 numbers(last one whole natural).\n");
            printf("(a b c): ");
        }
    }

    for (int i = 0; i < c; ++i) {
        array[i] = r_num(a, b);
    }

    printf("Array = {");
    for (int i = 0; i < c; ++i) {
        if (i != 0) {
            printf(", %lf", array[i]);
        } else {
            printf("%lf", array[i]);
        }
    }
    printf("}\n");
    
    return 0;
}