#include <stdio.h>

int getPositiveNumber(char *msg) {
    int input_num;

    while (1) {
        printf("%s", msg);

        if ((fscanf(stdin, "%d", &input_num) == 1) && (getchar() == '\n')) {
            if (input_num > 0)
                break;
        } else {
            while (getchar() != '\n')
                ;
            // printf("Incorrect input, try again!\n");
        }
        
    }

    return input_num;
}

int main() {

    printf("Res: %d", getPositiveNumber("Just enter positive number: "));
    return 0;
}