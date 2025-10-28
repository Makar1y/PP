#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


char* my_strcat(char *string1, const char *string2){
   if (string1 == NULL) {
      return NULL;
   }

   size_t strlen1 = strlen(string1), 
          strlen2 = (string2 != NULL) ? strlen(string2) : 0;

   for (size_t i = 0; i < strlen2; ++i) {
      string1[i + strlen1] = string2[i];
   }

   string1[strlen1 + strlen2] = '\0';

   return string1;
}

int main() {
   char str1[100] = "Hello,";
   char str2[100] = "Another";
   char str3[100] = "你好, ";
   char str5[100] = "Hello,";
   char str4[100] = "NULL";

   // Happy cases
   assert(strcmp(my_strcat(str1, " world!"), "Hello, world!") == 0);
   assert(strcmp(my_strcat(str2, " test."), "Another test.") == 0);
   assert(strcmp(my_strcat(str3, "世界!"), "你好, 世界!") == 0);

   // Bounds cases?
   printf("Check ");
   assert(strcmp(my_strcat(str4, NULL), "NULL") == 0);  // original strcat crash
   printf("passed.\n");

   // Errors cases
   printf("Check ");
   assert(strcmp(my_strcat(NULL, NULL), "NULL") == 0);  // original strcat crash
   printf("passed.\n");

   printf("Check ");
   assert(strcmp(my_strcat(NULL, str5), "NULL") == 0);  // original strcat crash
   printf("passed.\n");

    char a[1001], b[501];
    memset(a, 'A', 500); a[500] = '\0';
    memset(b, 'B', 500); b[500] = '\0';
    char *res = my_strcat(a, b);
    assert(strlen(res) == 1000);
    assert(res[0] == 'A' && res[999] == 'B');

   return 0;
}