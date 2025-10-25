#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLUMNS 10


char*** create_array(const int n, const int m){
    char ***array = (char***)calloc(n, sizeof(char**));

    for (int i = 0; i < n; ++i) {
        array[i] = calloc(m, sizeof(char*));
    }

    return array;
}

char* insert_to_array(char ***array, const int i_row, const int j_column, char *string){
    int string_size = 0;
    char *result = NULL;
    int real_i_row = i_row - 1, real_j_column = j_column - 1;

    if ((array != NULL) && (array[real_i_row] != NULL)) {
        char character = ' ';
        for (int i = 0; character != '\0'; ++string_size, ++i) {
            character = string[i];
        }

        array[real_i_row][real_j_column] = realloc(array[real_i_row][real_j_column], (string_size + 1) * sizeof(char));
        if (array[real_i_row][real_j_column] != NULL) {
            result = strcpy(array[real_i_row][real_j_column], string);
        }
    }
    return result;
}

char* get_from_array(char ***array, const int real_i_row, const int j_column) {
    // Here is why I used pointers to pointers to pointer
    return array[real_i_row-1][j_column-1];
}

void free_array(char ***arr, const int n, const int m) {
    if (arr != NULL) {
        for (int i = 0; i < n; ++i) {

            if (arr[i] != NULL) {
                for (int j = 0; j < m; ++j) {
                    free(arr[i][j]);
                }
                free(arr[i]);
            }

        }
        free(arr);
    }
}


int main() {
    char ***arr = create_array(ROWS, COLUMNS);
    int i, j;
    char str[250] = "";

    printf("Write: ");
    while (scanf("%d%d%s", &i, &j, str) == 3) {
        if (insert_to_array(arr, i, j, str)) {
            printf("Inserted '%s' to row: %d column %d\n", str, i, j);
        } else {
            printf("Error to insert '%s' to row: %d column %d\n", str, i, j);
        }

        printf("Read: ");
        scanf("%d%d", &i, &j);
        printf("%s \n", get_from_array(arr, i, j));

        printf("Write: ");
    }
    printf("\nExit...");

    free_array(arr, ROWS, COLUMNS);
    return 0;
}