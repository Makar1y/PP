#include <stdlib.h>
#include <stdio.h>

void burble_sort(int *array, size_t arr_size) {
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


void swap(int *a, int *b) {
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

int partition(int *array, int low, int high) {
   int mid = low + (high - low) / 2;
   swap(&array[mid], &array[high]);
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


insertion_sort(int *array, int size) {
   int i = 1;
   while (i < size) {
      int tmp = array[i];
      int j = i;
      while (j > 0 && array[j-1] > tmp) {
         array[j] = array[j - 1];
         --j;
      }
      array[j] = tmp;
      ++i;
   }
}