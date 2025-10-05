#include <stdio.h>
#include <string.h>

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
                } else {
                    perror("!!! Error, emails.txt");
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