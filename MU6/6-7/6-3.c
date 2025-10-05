#include <stdio.h>
#include <string.h>

#define NUM_SIZE 100
#define TRIES 5

int tries = TRIES;

int main() {
    long a, b, c;
    int middle;
    char filename[100];

    printf("Program to find middle number\n");
    printf("Please enter three whole numbers in this format(without spaces):\n");
    printf("Example: 12;-5;6\n");
    printf("Enter yours\n");


    while (1) {
        printf(": ");
        if ((scanf("%ld;%ld;%ld", &a, &b, &c) == 3) && (getchar() == '\n')) {
            printf("Numbers a=%ld, b=%ld, c=%ld entered successfully\n", a, b, c);
            break;
        } else {
            while(getchar() != '\n');
            --tries;
            printf("!!! Error, please enter numbers in specified format(%d tries left).\n", tries);
        }

        if (tries <= 0) {
            printf("Program exit(0 tries left).\n");
            return 1;
        }
    } tries = TRIES;


    if ((a >= b && a <= c) || (a <= b && a >= c)) {
        middle = a;
    } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
        middle = b;
    } else {
        middle = c;
    }


    while (1) {        
        while (1) {
            printf("Enter file name for saving result (must end .txt): ");
            scanf("%s", filename);

            if (strcmp(filename, "exit") == 0) {
                printf("Program exit(user exit).");
                return 0;
            }

            int len = strlen(filename);
            if (len > 4 && strcmp(filename + len - 4, ".txt") == 0) {
                break;
            } else {
                --tries;
                printf("!!! Error(%d tries left), file extension should be .txt\n", tries);
            }

            if (tries <= 0) {
                printf("Program exit(0 tries left).\n");
                return 1;
            }
        }



        FILE *f = fopen(filename, "a");
        if (f != NULL) {
            fprintf(f, "%d\n", middle);
            printf("Result saved to \"%s\".\n", filename);

            fclose(f);
            break;
        } else {
            --tries;
            printf("!!! Error(%d tries left), could not open file.\n", tries);
            if (tries > 0) {
                printf("Try enter new file name, or type exit to terminate program.");
            }
        }

        if (tries <= 0) {
            printf("Program exit(0 tries left).\n");
            return 1;
        }
    }

    return 0;
}