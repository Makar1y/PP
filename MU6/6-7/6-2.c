#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRIES 5
#define NUMBER_MAX_LENGTH 100

int invalid_inputs_left = TRIES;

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
    char file_name[64] = "in.txt";
    char number[64];
    double val;

    printf("Please enter real number in in.txt (from 10 to 1000, max 3 digits after comma).\n");
    printf("Press enter when ready...");
    getchar();
    printf("\n");

    while (1) {
        if (invalid_inputs_left <= 0) {
            printf("Program exit(0 tries left)");
            return 1;
        }
        FILE *f = fopen(file_name, "r");
        if (f == NULL) {
            --invalid_inputs_left;
            printf("!!! (Tries left: %d) Error, %s", invalid_inputs_left, file_name);
            perror("|");
            printf("Enter another file name: ");
            scanf("%63s", file_name);
            continue;
        }

        if (!fgets(number, sizeof(number), f)) {
            fclose(f);
            --invalid_inputs_left;
            printf("File is empty, (%d tries left).\n", invalid_inputs_left);
            printf("Enter another file name: ");
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
            --invalid_inputs_left;
            printf("Invalid data, (%d tries left).\n", invalid_inputs_left);
            printf("Enter another file name: ");
            scanf("%63s", file_name);
        }
    }

    return 0;
}
