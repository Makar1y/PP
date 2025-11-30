#include <stdlib.h>
#include <stdio.h>

void burble(int *array, size_t arr_size) {
   if (array) {
      int swapped, tmp;

      do {
         swapped = 0;
         for (int i = 0; i < arr_size - 1; ++i) {
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


// TODO add to snippets
void swap(int *a, int *b) {
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

int partition(int *array, int low, int high) {
   // int mid = low + (high - low) / 2; TODO median of three
   // swap(&array[mid], &array[high]);
   int pivot = array[high];
   int i = low - 1;
   
   for (int j = low; j < high; ++j) {
      if (array[j] < pivot) {
         ++i;
         swap(array + i, array + j);
      }
   }
   ++i;
   swap(array + i, array + high);
   return i;
}

void quicksort(int *array, int low, int high) {
   if (low < high) {
      int pivot = partition(array, low, high);
      
      quicksort(array, pivot + 1, high);
      quicksort(array, low, pivot - 1);
   }
}