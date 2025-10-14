#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_ARRAY_SIZE 10
#define TEST_SPLIT 6


void fillArray(int *array, const int size, const int low, const int high) {
    srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        *(array + i) = (rand() % (high - low + 1) ) + low;
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


int splitData(int *array, const int size, const int split, int **part1, int **part2) {
    if ( (size > 1) && (array != NULL) && ((split > 0) && (split < size)) && ((*part1 == NULL) && (*part2 == NULL))) {
        *part1 = calloc(split, sizeof(int));
        *part2 = calloc(size - split, sizeof(int));

        if ((*part1 != NULL) && (*part2 != NULL)) {
            for (int i = 0; i < split; ++i) {
                (*part1)[i] = array[i];
            }

            for (int i = 0; i < size - split; ++i) {
                (*part2)[i] = array[split + i];
            }
            return 0;
        }
    }
    return -1;
}


int main() {
    int *first_array = NULL, *second_array = NULL;    
    int main_array[TEST_ARRAY_SIZE];

    fillArray(main_array, TEST_ARRAY_SIZE, 0, 100);

    if (splitData(main_array, TEST_ARRAY_SIZE, TEST_SPLIT, &first_array, &second_array) == 0) {
        printf("Main array:\n");
        for (int i = 0; i < TEST_ARRAY_SIZE; ++i) {
            printf("%d ", main_array[i]);
        }
        printf("\n");

        printf("First part:\n");
        for (int i = 0; i < TEST_SPLIT; ++i) {
            printf("%d ", first_array[i]);
        }
        printf("\n");
        
        printf("Second part:\n");
        for (int i = 0; i < TEST_ARRAY_SIZE - TEST_SPLIT; ++i) {
            printf("%d ", second_array[i]);
        }
    } else {
        printf("Error...\n");
    }

    free(first_array);
    free(second_array);
    
    return 0;
}