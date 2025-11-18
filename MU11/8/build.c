#include <stdlib.h>

int main() {

   system("gcc -c file.c -o file.o");
   system("gcc -c counters.c -o counters.o");

   system("gcc -shared -o libdynamic.dll file.o counters.o");
   system("ar rc -o libstatic.a file.o counters.o");

   system("gcc 11-8.c -L. -lstatic -o static.exe");
   system("gcc 11-8.c -L. -ldynamic -o dynamic.exe");
   return 0;
}