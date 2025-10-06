#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "custom_module.c"

#define NUMBER_MAX_LENGTH 100

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

        if (str_valid_number(number, 10, 1000, 3)) {
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
