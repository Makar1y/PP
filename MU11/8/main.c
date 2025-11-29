#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "file.h"
#include "file.h"

#define SIZE 10
#define ELEMENTS_TYPE double
#define FILENAME "test.bin"

// for float numbers
void fillArray(ELEMENTS_TYPE *array, size_t size, const float low, const float high) {
   if (array) {
      for (int i = 0; i < size; ++i) {
         *(array + i) = (((float)rand() / RAND_MAX) * (high - low) + low);
         (float)rand()/(float)(RAND_MAX/high);
      }
   }
}

void printArray(ELEMENTS_TYPE *array, size_t size) {
   if(array) {
      for(size_t i = 0; i < size; ++i) {
         printf("%f ", array[i]);
      }
      printf("\n");
   }
}



int main(void) {
   ELEMENTS_TYPE m1[SIZE];
   ELEMENTS_TYPE m2[SIZE];
   FILE *file = fopen(FILENAME, "wb");

   assert(m1 && m2 && file);
   srand(time(NULL));

   fillArray(m1, SIZE, 0, 10);
   printArray(m1, SIZE);
   saveToFile(file, m1, SIZE, sizeof(ELEMENTS_TYPE));

   file = freopen(FILENAME, "rb", file);
   assert(file);

   loadFromFile(file, m2, sizeof(ELEMENTS_TYPE));
   printArray(m2, SIZE);

   for (int i = 0; i < SIZE; ++i) {
      if(m1[i] != m2[i]) {
         printf("Something's wrong.");
         return 0;
      }
   }
   printf("All good.");
   return 0;
}