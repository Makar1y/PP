#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAIL_PART_SIZE 100

// Factorial counter
unsigned long get_factorial(const int number) {
    unsigned long result = 1;

    if (number == 0) {
        return 1;
    } else if (number < 0) {
        return 0;
    }

    for (int i = 1; i <= number; ++i) {
        result *= i; 
    }
    return result;
}

// Is string is valid number
int str_valid_number(char *string_number, const double lower_bound, const double upper_bound, const int precision) {
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
        if (buf[i] == ',') {
            buf[i] = '.';
            break;
        }
    }

    value = strtod(buf, &endptr);

    // error
    if (*endptr != '\0')
        return 0;

    // bounds check
    if (value < lower_bound || value > upper_bound)
        return 0;

    // check nums after , or .
    char *comma = strchr(buf, '.');
    if (comma != NULL) {
        int fractional_len = strlen(comma + 1);
        if (fractional_len > precision)
            return 0;
    }

    return 1;
}

// Find middle number
long middle_num(const long num1, const long num2, const long num3) {
    long result;

    if ((num1 >= num2 && num1 <= num3) || (num1 <= num2 && num1 >= num3)) {
        result = num1;
    } else if ((num2 >= num1 && num2 <= num3) || (num2 <= num1 && num2 >= num3)) {
        result = num2;
    } else {
        result = num3;
    }

    return result;
}

// if string ends with string
int str_end_with(const char string[], const char ends[]) {
    int string_len = strlen(string);
    int ending_len = strlen(ends);
    if (string_len > ending_len) {
        return strcmp(string + string_len - ending_len, ends) == 0; 
    }
    return 0;
}

// If date nums is correct
int is_date_exist(const int year, const int month, const int day) {
    if (year < 1 || (month < 1 || month > 12) || (day < 1 || day > 31)) {
        return 0;
    }

    int leap = ( (((year % 4) == 0) && ((year % 100) != 0))   ||   ((year % 400) == 0) ) ? 1 : 0;
    int month_days;

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            month_days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            month_days = 30;
            break;
        case 2:
            month_days = (leap) ? 29 : 28;
            break;
        default:
            return 0;
    }

    return day <= month_days;
}

// Date entering/validation
int scan_date_yyyy_mm_dd(int *year, int *month, int *day) {
    char year_s[5], month_s[5], day_s[5];
    int year_i, month_i, day_i;

    if (scanf("%4[0-9]-%2[0-9]-%2[0-9]", year_s, month_s, day_s) == 3 && getchar() == '\n') {
        if ( (strlen(year_s) == 4) && (strlen(month_s) == 2) && (strlen(day_s) == 2) ) {
            sscanf(year_s, "%d", &year_i);
            sscanf(month_s, "%d", &month_i);
            sscanf(day_s, "%d", &day_i);
            if (is_date_exist(year_i, month_i, day_i)) {
                *year = year_i;
                *month = month_i;
                *day = day_i;
                return 1;
            } else {
                printf("Invalid date.\n");
            }
        } else {
            printf("Invalid date format.\n");
        }
    } else {
        while(getchar() != '\n');
        printf("Invalid date format.\n");
    }

    return 0;
}

// name below
int get_day_of_week_from_date(int year, const int month, const int day) {
    if (! is_date_exist(year, month, day)) {
        return 0;
    }

    int day_of_week;

    // https://en.wikipedia.org/wiki/Zeller%27s_congruence
    int q, k, j, m;
    q = day;
    if (month == 1 || month == 2) {
        m = month + 12;
        --year;
    } else {
        m = month;
    }
    k = year % 100;
    j = year / 100;

    day_of_week = (q + ((13 * (m + 1)) / 5 ) + k + (k / 4) + (j / 4) - 2 * j) % 7;
    day_of_week = ((day_of_week + 5) % 7) + 1; 

    return day_of_week;
}

int is_email_part_valid(char part[]) {
    for (int i = 0; part[i] != '\0'; ++i) {
        if ((part[i] != '.') && (part[i] != ' ') && (part[i] != '\t')) {
            return 1;
        }
    }
    return 0;
}

// Is valid email
int is_valid_email(const char email[]) {
    char before[MAIL_PART_SIZE], between[MAIL_PART_SIZE], after[MAIL_PART_SIZE];
    if ( (sscanf(email, "%100[^@]@%100[^@.].%100[^@]", before, between, after) == 3) ) {
        if (is_email_part_valid(before) && is_email_part_valid(between) && is_email_part_valid(after)) {
            return 1;
        } else {
            printf("Invalid email, there must be at least one symbol before, after and between @ and . symbols.\n");
        }
    } else {
        printf("Invalid format.\n");
    }
    return 0;
}

// Get domain
void get_email_domain(const char email[], char domain[]) {
    sscanf(email, "%*[^@]@%200s", domain);
}

