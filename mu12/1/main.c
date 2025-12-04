#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "algorithms.h"

#define ARRAY_SIZE 1000
#define LOW_BOUND 0
#define HIGH_BOUND 100

#define TABLE_ELEMENT_WIDTH 10


void print_res(char *name, int result) {
   printf("| %*s | %*d |\n", TABLE_ELEMENT_WIDTH, name, TABLE_ELEMENT_WIDTH, result);
}

void fill_array(int *array, const size_t size, const int low, const int high) {
   if (array)
      for (size_t i = 0; i < size; ++i)
         *(array + i) = (rand() % (high - low + 1) ) + low;
}

/// @return 1 if sorted, 0 if not, -1 if incorrect parameters
int is_sorted(int *array, const size_t size) {
   if (array && size > 1)
      for (size_t i = 0; i < size; ++i) {
         // printf("%d ", array[i]);
         for (int j = i + 1; j < size; ++j)
            if (array[i] > array[j])
               return 0;
      }
      return 1;
   return -1;
}

void copy_array(int const *source_arr, size_t arr_size, int *destination_arr) {
   if (source_arr && destination_arr)
      for (int i = 0; i < arr_size; ++i)
         destination_arr[i] = source_arr[i];
}



int main() {
   srand(time(NULL));
   int test_array[ARRAY_SIZE];
   int result_array[ARRAY_SIZE];
   fill_array(test_array, ARRAY_SIZE, LOW_BOUND, HIGH_BOUND);
   is_sorted(test_array, ARRAY_SIZE);

   printf("| %*s | %*s |\n",
                           TABLE_ELEMENT_WIDTH, "Algorithm", 
                           TABLE_ELEMENT_WIDTH, "Is sorted");

   for (int i = 0; i < TABLE_ELEMENT_WIDTH * 2; ++i) {
      printf("-");
   } printf("\n");

   // Bubble  sort
   copy_array(test_array, ARRAY_SIZE, result_array);
   bubble_sort(result_array, ARRAY_SIZE);
   print_res("Burble", is_sorted(result_array, ARRAY_SIZE));

   // Quicksort
   copy_array(test_array, ARRAY_SIZE, result_array);
   quicksort(result_array, 0, ARRAY_SIZE - 1);
   print_res("Quicksort", is_sorted(result_array, ARRAY_SIZE));

   // Insertion sort
   copy_array(test_array, ARRAY_SIZE, result_array);
   insertion_sort(result_array, ARRAY_SIZE);
   print_res("Insertion", is_sorted(result_array, ARRAY_SIZE));

   // Selection sort
   copy_array(test_array, ARRAY_SIZE, result_array);
   selection_sort(result_array, ARRAY_SIZE);
   print_res("Selection", is_sorted(result_array, ARRAY_SIZE));

   // Merge sort
   copy_array(test_array, ARRAY_SIZE, result_array);
   selection_sort(result_array, ARRAY_SIZE);
   print_res("Selection", is_sorted(result_array, ARRAY_SIZE));

   return 0;
}