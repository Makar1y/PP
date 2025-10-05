#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 200
#define DICTIONARY "dict.txt"
#define INCORRECT_WORDS_LIST "iw.txt"


void welcome_print() {
    printf("========================================================================================\n");
    printf("This program will read your file and compare words with dictionary.\n");
    printf("If word not in dictionary will be asked save it to dictionary or to incorrect word list.\n");
    printf("Dictionary stores in '%s', incorrect words list - '%s'\n", DICTIONARY, INCORRECT_WORDS_LIST);
    printf("========================================================================================\n\n");

}

int init() {
    FILE *init_dict = fopen(DICTIONARY, "a");
    if (init_dict == NULL) {
        printf("!!! Error(initialization failed), %s", DICTIONARY);
        perror("");
        return 0;
    } fclose(init_dict);

    FILE *init_incorrect_words_list = fopen(INCORRECT_WORDS_LIST, "a");
    if (init_incorrect_words_list == NULL) {
        printf("!!! Error(initialization failed), %s: ", INCORRECT_WORDS_LIST);
        perror("");
        return 0;
    }
    fclose(init_incorrect_words_list);
    return 1;
}

int add_to_incorrect(const char word[], const unsigned long line, const unsigned long line_word) {
    FILE *dict = fopen(INCORRECT_WORDS_LIST, "a");

    if (dict != NULL) {

        fprintf(dict, "%s (line %lu, word %lu)\n", word, line, line_word);
        fclose(dict);
        return 1;
    } else {
        printf("!!! Error, cant write word to incorrect words list, %s:", INCORRECT_WORDS_LIST);
        perror("");
    }
    return 0;
}

int add_to_dictionary(const char word[]) {
    FILE *dict = fopen(DICTIONARY, "a");

    if (dict != NULL) {
        fprintf(dict, "%s\n", word);
        fclose(dict);
        return 1;
    } else {
        printf("!!! Error, cant write word to dictionary, %s:", DICTIONARY);
        perror("");
    }
    return 0;
}

int in_dict(const char word[]) {
    FILE *dict = fopen(DICTIONARY, "r");
    char buffer[BUFFER_SIZE] = {0};

    if (dict != NULL) {
        while (fscanf(dict, "%s", buffer) == 1) {
            if (strcmp(buffer, word) == 0) {
                fclose(dict);
                return 1;
            }
        }
        fclose(dict);
    } else {
        printf("!!! Error, cant check word, %s:", DICTIONARY);
        perror("");
        printf("Press any key to continue...");
        getchar();
        return 1;
    }
    return 0;
}

void to_lower(char *word) {
    for (int i = 0; word[i]; i++) {
    if (word[i] >= 'A' && word[i] <= 'Z')
        word[i] += 'a' - 'A';
}
};

int main(int arg_count, char *args[]) {
    char buffer[BUFFER_SIZE] = {0};
    char filename[FILENAME_MAX];

    // Initialization
    if (!init()) {
        return 1;
    }

    welcome_print();

    // Reading filename
    if (arg_count > 1) {
        strcpy(filename, args[1]);
    } else {
        printf("Please, enter filename: ");
        scanf("%s", filename);
        getchar(); // remove \n from input stream
    }


    FILE *file_to_read = fopen(filename, "r");

    if (file_to_read != NULL) {
        unsigned long line = 1, line_word = 0;

        printf("Reading file...\n\n");
        while (fscanf(file_to_read, "%[a-zA-Z-]", buffer) == 1) {

            fscanf(file_to_read, "%*[^a-zA-Z\n]");
            ++line_word;

            to_lower(buffer);

            if (!in_dict(buffer)) {
                char option;

                printf("Word %s not in dictionary.\n", buffer);
                printf("Start enter with '1' to add to dictionary, or any other key to mark as incorrect: ");
                if (scanf(" %c", &option) == 1) {
                    if (option == '1') {
                        if (add_to_dictionary(buffer)) {
                            printf("Word %s successfully added to dictionary.\n\n", buffer);
                        }
                    } else {
                        if (add_to_incorrect(buffer, line, line_word)) {
                            printf("Word %s successfully added to incorrect words list\n\n", buffer);
                        }
                    }

                    while(getchar() != '\n'); // clear input stream
                } else {
                    while(getchar() != '\n'); // clear input stream
                }
            }  

            char check = fgetc(file_to_read);
            if ( check == '\n') {
                line_word = 0;
                ++line;

                while (check == '\n') {
                    check = fgetc(file_to_read);

                    if ( check == '\n') {
                        line_word = 0;
                        ++line;
                    }
                }
            } 
            if ( check != EOF) {
                ungetc(check, file_to_read);
            }
        }

        printf("All words checked.\n");
        fclose(file_to_read);
    } else {
        printf("!!! Error, %s: ", filename);
        perror("");
        return 1;
    }

    return 0;
}