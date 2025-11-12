#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct saveCount{
   FILE *file;
   int count;
   struct saveCount *next;
} saveCount;

typedef struct loadCount{
   FILE *file;
   int count;
   struct loadCount *next;
} loadCount;

typedef struct {
   saveCount *saveCounters;
   int saveCounterTotal;
   loadCount *loadCounters;
   long loadCounterTotal;
} countManager;

countManager countersManager = {0};


int getSaveCount(FILE *file) {
   if (file){
      saveCount *current = countersManager.saveCounters;
      while (current) {
         if (file == current->file)
            return current->count;
         current = current->next;
      }
      return 0; // File not found in tracked file list
   }
   return countersManager.saveCounterTotal;
}

int getLoadCount(FILE *file) {
   if (file){
      loadCount *current = countersManager.loadCounters;
      while (current) {
         if (file == current->file)
            return current->count;
         current = current->next;
      }
      return 0; // File not found in tracked file list
   }
   return countersManager.loadCounterTotal;
}

void addSaveCount(FILE *file) {
   assert(file);
   
   saveCount *current = countersManager.saveCounters;
   while (current) {
      if (file == current->file) {
         ++current->count;
         ++countersManager.saveCounterTotal;
         return;
      }
      current = current->next;
   }
   
   saveCount *new = malloc(sizeof(saveCount));
   if (new){
      new->count = 1;
      new->file = file;
      new->next = countersManager.saveCounters;
      countersManager.saveCounters = new;
      ++countersManager.saveCounterTotal;
      return;
   }
   fprintf(stderr, "Error! Cant locate memory for save file counter.\n");
}

void addLoadCount(FILE *file) {
   assert(file);
   
   loadCount *current = countersManager.loadCounters;
   while (current) {
      if (file == current->file) {
         ++current->count;
         ++countersManager.loadCounterTotal;
         return;
      }
      current = current->next;
   }

   loadCount *new = malloc(sizeof(loadCount));
   if (new){
      new->count = 1;
      new->file = file;
      new->next = countersManager.loadCounters;
      countersManager.loadCounters = new;
      ++countersManager.loadCounterTotal;
      return;
   }
   fprintf(stderr, "Error! Cant locate memory for save file counter.");
}



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