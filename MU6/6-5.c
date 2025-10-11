#include <stdio.h>
#include <string.h>

#define EMAIL_PART_SIZE 100
#define OUTPUT_FILE "emails.txt"

int valid(char *array) {

    for (int i = 0; i < sizeof array && array[i] != '\0'; ++i) {
        if ((array[i] != '.') && (array[i] != ' ') && (array[i] != '\t')) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // before @, between @ and first .(dot), after first .(dot)
    char before[EMAIL_PART_SIZE], between[EMAIL_PART_SIZE], after[EMAIL_PART_SIZE];

    printf("Enter email addres to check if it valid.\n");
    printf("All correct email addressed wil be saved to \"%s\".\n\n", OUTPUT_FILE);
    printf(": ");

    while (1) {
        if ( (scanf("%100[^@\n]@%100[^@.\n].%100[^@\n]", before, between, after) == 3) && (getchar() == '\n') ) {
            if (valid(before) && valid(between) && valid(after)) {
                printf("Email entered successfully.\n");
                printf("Email domain: %s.%s\n", between, after);

                FILE *emails = fopen(OUTPUT_FILE, "a");

                if (emails != NULL) {

                    fprintf(emails, "\n%s@%s.%s", before, between, after);

                    fclose(emails);
                    printf("Email saved to %s\n", OUTPUT_FILE);
                    printf("\nEnter next email(press ctrl+c to exit): ");
                } else {
                    printf("!!! Error, %s", OUTPUT_FILE);
                    perror(" |");
                }
            } else {
                printf("Invalid email, there must be at least one symbol before, after and between @ and . symbols.\n");
                printf("Enter correct email: ");
            }
        } else {
            while (getchar() != '\n');
            printf("!!! Error, enter valid email: ");
        }
    }

    return 0;
}