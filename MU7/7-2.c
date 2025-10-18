#include <stdio.h>

int getFactorial_nrec(int number) {
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

int getFactorial(int number) {

    if (number == 0) {
        return 1;
    } else if (number < 0) {
        return 0;
    }

    return number * getFactorial(number - 1);
}

int main() {
    int num = 5;
    
    printf("%d ?= %d", getFactorial(num), getFactorial_nrec(num));
    return 0;
}