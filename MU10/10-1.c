#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>


size_t my_strlen(char * str, size_t max_len) {
   size_t counter = 0;
   if (str != NULL)
      while (*(str + counter) != '\0' && counter < max_len) {
         counter++;
      }
   return counter;
}

int main() {
   
   // Happy cases
   assert(my_strlen("Teast", 100) == 5);
   assert(my_strlen("25", 100) == 2);
   assert(my_strlen("f4ds4dsf489f4s94ds4gdg4", 100) == 23);

   // Bounds cases
   assert(my_strlen("", 100) == 0);

   // Errors
   printf("Check ");
   assert(my_strlen(NULL, 100) == 0);
   printf("ok\n");

   printf("Check ");
   void *ptr = malloc(32);
   assert(my_strlen(ptr, 100) == 0);
   free(ptr);
   printf("ok\n");


   printf("Check ");
   char *test_0 = malloc(10);
   for (int i = 0; i < 10; i++) {
      test_0[i] = 't';
   }
   assert(my_strlen(test_0, 10) == 10);
   free(test_0);
   printf("ok\n");

   assert(my_strlen("Test length", 10) == 10);


   return 0;
}