#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

char *LAST_PTR = NULL;

char* my_strtok(char *str, const char *separators) {
   if (str == NULL) {
      printf("%c%c%c", LAST_PTR[0], LAST_PTR[1], LAST_PTR[2]);
      for (int i = 0; LAST_PTR[i] != '\0'; ++i) {
         if (LAST_PTR[i] = *separators) {
            str = LAST_PTR;
            LAST_PTR += i;
            LAST_PTR[-1] = '\0';
            return str;
         }
      }
   } else {
      LAST_PTR = str + 6;
      str[5] = '\0';
      return str;
   }
   printf("Error!");
   exit(1);
}


int m3ain() {
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