#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMBER_MAX_LENGTH 100

int is_valid_number(char *s, double *value) {
    char *endptr;
    char buf[NUMBER_MAX_LENGTH];
    int len = strlen(s);

    // Remove \n
    if (len > 0 && s[len - 1] == '\n') {
        ((char*)s)[len - 1] = '\0';
        len--;
    }

    // , -> . 
    strcpy(buf, s);
    for (int i = 0; buf[i]; i++) {
        if (buf[i] == ',') {
            buf[i] = '.';
            break;
        }
    }

    *value = strtod(buf, &endptr);

    // error
    if (*endptr != '\0')
        return 0;

    // bounds check
    if (*value < 10.0 || *value > 1000.0)
        return 0;

    // check nums adter .
    char *comma = strchr(s, '.');
    if (comma != NULL) {
        int fractional_len = strlen(comma + 1);
        if (fractional_len > 3)
            return 0;
    }

    return 1;
}

int main() {
    char file_name[FILENAME_MAX] = "in.txt";
    char number[NUMBER_MAX_LENGTH];
    double val;

    printf("Please enter real number in in.txt (from 10 to 1000, max 3 digits after comma).\n");
    printf("Press enter when ready...");
    getchar();
    printf("\n");

    while (1) {
        FILE *f = fopen(file_name, "r");
        if (f == NULL) {
            printf("Could not open file. Enter another file name: ");
            scanf("%63s", file_name);
            continue;
        }

        if (!fgets(number, sizeof(number), f)) {
            fclose(f);
            printf("File is empty. Enter another file name: ");
            scanf("%63s", file_name);
            continue;
        }
        fclose(f);

        if (is_valid_number(number, &val)) {
            unsigned length = strlen(number);
            for (int i = 0; number[i]; ++i) {
                if (number[i] == ',' || number[i] == '.') {
                    --length;
                }
            }
            printf("Number length: %lu\n", length);
            break;
        } else {
            printf("Invalid data. Enter another file name: ");
            scanf("%63s", file_name);
        }
    }

    return 0;
}
