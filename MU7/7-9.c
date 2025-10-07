#include <stdio.h>

void print_first() {
    printf("\n\nPrinting First!");
}

void print_second() {
    printf("\n\nPrinting Second!");
}

void print_third() {
    printf("\n\nPrinting Third!");
}

void clear_screen() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg, void (*functions[])()) {
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
                functions[input - 1]();
                return input; // <--------------------------------- Return
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
    char *options[] = {"First option.", "Seond option.", "Third option.", "Clear screen."};
    char input_msg[] = "Please input super puper option: ";
    void (*func_aar[])() = {print_first, print_second, print_third, clear_screen};
    
    showMenu(title, options, 4, input_msg, func_aar);
    return 0;
}