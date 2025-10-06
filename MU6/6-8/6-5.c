#include <stdio.h>
#include <string.h>
#include "custom_module.c"


int main() {
    char input_email[MAIL_PART_SIZE * 3 + 2];
    char email_domain[MAIL_PART_SIZE];

    printf("Enter email addres to check if it valid.\n");
    printf("All correct email addressed wil be saved to \"emails.txt\".\n\n");
    printf(": ");

    while (1) {
        if (scanf("%s", input_email) && getchar() == '\n') {
            if ( is_valid_email(input_email)) {
                printf("Email entered successfully.\n");
                get_email_domain(input_email, email_domain);
                printf("Email domain: %s\n", email_domain);

                FILE *emails = fopen("emails.txt", "a");

                if (emails != NULL) {

                    fprintf(emails, "%s\n", input_email);

                    fclose(emails);
                    printf("Email saved to emails.txt\n");
                    printf("\nEnter next email(press ctrl+c to exit): ");
                } else {
                    perror("!!! Error, emails.txt");
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