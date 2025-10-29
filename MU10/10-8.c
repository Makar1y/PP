#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

char *LAST_PTR = NULL;

char* my_strtok(char *str, const char *separators) {
   if (str == NULL) {
      char *ret = LAST_PTR;
      LAST_PTR = strpbrk(LAST_PTR, separators) + 1;
      if (LAST_PTR != NULL)
         LAST_PTR[-1] = '\0';
      else {
         LAST_PTR = NULL;
      }
      return ret;
   }
   LAST_PTR = strpbrk(str, separators) + 1;
   LAST_PTR[-1] = '\0';
   return str;
}


int main() {
   printf(" -------------------- PROGRAM ----------------------\n\n");
   char my_test_str_1[] = "Super puper test string to test strtok.";
   char test_str_1[] = "Super puper test string to test strtok.";
   char test_str_2[] = "Super puper-test: string to test strtok 2-nd variant.";


   char *my_res = my_strtok(my_test_str_1, " ");
   char *res = strtok(test_str_1, " ");
   assert(strcmp(res, my_res) == 0);

   my_res = my_strtok(NULL, " ");
   res = strtok(NULL, " ");
   assert(strcmp(res, my_res) == 0);

   my_res = my_strtok(NULL, " ");
   res = strtok(NULL, " ");
   assert(strcmp(res, my_res) == 0);

   my_res = my_strtok(NULL, " ");
   res = strtok(NULL, " ");
   assert(strcmp(res, my_res) == 0);

   my_res = my_strtok(NULL, " ");
   res = strtok(NULL, " ");
   assert(strcmp(res, my_res) == 0);

   my_res = my_strtok(NULL, " ");
   res = strtok(NULL, " ");
   assert(strcmp(res, my_res) == 0);

   my_res = my_strtok(NULL, " ");
   res = strtok(NULL, " ");
   assert(strcmp(res, my_res) == 0);

   printf("All tests passed!\n");
   return 0;
}