#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

char *LAST_PTR = NULL;

char* my_strtok(char *str, const char *separators) {
   if (separators != NULL) {
      if (str != NULL && *str != '\0') {
         LAST_PTR = strpbrk(str, separators);

         if(LAST_PTR != str) {
            if (LAST_PTR) {
               *LAST_PTR = '\0';
               ++LAST_PTR;
            }
            return str;
         }
      }

      if (LAST_PTR != NULL) {
         char *ret = LAST_PTR;

         if (ret) {
            while (strcspn(ret, separators) == 0 && *ret != '\0')
               ++ret;
         }
         LAST_PTR = (*ret == '\0') ? NULL : strpbrk(ret, separators);


         if (LAST_PTR != NULL) {
            *LAST_PTR = '\0';
            ++LAST_PTR;
            if (*LAST_PTR == '\0') {
               LAST_PTR = NULL;
            }
         }
         return (*ret == '\0') ? NULL : ret;
      }
   }
   return NULL;
}


int main() {
   printf(" -------------------- PROGRAM ----------------------\n\n");
   char my_test_str_1[] = "Super puper test string to test strtok.";
   char test_str_1[] = "Super puper test string to test strtok.";

   // Happy cases?
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

   my_res = my_strtok(NULL, " ");
   res = strtok(NULL, " ");
   assert(res == my_res);


   // Bounds cases
   char my_test_str_2[] = "Super puper-test: string to test strtok 2-nd variant.";
   char test_str_2[] = "Super puper-test: string to test strtok 2-nd variant.";

   my_res = my_strtok(my_test_str_2, "S -:.");
   res = strtok(test_str_2, "S -:.");

   while (my_res || res) {
      assert(strcmp(my_res, res) == 0);
      my_res = my_strtok(NULL, "S -:.");
      res = strtok(NULL, "S -:.");
   }

   // Errors
   my_res = my_strtok(my_test_str_2, "/");
   res = strtok(test_str_2, "/");
   assert(strcmp(res, my_res) == 0);

   my_res = my_strtok(NULL, "/");
   res = strtok(NULL, "/");
   assert(my_res == res);

   my_res = my_strtok(NULL, NULL);
   //res = strtok(NULL, NULL);
   assert(my_res == NULL);


   char my_test_str_3[] = "..Super puper-test: string to test strtok  variant No3.";
   char test_str_3[] = "..Super puper-test: string to test strtok  variant No3.";

   my_res = my_strtok(my_test_str_3, "S -:.");
   res = strtok(test_str_3, "S -:.");

   while (my_res || res) {
      assert(strcmp(my_res, res) == 0);
      my_res = my_strtok(NULL, "S -:.");
      res = strtok(NULL, "S -:.");
   }


   char my_only_separators[] = "     ";
   char only_separators[] = "     ";
   char *t1 = my_strtok(my_only_separators, " ");
   char *t2 = strtok(only_separators, " ");
   assert(t1 == t2);


   char my_empty[] = "";
   char empty[] = "";
   t1 = my_strtok(my_empty, ",");
   t2 = strtok(empty, ",");
   assert(t1 == t2);


   assert(my_strtok("hello", NULL) == NULL);

   printf("All tests passed!\n");
   return 0;
}