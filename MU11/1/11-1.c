#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "file.h"

#define SIZE 10
#define FILENAME "test.bin"


void fillArray(int *array, size_t size, const int low, const int high) {
   if (array) {
      for (int i = 0; i < size; ++i) {
         *(array + i) = (rand() % (high - low + 1) ) + low;
      }
   }
}

void printArray(int *array, size_t size) {
   if(array) {
      for(size_t i = 0; i < size; ++i) {
         printf("%d ", array[i]);
      }
      printf("\n");
   }
}

int main(void) {
   int m1[SIZE];
   int m2[SIZE];
   FILE *file = fopen(FILENAME, "wb");

   assert(m1 && m2 && file);
   srand(time(NULL));

   fillArray(m1, SIZE, 0, 10);
   printArray(m1, SIZE);
   saveToFile(file, m1, SIZE);

   file = freopen(FILENAME, "rb", file);
   assert(file);

   loadFromFile(file, m2);
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