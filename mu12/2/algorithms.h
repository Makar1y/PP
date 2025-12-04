#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

extern long g_comparisons, g_swaps;

void bubble_sort(int *array, int size);

void quicksort(int *array, int low, int high);

void insertion_sort(int *array, int size);

void selection_sort(int *array, int size);

void merge_sort(int* array, int size);

#endif