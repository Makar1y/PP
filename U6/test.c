#include <stdio.h>

int main() {
    FILE *test;

    test = fopen("test.txt", "w+");
    if (test != NULL) {
        fputs("Ty lox", test);

        char getstr[20] = {0};
        fgets(getstr , 10, test);

        printf("%s", getstr);
    } else {
        printf("Bad!\n");
    }
    return 0;
}