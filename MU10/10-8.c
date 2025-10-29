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


   printf("\n-------------------- GPT TESTS ----------------------\n");

   // 1️⃣ Consecutive separators — ensure no empty tokens
   char my_s1[] = "A,,B,,,C";
   char s1[] = "A,,B,,,C";
   t1 = my_strtok(my_s1, ",");
   t2 = strtok(s1, ",");
   while (t1 || t2) {
      assert((t1 && t2 && strcmp(t1, t2) == 0) || (!t1 && !t2));
      t1 = my_strtok(NULL, ",");
      t2 = strtok(NULL, ",");
   }

   // 2️⃣ Leading separators — should skip them
   char my_s2[] = ",,start middle end";
   char s2[] = ",,start middle end";
   t1 = my_strtok(my_s2, ", ");
   t2 = strtok(s2, ", ");
   while (t1 || t2) {
      assert((t1 && t2 && strcmp(t1, t2) == 0) || (!t1 && !t2));
      t1 = my_strtok(NULL, ", ");
      t2 = strtok(NULL, ", ");
   }

   // 3️⃣ No delimiters at all — one full token
   char my_s3[] = "nodelem";
   char s3[] = "nodelem";
   t1 = my_strtok(my_s3, ",");
   t2 = strtok(s3, ",");
   assert((t1 && t2 && strcmp(t1, t2) == 0) || (!t1 && !t2));
   assert(my_strtok(NULL, ",") == strtok(NULL, ","));

   // 4️⃣ Different delimiters in sequence
   char my_s4[] = "a;b:c-d";
   char s4[] = "a;b:c-d";
   t1 = my_strtok(my_s4, ";:-");
   t2 = strtok(s4, ";:-");
   while (t1 || t2) {
      assert((t1 && t2 && strcmp(t1, t2) == 0) || (!t1 && !t2));
      t1 = my_strtok(NULL, ";:-");
      t2 = strtok(NULL, ";:-");
   }

   // 5️⃣ Reinitialize new string after finishing previous
   char my_s5[] = "first second third";
   char s5[] = "first second third";
   t1 = my_strtok(my_s5, " ");
   t2 = strtok(s5, " ");
   while (t1 || t2) {
      assert((t1 && t2 && strcmp(t1, t2) == 0) || (!t1 && !t2));
      t1 = my_strtok(NULL, " ");
      t2 = strtok(NULL, " ");
   }

   // Then start a completely new string (state reset)
   char my_s6[] = "reset works fine";
   char s6[] = "reset works fine";
   t1 = my_strtok(my_s6, " ");
   t2 = strtok(s6, " ");
   while (t1 || t2) {
      assert((t1 && t2 && strcmp(t1, t2) == 0) || (!t1 && !t2));
      t1 = my_strtok(NULL, " ");
      t2 = strtok(NULL, " ");
   }

   // 6️⃣ String with only delimiters (different set)
   char my_s7[] = "---";
   char s7[] = "---";
   t1 = my_strtok(my_s7, "-");
   t2 = strtok(s7, "-");
   assert(t1 == t2);


   printf("All extra tests passed successfully!\n");
   return 0;
}