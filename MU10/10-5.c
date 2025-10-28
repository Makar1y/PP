#include <stdio.h>
#include <assert.h>
#include <string.h>

void* my_memchr(const char *str, int ch, size_t n) {
   if (str != NULL)
      for (size_t i = 0; i < n; ++i)
         if ((unsigned char)str[i] == ch)
            return str + i;
   return NULL;
}

int main() {
   const char data[] = "Hello, world!";

   // Happy cases
   assert(my_memchr(data, 'H', strlen(data)) == memchr(data, 'H', strlen(data)));
   assert(my_memchr(data, 'w', strlen(data)) == memchr(data, 'w', strlen(data)));
   assert(my_memchr(data, 'x', strlen(data)) == memchr(data, 'x', strlen(data)));

   // Bounds cases
   assert(my_memchr(data, '!', strlen(data)) == memchr(data, '!', strlen(data)));
   assert(my_memchr(data, '\0', strlen(data)) == memchr(data, '\0', strlen(data)));

   // Errors
   assert(my_memchr(NULL, 'H', 20) == NULL);
   assert(my_memchr(data, 200, 20) == memchr(data, 200, 20));


   unsigned char bytes[] = { 10, 255, 128, 0, 200 };
   size_t nbytes = sizeof(bytes);

   void *std_res = memchr(bytes, 200, nbytes);
   void *my_res  = my_memchr(bytes, 200, nbytes);
   assert(std_res == my_res);

   printf("All tests passed!\n");
   return 0;
}