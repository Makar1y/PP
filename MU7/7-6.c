#include <stdio.h>

void clear_screen() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg) {
    int input;
    
    clear_screen(); // Clear screen

    while (1) {
        printf("\n\n\n");

        // Title
        printf("\t%s\n\n", menuTitle);

        // Options
        for (int i = 0; i < menuSize; ++i) {
            printf(" %d. - %s\n", i + 1, menuOptions[i]);
        }

        // Input msg
        printf("\n%s", inputMsg);

        // input handling
        if ( (scanf("%d", &input) == 1) && (getchar() == '\n') ) {
            if ((input > 0) && (input <= menuSize) ) {
                return input; // <--------------------------- Return
            } else {
                clear_screen();
                printf("!!! Error, enter menu option.");   
            }
        } else {
            while (getchar() != '\n')
                ;
            clear_screen();
            printf("!!! Error, try again.");
        }
    }
}

int main() {
    char title[] = "Super puper title.";
    char *options[] = {"First option.", "Seond option.", "Third option."};
    char input_msg[] = "Please input super puper option: ";
    
    printf("\n\nOption %d selected.", showMenu(title, options, 3, input_msg));
    return 0;
}