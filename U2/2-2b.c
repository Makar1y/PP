#include <stdio.h>


int binary_to_decimal(long long n) {
    int result = 0;
    int counter = 1;
    if (n == 0) return 0;
    
    while (n) {
        int last_digit = n % 10;
        n = n / 10;
        result += last_digit * counter;
        counter = counter * 2;
    }
    return result;
}

int decimal_to_binary(int n) {
    int n_save = n;
    long long result = 0;
    long long counter = 1;

    if (n == 0) {
        printf("This decimal number in binary is 0\n");
        return 0;
    }
    
    while (n) {
        result += counter * (n % 2);
        n = n / 2;
        counter *= 10;
    }
    printf("This decimal number %d in binary is %lld\n", n_save, result);
    return 0;
}

int main() {
    printf("Binary to decimal.\n\n");

    // long long binary1 = 11011;
    // long long binary2 = 10010100;
    // long long binary3 = 11001011010101;

    // int decimal1 = binary_to_decimal(binary1);
    // int decimal2 = binary_to_decimal(binary2);
    // int decimal3 = binary_to_decimal(binary3);

    // printf("This binary number %lld in decimal is %d\n", binary1, decimal1);
    // printf("This binary number %lld in decimal is %d\n", binary2, decimal2);
    // printf("This binary number %lld in decimal is %d\n\n\n", binary3,  decimal3);

    printf("This binary number 11011 in decimal is %d\n", 0b11011);
    printf("This binary number 10010100 in decimal is %d\n", 0b10010100);
    printf("This binary number 11001011010101 in decimal is %d\n\n\n", 0b11001011010101);




    printf("Decimal to binary.\n\n");

    int decimal1 = 37;
    int decimal2 = 241;
    int decimal3 = 2487;

    decimal_to_binary(decimal1);
    decimal_to_binary(decimal2);
    decimal_to_binary(decimal3);




    printf("\n\nHexadecimal to decimal.\n\n");

    int hexadecimal1 = 0x6E2;
    int hexadecimal2 = 0xED33;
    int hexadecimal3 = 0x123456;

    printf("This hexadecimal number %x in decimal is %d\n",hexadecimal1, hexadecimal1);
    printf("This hexadecimal number %x in decimal is %d\n",hexadecimal2, hexadecimal2);
    printf("This hexadecimal number %x in decimal is %d\n\n",hexadecimal3, hexadecimal3);
    



    printf("\nDecimal to hexadecimal.\n\n");

    decimal1 = 243;
    decimal2 = 2483;
    decimal3 = 4612;

    printf("This decimal number %d in hexadecimal is %x\n", decimal1, decimal1);
    printf("This decimal number %d in hexadecimal is %x\n", decimal2, decimal2);
    printf("This decimal number %d in hexadecimal is %x\n\n", decimal3, decimal3);



    getchar();
    return 0;
}