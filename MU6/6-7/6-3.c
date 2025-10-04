#include <stdio.h>
#include <string.h>

#define NUM_SIZE 100

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
            printf("!!! Error, please enter numbers in specified format.\n");
        }
    }

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
                printf("Program exited.");
                return 0;
            }

            int len = strlen(filename);
            if (len > 4 && strcmp(filename + len - 4, ".txt") == 0) {
                break;
            } else {
                printf("!!! Error, file extension should be .txt\n");
            }
        }



        FILE *f = fopen(filename, "w");
        if (f != NULL) {
            fprintf(f, "%d\n", middle);
            printf("Result saved to \"%s\".\n", filename);

            fclose(f);
            break;
        } else {
            printf("!!! Error, could not open file.\n");
            printf("Try enter new file name, or type exit to terminate program.");
        }
    }

    return 0;
}