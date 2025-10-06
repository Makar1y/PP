#include <stdio.h>

int get_factorial(int number) {
    int factorial = 1;

    if (number == 0) {
        return 1;
    } else if (number < 0) {
        return 0;
    }

    for (int i = 1; i <= number; ++i) {
        factorial *= i; 
    }

    return factorial;
}

int get_factorial_rec(int number) {

    if (number == 0) {
        return 1;
    } else if (number < 0) {
        return 0;
    }

    return number * get_factorial_rec(number - 1);
}

int main() {
    int num = 10;
    
    printf("%d ?= %d", get_factorial_rec(num), get_factorial(num));
    return 0;
}