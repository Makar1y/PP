#include <stdio.h>

int main() {
   typedef struct {
      float x[3];
      int y;
   } x;
   typedef struct {
      int a, b;
      x y[2]; x x;
   } y;
   struct {
      x y[2];
      y x[2];
      double z;
   } z = {{{2,1},2,1},9,9,{{2,1},2,1},{2,1},9,9,{{2,1},2,1},2,1};
//        {2,1,0,9,2,1},9,9,{2,1,0,9,2,1,0},{2,1},9,9,{2,1,0,9,2,1},2,1

   printf("!");
   return 0;
}
// 5-6) float'ų masyve (visur) pirmas elementas turėtų reikšmę 2.0, antras - 1.0, o trečias - 0.0
//       {2,1,0,9,2,1},9,9,{2,1,0,9,2,1,0},{2,1},9,9,{2,1,0,9,2,1},2,1