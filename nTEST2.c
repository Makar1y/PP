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
   } z = {{{.y=1},{.y=2}}, 0};

//         {0},1,{0},2, {{9,9,{0},3,{0},4,{0},5},  {9,9,{0},6,{0},7,{0},8}}

   printf("!");
   return 0;
}
// 7-8) pirmas atmintyje (daryti prielaidą kad atmintyje kodas bus iš eilės ta tvarka, kuria būtų nuosekliai skaitant kodą,
// o ne pvz. "apverstas") esantis laukas y turėtų reikšmę 1, antras - 2, trečias - 3 ir t.t.