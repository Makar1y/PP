#include <stdio.h>
#include <assert.h>
#include <string.h>

char* my_strchr(const char *str1, const int str2) {
   if (str1 != NULL) {
      size_t len = strlen(str1);
      
      for(int i = 0; i <= len; ++i)
         if (str1[i] == str2)
            return (char*)(str1 + i);
   }
   return NULL;
}

int main() {
   char strtest1[] = "Test str";
   char strtest2[] = "Test2";
   
   // Happy cases
   assert(my_strchr(strtest1, ' ') == strchr(strtest1, ' '));
   assert(my_strchr(strtest1, 's') != strchr(strtest1, 'r'));

   // Bounds cases
   assert(my_strchr(strtest1, 'T') == strchr(strtest1, 'T'));
   assert(my_strchr(strtest1, '\\') == strchr(strtest1, '\\'));
   assert(my_strchr(strtest1, 'r') == strchr(strtest1, 'r'));

   // Errors
   assert(my_strchr("", 'n') == strchr("", 'n'));

   printf("Check ");
   assert(my_strchr(NULL, 'n') == NULL);
   printf("passed\n");

   printf("Check ");
   assert(my_strchr(strtest2, 0) == strchr(strtest2, 0));
   printf("passed\n");

   printf("Check ");
   assert(my_strchr(strtest2, '\0') == strchr(strtest2, '\0'));
   printf("passed\n");

   return 0;
}