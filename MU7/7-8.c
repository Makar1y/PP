#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int medianThree(int *array, int a, int b, int c) {
    int a_a = array[a];
    int a_b = array[b];
    int a_c = array[c];

    // Someone clever on stackoverflow said that this xor faster than more, less operations.
    if ((a_a > a_b) ^ (a_a > a_c)) 
        return a;
    else if ((a_b < a_a) ^ (a_b < a_c)) 
        return b;
    else
        return c;
}

int sort(int array[], const int start, const int end) {
    // Base element
    int base_index = medianThree(array, start, start + (end - start) / 2, end);
    swap(&array[base_index], &array[end]);
    int base = array[end];

    // Starting point
    int i = start - 1;

    // Sorting
    for (int j = start; j < end; ++j) {
        if (array[j] < base) {
            ++i;
            if (j != i) {
                swap(&array[i], &array[j]);
            }
        }
    }

    // New base
    swap(&array[i + 1], &array[end]);
    return i + 1;

}

void rec_quicksort(int array[], const int start, const int end) {
    // If more than 1 element
    if (start < end) {

        // Sort + return new base
        int base = sort(array, start, end);

        // Recursion for left and right side of base element
        rec_quicksort(array, base + 1, end);
        rec_quicksort(array, start, base - 1);
    }
}

void nrec_quicksort(int array[], int start, int end) {
    int mem[end - start + 1];
    int current = -1;

    mem[++current] = start;
    mem[++current] = end;

    while (current >= 0) {

        end = mem[current--];
        start = mem[current--];

        // Sort + return new base
        int base = sort(array, start, end);

        if (base > start) {
            mem[++current] = start;
            mem[++current] = base - 1;
        }
        if (base < end) {
            mem[++current] = base + 1;
            mem[++current] = end; 
        }

        // Recursion for left and right side of base element
        // rec_quicksort(array, base + 1, end);
        // rec_quicksort(array, start, base - 1);
    }


}


int main() {
    int array[ARRAY_SIZE];

    srand(time(NULL));

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = rand() % 101;
    }

    rec_quicksort(array, 0, ARRAY_SIZE - 1);
    // nrec_quicksort(array, 0, ARRAY_SIZE - 1);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf(" %d ", array[i]);
    }

    return 0;
}