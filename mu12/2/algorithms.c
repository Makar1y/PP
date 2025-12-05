#include <stdio.h>
#include <stdlib.h>

long long g_comparisons, g_swaps;

void bubble_sort(int* array, int size) {
   int swapped, tmp;

   do {
      swapped = 0;

      for (int i = 0; i < size - 1; ++i) {
         if (array[i] > array[i + 1]) {
            tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
            swapped = 1;
            ++g_swaps;
         }
         ++g_comparisons;
      }
   } while (swapped);
}


void swap(int* a, int* b) {
   int tmp = *a;
   *a = *b;
   *b = tmp;
   ++g_swaps;
}

int partition(int* array, int begin, int end) {
   int mid = (end + begin) / 2;
   swap(&array[mid], &array[end]);
   int pivot = array[end];
   int i = begin - 1;

   for (int j = begin; j < end; ++j) {
      if (array[j] < pivot) {
         
         ++i;
         swap(array + i, array + j);
      }
      ++g_comparisons;
   }

   ++i;
   swap(array + i, array + end);
   return i;
}

void quicksort(int* array, int begin, int end) {
   if (begin < end) {
      int pivot = partition(array, begin, end);

      quicksort(array, begin, pivot - 1);
      quicksort(array, pivot + 1, end);
   }
}


void insertion_sort(int* array, int size) {
   int i = 1;

   while (i < size) {
      int tmp = array[i];
      int j = i;

      while (j > 0 && array[j - 1] > tmp) {
         ++g_swaps;
         array[j] = array[j - 1];
         --j;
      }
      ++g_comparisons;

      if (j != i) {
         array[j] = tmp;
         ++g_swaps;
      }
      ++i;
   }
}


void selection_sort(int* array, int size) {
   for (int i = 0; i < size; ++i) {
      int min = i;
      int min_value = array[i];

      for (int j = i + 1; j < size; ++j) {
         if (array[j] < min_value) {
            min = j;
            min_value = array[j];
         }
         ++g_comparisons;
      }

      if (min != i) {
         array[min] = array[i];
         array[i] = min_value;
         ++g_swaps;
      }
   }
}


void merge(int *array, int begin, int middle, int end, int *tmp_arr) {
   for (int i = begin; i < end; ++i)
      tmp_arr[i] = array[i]; // copy array

   int i = begin;
   int j = middle;

   for (int k = begin; k < end; ++k) {
      if (i < middle && (j >= end || tmp_arr[i] <= tmp_arr[j]) ) {
         if ( !(j >= end) ) ++g_comparisons;
         array[k] = tmp_arr[i];
         ++i;
         ++g_swaps;
      } else {
         if ( !(j >= end) ) ++g_comparisons;
         array[k] = tmp_arr[j];
         j++;
         ++g_swaps;
      }
      ++g_comparisons;
   }
}

void split(int *array, int begin, int end, int *tmp_arr) {
   if (end - begin <= 1) {
      return;
   }

   int middle = (end + begin) / 2;
   split(array, begin, middle, tmp_arr);
   split(array, middle, end, tmp_arr);

   merge(array, begin, middle, end, tmp_arr);
}

void merge_sort(int* array, int size) {
   int tmp_arr[size];

   split(array, 0, size, tmp_arr);
}
