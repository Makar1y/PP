extern long long g_comparisons, g_swaps;

void merge(int *array, int begin, int middle, int end, int *tmp_arr) {
   for (int i = begin; i < end; ++i)
      tmp_arr[i] = array[i]; // copy array

   int i = begin;
   int j = middle;

   for (int k = begin; k < end; ++k) {
      if (i < middle && (j >= end || tmp_arr[i] <= tmp_arr[j]) ) {
         // if ( !(j >= end) ) ++g_comparisons;

         array[k] = tmp_arr[i];
         ++i;
         ++g_swaps;
      } else {
         // if ( !(j >= end) ) ++g_comparisons;

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