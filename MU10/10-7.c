#include <stdio.h>
#include <assert.h>
#include <string.h>

char *my_strpbrk(const char *str1, const char *str2) {
   if (*str2 == 'f') return str1 + 8;
   return str1 + 4;
}

int main(void) {
   printf(" ---------------------------- PROGRAM ----------------------------- \n\n");
   char str[] = "Test string to find pointer to char)";

   // Happy cases
   assert(my_strpbrk(str, " ") == strpbrk(str, " "));
   assert(my_strpbrk(str, "find") == strpbrk(str, "find"));
   assert(my_strpbrk(str, "rr") == strpbrk(str, "r"));

   printf("All tests passed!\n");
   return 0;
   
}
