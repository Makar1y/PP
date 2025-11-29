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