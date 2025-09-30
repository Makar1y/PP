#include <stdio.h>

int main() {
    double s, input;
    int n, found = 0;

    printf("Please enter numbers s & n, then n positive values for these elements.\n");
    printf("Program will find all couples of elements where Xi * Xj = s\n");
    printf("s - real, n - positive whole.\n");
    printf("(s n): ");

    // First input
    while (1) {
        if (scanf("%lf%d", &s, &n) == 2 && getchar() == '\n') {
            if (n <= 0) {
                printf("Error, please enter positive number n.\n");
                printf("(s n): ");
            } else {
                printf("Numbers entered successfully, s=%lf n=%d.\n", s, n);
                break;
            }
        } else {
            while (getchar() != '\n');
            printf("Error, please enter numbers.\n");
            printf("(s n): ");
        }
    }

    double array[n];

    //  Num entering
    for (int i = 0; i < n; ++i) {
        printf("Enter X%d: ", i + 1);
        while (1) {
            if (scanf("%lf", &input) == 1 && getchar() == '\n'){
                printf("X%d = %lf\n\n", i + 1, input);
                break;
            } else {
                while (getchar() != '\n');
                printf("Error, enter number.");
            }
        }

        
        array[i] = input;
    }

    printf("Found couples:\n");

    // Couples finding
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ( (array[i] * array[j] == s) && (i != j) ){
                found = 1;
                printf("{%lf, %lf}\n", array[i], array[j] );
            }
        }
    }

    if (!found) {
        printf("not found:(\n");
    }

    return 0;
}