extern long long g_comparisons, g_swaps;

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