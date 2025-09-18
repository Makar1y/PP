#include <stdio.h>

void error() {
    printf("    Invalid input, try again...\n");
    while(getchar() != '\n');
}


int main() {
    int input = 1;

    while (input) {
        printf("Please enter whole number(0 to exit): ");
        (  (scanf("%d", &input) == 1) && (getchar() == '\n')  ) ? 
            printf("Number %d are %s.\n\n", input, (input < 0) ? ((input % 2 == -1) ? "odd" : "even") : ((input % 2 == 1) ? "odd" : "even"))
        : 
            error();
    }
    
    return 0;
}