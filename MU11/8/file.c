#include <stdio.h>
#include <assert.h>


int saveToFile(FILE *file, const void *array, const size_t size, const size_t element_size) {
   if (file && array)
      if (size > 0 && fwrite(&size, sizeof(size_t), 1, file) && fwrite(&element_size, sizeof(size_t), 1, file))
         if (fwrite(array, element_size, size, file)){
            return 1;
         }
   return 0;
}

int loadFromFile(FILE *file, void *array, const size_t element_size) {
   if (file && array) {
      size_t size;
      size_t local_el_size;

      if (fread(&size, sizeof(size_t), 1, file) && fread(&local_el_size, sizeof(size_t), 1, file))
         if((local_el_size == element_size) && fread(array, element_size, size, file)) {
            return 1;
         }
   }
   return 0;
}