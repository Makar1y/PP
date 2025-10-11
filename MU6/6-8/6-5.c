#include <stdio.h>
#include <string.h>
#include "custom_module.c"

#define OUTPUT_FILE "emails.txt"

int main() {
    char input_email[MAIL_PART_SIZE * 3 + 2];
    char email_domain[MAIL_PART_SIZE];

    printf("Enter email addres to check if it valid.\n");
    printf("All correct email addressed wil be saved to \"%s\".\n\n", OUTPUT_FILE);
    printf(": ");

    while (1) {
        if (scanf("%s", input_email) && getchar() == '\n') {
            if ( is_valid_email(input_email)) {
                printf("Email entered successfully.\n");
                get_email_domain(input_email, email_domain);
                printf("Email domain: %s\n", email_domain);

                FILE *emails = fopen(OUTPUT_FILE, "a");

                if (emails != NULL) {

                    fprintf(emails, "\n%s", input_email);

                    fclose(emails);
                    printf("Email saved to %s\n", OUTPUT_FILE);
                    printf("\nEnter next email(press ctrl+c to exit): ");
                } else {
                    printf("!!! Error, %s", OUTPUT_FILE);
                    perror(" |");
                }
            } else {
                printf("!!! Error, enter valid email: ");
            }
        } else {
            while (getchar() != '\n');
            printf("!!! Error, enter valid email: ");
        }
    }

    return 0;
}