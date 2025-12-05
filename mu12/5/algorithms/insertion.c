extern long long g_comparisons, g_swaps;

void insertion_sort(int* array, int size) {
   int i = 1;

   while (i < size) {
      int tmp = array[i];
      int j = i;

      ++g_comparisons;
      while (j > 0 && array[j - 1] > tmp) {
         ++g_swaps;
         array[j] = array[j - 1];
         --j;
         ++g_comparisons;
      }
      

      if (j != i) {
         array[j] = tmp;
         ++g_swaps;
      }
      ++i;
   }
}