#include <stdio.h>
#include <string.h>

#define TRIES 5

int tries = TRIES;


int valid(char *array) {

    for (int i = 0; i < sizeof array && array[i] != '\0'; ++i) {
        if ((array[i] != '.') && (array[i] != ' ') && (array[i] != '\t')) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char before[100], between[100], after[100];

    printf("Enter email addres to check if it valid.\n");
    printf("All correct email addressed wil be saved to \"emails.txt\".\n\n");
    printf(": ");

    while (1) {
        if ( tries <= 0) {
            printf("Program exit(0 tries left).");
            return 1;
        }

        if ( (scanf("%100[^@\n]@%100[^@.\n].%100[^@\n]", before, between, after) == 3) && (getchar() == '\n') ) {
            if (valid(before) && valid(between) && valid(after)) {
                printf("Email entered successfully.\n");
                printf("Email domain: %s.%s\n", between, after);

                FILE *emails = fopen("emails.txt", "a");

                if (emails != NULL) {

                    fprintf(emails, "%s@%s.%s\n", before, between, after);

                    fclose(emails);
                    printf("Email saved to emails.txt\n");
                    printf("\nEnter next email(press ctrl+c to exit): ");
                    tries = TRIES;
                } else {
                    --tries;
                    printf("!!! Error(%d tries left), ", tries);
                    perror("emails.txt");
                }
            } else {
                --tries;
                printf("Invalid email(%d tries left), there must be at least one symbol before, after and between @ and . symbols.\n", tries);
                if (tries) {
                    printf("Enter correct email: ");
                }
            }
        } else {
            while (getchar() != '\n');
            --tries;
            printf("!!! Error(%d tries left), enter valid email: ", tries);
        }
    }

    return 0;
}