#include <stdio.h>


long long num_sort(long long x) {
    long long n = x;
    long long counter = 1;
    long long result = 0;


    if (x == 0) {
        return 0;
    } else if (x > 0) {
        for ( int i = 0; i < 10; i++ ) {
            while (n) {
                if (n % 10 == i) {
                    result += counter * (i);
                    counter *= 10;
                }
                n /= 10;
            }
            n = x;
        }
    } else {
        for ( int i = 0; i > -10; i-- ) {
            while (n) {
                if (n % 10 == i) {
                    result += counter * (i);
                    counter *= 10;
                }
                n /= 10;
            }
            n = x;
        }
    }

    return result;
    
}


int main() {
    long long number = 1;

    while (number) {

        printf("Enter number for sorting(zero to exit): ");
        if((scanf("%lld", &number) == 1) && (getchar() == '\n')) {
            number = num_sort(number);
            printf("Sorted number: %lld\n\n", number);
        } else {
            printf("    Invalid input, try again...\n");
            while(getchar() != '\n');
        }
    }

    return 0;
}