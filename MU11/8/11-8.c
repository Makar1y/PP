#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "file.h"
#include "counters.h"

#define SIZE 10
#define FILENAME1 "test1.bin"
#define FILENAME2 "test2.bin"


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
   int m3[SIZE];
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

   
   saveToFile(file1, m1, SIZE);
   saveToFile(file1, m3, SIZE);

   file1 = freopen(FILENAME1, "rb", file1);

   loadFromFile(file1, m1);
   saveToFile(file2, m2, SIZE);

   file2 = freopen(FILENAME2, "rb", file2);

   loadFromFile(file2, m3);
   loadFromFile(file1, m2);


   // printArray(m1, SIZE);
   // printArray(m2, SIZE);
   // printArray(m3, SIZE);

   int f1 = getSaveCount(file1) == 2 && getLoadCount(file1) == 2;
   int f2 = getSaveCount(file2) == 1 && getLoadCount(file2) == 1;
   if (getLoadCount(NULL) == 3 && getSaveCount(NULL) == 3 && f1 && f2) {
      printf("All good.");
   } else {
      printf("Something's wrong.");
      // printf("%d %d %d %d %d %d ", getLoadCount(NULL), getLoadCount(file1), getLoadCount(file2), getSaveCount(NULL), getSaveCount(file1), getSaveCount(file2));
   }
   return 0;
}