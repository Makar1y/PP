#include <stdio.h>
#include <assert.h>

#define ARRAY_SIZE 10
#define LOW_BOUND 0
#define HIGH_BOUND 100



void fill_array(int *array, const size_t size, const int low, const int high) {
   if (array)
      for (size_t i = 0; i < size; ++i)
         *(array + i) = (rand() % (high - low + 1) ) + low;
}

/// @return 1 if sorted, 0 if not, -1 if incorrect parameters
int is_sorted(int *array, const size_t size) {
   if (array && size > 1)
      for (size_t i = 0; i < size; ++i)
         for (int j = i + 1; j < size; ++j)
            if (i > j)
               return 0;
      return 1;
   return -1;
}

void copy_array(int const *source_arr, size_t arr_size, int *destination_arr) {
   if (source_arr && destination_arr)
      for (int i = 0; i < arr_size; ++i)
         destination_arr[i] = source_arr[i];
}



int main() {
   srand(time(NULL));
   int test_array[ARRAY_SIZE];
   int result_array[ARRAY_SIZE];

   fill_array(test_array, ARRAY_SIZE, LOW_BOUND, HIGH_BOUND);
   copy_array(test_array, ARRAY_SIZE, result_array);

   

   
   printf("Hello world");
   return 0;
}