#include <stdio.h>
#include <stdlib.h>

char* create_array(const int n, const int m){
    char *array = calloc(n * m, sizeof(char*));
    if (array != NULL)
        return array;
    return 0;
}

int insert_to_array(char *array[], const int i_row, const int j_column){
    if (array != NULL) {
    }
}

int get_from_array() {

}

int free_array() {

}

int main() {
    char **arr = create_array(10, 10);
    printf("%p", arr[0][1]);
    free(arr);
    return 0;
}