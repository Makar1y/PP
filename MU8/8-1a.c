#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_ARRAY_SIZE 10

void fillArray(int array[], const int size, const int low, const int high) {
    srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        array[i] = (rand() % (high - low + 1) ) + low;
    }
}


int * createArray(const int size, const int low, const int high) {
    int *arr = calloc(size, sizeof(int)); 

    if ((arr != NULL) && (low <= high)) {
        fillArray(arr, size, low, high);
        return arr;
    }
    return NULL;
}


int main() {
    
    int *test = createArray(TEST_ARRAY_SIZE, 0, 100);
    if (test != NULL) {
        for (int i = 0; i < TEST_ARRAY_SIZE; ++i) {
            printf("%d ", test[i]);
        }
    }
    free(test);
    return 0;
}