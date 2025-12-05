extern long long g_comparisons, g_swaps;

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