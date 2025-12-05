#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "algorithms.h"

#define ARRAY_SIZE 1000
#define LOW_BOUND 0
#define HIGH_BOUND 1000
#define TABLE_ELEMENT_WIDTH 20
#define REPETITIONS 1000
#define ALGORITHMS_NUM 5

typedef union {
   void (*quicksort)(int*, int, int);
   void (*not_quicksort)(int*, int);
} alg;

typedef struct {
   char name[TABLE_ELEMENT_WIDTH];
   alg function;
   int sorted;
   double time_total;
   long long comparisons_total;
   long long swaps_total;
} algorithm_results;


void print_res(algorithm_results * results_normal, algorithm_results *results_revers, algorithm_results *results_random, char* Title) {
   int table_width = TABLE_ELEMENT_WIDTH * 6 + 19;

   for (int i = 0; i < table_width; ++i) { printf("-"); } printf("\n");

   printf("| %-*s |\n", table_width - 4, Title, REPETITIONS);

   for (int i = 0; i < table_width; ++i) { printf("-"); } printf("\n");

   printf("| %-*s | %-*s | %-*s | %-*s | %-*s | %-*s |\n",
      TABLE_ELEMENT_WIDTH, "Algorithm",
      TABLE_ELEMENT_WIDTH, "Array type",
      TABLE_ELEMENT_WIDTH, "Is sorted",
      TABLE_ELEMENT_WIDTH, "Average time",
      TABLE_ELEMENT_WIDTH, "Average comparisons",
      TABLE_ELEMENT_WIDTH, "Average swaps"
   );
   for (int i = 0; i < table_width; ++i) { printf("-"); } printf("\n");

   for (int i = 0; i < ALGORITHMS_NUM; ++i) {
      printf("| %-*s | %-*s | %-*d | %-*lf | %-*lld | %-*lld |\n", 
         TABLE_ELEMENT_WIDTH, results_normal[i].name, 
         TABLE_ELEMENT_WIDTH, "Normal", 
         TABLE_ELEMENT_WIDTH, results_normal[i].sorted,
         TABLE_ELEMENT_WIDTH, results_normal[i].time_total,
         TABLE_ELEMENT_WIDTH, results_normal[i].comparisons_total,
         TABLE_ELEMENT_WIDTH, results_normal[i].swaps_total
      );

      printf("| %-*s | %-*s | %-*d | %-*lf | %-*lld | %-*lld |\n", 
         TABLE_ELEMENT_WIDTH, "", 
         TABLE_ELEMENT_WIDTH, "Reverse", 
         TABLE_ELEMENT_WIDTH, results_revers[i].sorted,
         TABLE_ELEMENT_WIDTH, results_revers[i].time_total,
         TABLE_ELEMENT_WIDTH, results_revers[i].comparisons_total,
         TABLE_ELEMENT_WIDTH, results_revers[i].swaps_total
      );

      printf("| %-*s | %-*s | %-*d | %-*lf | %-*lld | %-*lld |\n", 
         TABLE_ELEMENT_WIDTH, "", 
         TABLE_ELEMENT_WIDTH, "Random", 
         TABLE_ELEMENT_WIDTH, results_random[i].sorted,
         TABLE_ELEMENT_WIDTH, results_random[i].time_total / REPETITIONS,
         TABLE_ELEMENT_WIDTH, results_random[i].comparisons_total / REPETITIONS,
         TABLE_ELEMENT_WIDTH, results_random[i].swaps_total / REPETITIONS
      );

      for (int i = 0; i < table_width; ++i) { printf("-"); } printf("\n");
   }
}

void fill_array(int *array, const size_t size, const int low, const int high) {
   if (array)
      for (size_t i = 0; i < size; ++i)
         *(array + i) = (rand() % (high - low + 1) ) + low;
}

/// @return 1 if sorted, 0 if not, -1 if incorrect parameters
int is_sorted(int *array, const size_t size) {
   if (array && size > 1)
      for (size_t i = 0; i < size; ++i) {
         // printf("%d ", array[i]);
         for (int j = i + 1; j < size; ++j)
            if (array[i] > array[j])
               return 0;
      }
      return 1;
   return -1;
}

void copy_array(int const *source_arr, size_t arr_size, int *destination_arr) {
   if (source_arr && destination_arr)
      for (int i = 0; i < arr_size; ++i)
         destination_arr[i] = source_arr[i];
}

void test_sort_algorithm(algorithm_results *results, int *array, int size) {
   clock_t start_time, end_time;
   g_comparisons = 0;
   g_swaps = 0;

   if ( strcmp(results->name, "Quicksort") == 0 ) {
      start_time = clock();
         results->function.quicksort(array, 0, size);
      end_time = clock();
   } else {
      start_time = clock();
         results->function.not_quicksort(array, size);
      end_time = clock();
   }
   

   results->time_total += (double)(end_time- start_time) / CLOCKS_PER_SEC;
   results->comparisons_total += g_comparisons;
   results->swaps_total += g_swaps;
   int sorted = is_sorted(array, ARRAY_SIZE);
   if ( sorted < results->sorted ) {
      results->sorted = sorted;
   }
}



int main() {
   srand(time(NULL));
   int test_array[ARRAY_SIZE], result_array[ARRAY_SIZE];
   algorithm_results results_normal[ALGORITHMS_NUM], 
                     results_reverse[ALGORITHMS_NUM], 
                     results_random[ALGORITHMS_NUM] = {
                        {"Bubble",     .function.not_quicksort=bubble_sort,      1},
                        {"Quicksort",  .function.quicksort=quicksort,            1},
                        {"Insertion",  .function.not_quicksort=insertion_sort,   1},
                        {"Selection",  .function.not_quicksort=selection_sort,   1},
                        {"Merge",      .function.not_quicksort=merge_sort,       1}
                     };
   memcpy(results_normal, results_random, sizeof(results_random));
   memcpy(results_reverse, results_random, sizeof(results_random));

   // Randomized arrays
   for (int i = 0; i < REPETITIONS; ++i) {
      fill_array(test_array, ARRAY_SIZE, LOW_BOUND, HIGH_BOUND);
      is_sorted(test_array, ARRAY_SIZE);

      for (int j = 0; j < ALGORITHMS_NUM; ++j) {
         copy_array(test_array, ARRAY_SIZE, result_array);

         test_sort_algorithm(results_random + j, result_array, ARRAY_SIZE);
      }
   }


   // Normal and reverse arrays
   for (int i = 0; i < ARRAY_SIZE; ++i) {
      test_array[i] = i;
      result_array[i] = ARRAY_SIZE - i;
   }

   // Normal test
   for (int i = 0; i < ALGORITHMS_NUM; ++i) {
      test_sort_algorithm(results_normal + i, test_array, ARRAY_SIZE);
   }

   copy_array(result_array, ARRAY_SIZE, test_array);

   // Reverse test
   for (int i = 0; i < ALGORITHMS_NUM; ++i) {
      copy_array(test_array, ARRAY_SIZE, result_array);
      test_sort_algorithm(results_reverse + i, result_array, ARRAY_SIZE);
   }

   char Title[ALGORITHMS_NUM * TABLE_ELEMENT_WIDTH];
   sprintf(Title, "Results (num of randomized arrays = %d)", REPETITIONS);
   print_res(results_normal, results_reverse, results_random, Title);

   return 0;
}