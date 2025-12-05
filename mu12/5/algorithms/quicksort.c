extern long long g_comparisons, g_swaps;

void swap(int* a, int* b) {
   int tmp = *a;
   *a = *b;
   *b = tmp;
   ++g_swaps;
}

int partition(int* array, int begin, int end) {
   int mid = (end + begin) / 2;
   if (mid != end) {
      swap(&array[mid], &array[end]);
   }
   int pivot = array[end];
   int i = begin - 1;

   for (int j = begin; j < end; ++j) {
      if (array[j] < pivot) {
         
         ++i;
         if ( i != j) {
            swap(array + i, array + j);
         }
      }
      ++g_comparisons;
   }

   ++i;
   if (i != end) {
      swap(array + i, array + end);
   }
   return i;
}

void quicksort(int* array, int begin, int end) {
   if (begin < end) {
      int pivot = partition(array, begin, end);

      quicksort(array, begin, pivot - 1);
      quicksort(array, pivot + 1, end);
   }
}