#include <stdio.h>
#include <assert.h>
#include <string.h>

size_t my_strcspn(const char *str1, const char *str2) {
   if (str1 != NULL && str2 != NULL)
      for (size_t i = 0; str1[i] != '\0'; ++i)
         for (size_t j = 0; str2[j] != '\0'; ++j)
            if (str1[i] == str2[j])
               return i;
      return strlen(str1);
   return 0;
}

int main(void) {
   // Happy cases
   assert(my_strcspn("hello, world", ",!") == strcspn("hello, world", ",!"));
   assert(my_strcspn("abcdef", "xyz") == strcspn("abcdef", "xyz"));
   assert(my_strcspn("123abc", "abc") == strcspn("123abc", "abc"));
   assert(my_strcspn("123bc", "abc") == strcspn("123bc", "abc"));

   // Bounds checks
   assert(my_strcspn("", "abc") == strcspn("", "abc"));
   assert(my_strcspn("", "") == strcspn("", ""));
   assert(my_strcspn("test", "") == strcspn("test", ""));

   // Errors
   assert(my_strcspn(NULL, "abc") == 0);
   assert(my_strcspn("abc", NULL) == 0);

   printf("All tests passed!\n");
   return 0;
}
