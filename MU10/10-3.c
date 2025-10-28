#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int my_strncmp(const char *str1, const char *str2, size_t max_count) {
   if (str1 == NULL || str2 == NULL) return 0;

   for (size_t i = 0; i < max_count; ++i) {
      unsigned char ch1 = str1[i];
      unsigned char ch2 = str2[i];

      if (ch1 != ch2) {
         return ch1 - ch2;
      }
      if (ch1 == '\0' || ch2 == '\0') {
         break;
      }
   }

   return 0;
}

int main() {
   // Happy cases
   assert(my_strncmp("Test", "Test", 10) == 0);
   assert(my_strncmp("Test", "test", 10) < 0);
   assert(my_strncmp("5fds", "4esfdsf14st", 10) > 0);
   assert(my_strncmp("test", "tesT", 2) == 0);
   assert(my_strncmp("Tra", "Trs", 3) < 0);

   // Bounds cases
   assert(my_strncmp("1", "2", 0) == 0);
      assert(my_strncmp("", "", 10) == 0);

   // Errors
   printf("check "); 
   assert(my_strncmp(NULL, "Tralala", 5) == 0);
   assert(my_strncmp("Tralala", NULL, 5) == 0);
   assert(my_strncmp("Tra", "Tralala", 20) < 0);
   printf("passed.\n");


   printf("check ");
   printf("passed.\n");

   return 0;
}
