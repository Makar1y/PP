#include <stdio.h>
#include <assert.h>

#include "counters.h"


int saveToFile(FILE *file, const int *array, const size_t size) {
   if (file && array)
      if (size > 0 && fwrite(&size, sizeof(size_t), 1, file))
         if (fwrite(array, sizeof(int), size, file)){
            addSaveCount(file);
            return 1;
         }
   return 0;
}

int loadFromFile(FILE *file, int *array) {
   if (file && array) {
      size_t size;

      if (fread(&size, sizeof(size_t), 1, file))
         if(fread(array, sizeof(int), size, file)) {
            addLoadCount(file);
            return 1;
         }
   }
   return 0;
}