#include <stdio.h>
#include <assert.h>
#include <string.h>

#define LARGE_SIZE 1000000

char *my_strpbrk(const char *str1, const char *str2) {
   if (str1 != NULL && str2 != NULL)
      for (int i = 0; str1[i] != '\0'; ++i)
         for (int j = 0; str2[j] != '\0'; ++j)
            if (str1[i] == str2[j])
               return (char*)str1 + i;
   return NULL;
}

int main(void) {
   printf(" ---------------------------- PROGRAM ----------------------------- \n\n");
   char str[] = "Test string to find pointer to char)";

   // Happy cases
   assert(my_strpbrk(str, " ") == strpbrk(str, " "));
   assert(my_strpbrk(str, "find") == strpbrk(str, "find"));
   assert(my_strpbrk(str, "rr") == strpbrk(str, "r"));

   // Bounds cases
   assert(my_strpbrk(str, "\\|/") == strpbrk(str, "\\|/"));
   assert(my_strpbrk(str, "T") == strpbrk(str, "T"));
   assert(my_strpbrk(str, ")") == strpbrk(str, ")"));

   static char str_test_large[LARGE_SIZE + 1];
   memset(str_test_large, 'a', sizeof(char) * (LARGE_SIZE));
   str_test_large[LARGE_SIZE] = '\0';
   str_test_large[LARGE_SIZE - 1] = 'b';
   assert(my_strpbrk(str_test_large, "b") == strpbrk(str_test_large, "b"));

   // Error cases
   assert(my_strpbrk(NULL, "T") == NULL);
   assert(my_strpbrk(str, NULL) == NULL);

   printf("All tests passed!\n");
   return 0;
}
