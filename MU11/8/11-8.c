#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "file.h"
#include "counters.h"

#define SIZE 10
#define ELEMENTS_TYPE int
#define FILENAME1 "test1.bin"
#define FILENAME2 "test2.bin"


void fillArray(ELEMENTS_TYPE *array, size_t size, const int low, const int high) {
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
   ELEMENTS_TYPE m1[SIZE];
   ELEMENTS_TYPE m2[SIZE];
   ELEMENTS_TYPE m3[SIZE];
   srand(time(NULL));
   
   FILE *file1 = fopen(FILENAME1, "wb");
   FILE *file2 = fopen(FILENAME2, "wb");

   assert(file1 && file2 && m1 && m2 && m3);

   fillArray(m1, SIZE, 0, SIZE);
   fillArray(m2, SIZE, 0, SIZE);
   fillArray(m3, SIZE, 0, SIZE);

   // printArray(m1, SIZE);
   // printArray(m2, SIZE);
   // printArray(m3, SIZE);

   
   saveToFile(file1, m1, SIZE, sizeof(ELEMENTS_TYPE));
   saveToFile(file1, m3, SIZE, sizeof(ELEMENTS_TYPE));

   file1 = freopen(FILENAME1, "rb", file1);

   loadFromFile(file1, m1, sizeof(int));
   saveToFile(file2, m2, SIZE, sizeof(ELEMENTS_TYPE));

   file2 = freopen(FILENAME2, "rb", file2);

   loadFromFile(file2, m3, sizeof(ELEMENTS_TYPE));
   loadFromFile(file1, m2, sizeof(ELEMENTS_TYPE));


   // printArray(m1, SIZE);
   // printArray(m2, SIZE);
   // printArray(m3, SIZE);

   int f1 = getSaveCount(file1) == 2 && getLoadCount(file1) == 2;
   int f2 = getSaveCount(file2) == 1 && getLoadCount(file2) == 1;
   if (getLoadCount(NULL) == 3 && getSaveCount(NULL) == 3 && f1 && f2) {
      printf("All good.");
   } else {
      printf("Something's wrong.");
   }
   return 0;
}