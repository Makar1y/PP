#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 20

void generateArray(int data[], int size, int low, int high) {
    srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        data[i] = (rand() % (high - low + 1) ) + low;
    }
}


int main() {
    int data[ARRAY_SIZE];
    
    generateArray(data, ARRAY_SIZE, 5, 10);
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d\n", data[i]);
    }
    return 0;
}