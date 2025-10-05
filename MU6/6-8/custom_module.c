#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Factorial counter
unsigned long get_factorial(const int number) {
    unsigned long result = 1;

    if (number < 1) {
        return 0;
    }

    for (int i = 1; i <= number; ++i) {
        result *= i; 
    }
    return result;
}


// Is string is valid number
int str_valid_number(const char *string_number, const double lower_bound, const double upper_bound, const int precision) {
    char *endptr;
    char buf[64];
    int len = strlen(string_number);
    double value;

    // Remove \n
    if (len > 0 && string_number[len - 1] == '\n') {
        ((char*)string_number)[len - 1] = '\0';
        len--;
    }

    // , -> . 
    strcpy(buf, string_number);
    for (int i = 0; buf[i]; i++) {
        if (buf[i] == ',')
            buf[i] = '.';
            break;
    }

    value = strtod(buf, &endptr);

    // error
    if (*endptr != '\0')
        return 0;

    // bounds check
    if (value < lower_bound || value > upper_bound)
        return 0;

    // check nums after , or .
    char *comma = strchr(string_number, ',');
    if (comma != NULL) {
        int fractional_len = strlen(comma + 1);
        if (fractional_len > precision)
            return 0;
    }

    return 1;
}
