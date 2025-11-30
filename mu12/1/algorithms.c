#include <stdlib.h>

void burble(int *array, size_t arr_size) {
   if (array) {
      int swapped, tmp;

      do {
         swapped = 0;
         for (int i = 0; i < arr_size-1; ++i) {
            if (array[i] > array[i + 1]) {
               int tmp = array[i];
               array[i] = array[i + 1];
               array[i + 1] = tmp;
               swapped = 1;
            }
         }
      } while (swapped);
   }
}



int partition(int *array, size_t low, size_t high) {
   int pivot = low;

   int i = low - 1;
   int j = high + 1;

   while (1) {
      do ++i; while (array[i] < array[pivot]);

      do --j; while (array[j] > array[pivot]);

      if (i >= j) return j;

      int tmp = array[i];
      array[i] = array[j];
      array[j] = tmp;
   }
}

int quicksort(int *array, size_t low, size_t high) {
   if (low >= 0 && high >= 0 && low < high) {
      int pivot = partition(array, low, high);
      quicksort(array, low, pivot);
      quicksort(array, pivot + 1, high);
   }
}