#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// #define assert(ignore) ((void) 0)

// -------------------------- ↓ POINTS ↓ ---------------------------

typedef struct {
    double x, y;
} Point;


void printPoint(Point p) {
    printf("(%f, %f)", p.x, p.y);
}

Point createPoint(double x, double y) {
    Point result = {x, y};
    return result;
}
//                            ^        ^
// -------------------------- | POINTS | ---------------------------

typedef struct List {
   Point value;
   struct List *next;
} List;


List *createList(Point value) {
   List *list = malloc(sizeof(List));

   if (list != NULL){
      list->value = value;
      list->next = NULL;
   }

   return list;
}

void printList(List *list) {
   if (list != NULL) {
      printPoint(list->value);
      printf(" ");
      printList(list->next);
   }
}

int getListSize(List *list) {
   int counter = 0;
   List *tmp = list;
   
   while(tmp != NULL) {
      ++counter;
      tmp = tmp->next;
   }
   return counter;
}

void insertElement(List **list, Point value) {
   List *new = createList(value);
   new->next = *list;
   *list = new;
}

Point getElement(List *list) {
   if (list != NULL) {
      Point ret = list->value;
      return ret;
   }
   assert(list);
}

Point deleteElement(List **list) {
   if (list != NULL) {
      Point ret = getElement(*list);
      List *next = (*list)->next;

      if (next == NULL) {
         free(*list);
      }

      *list = next;
      return ret;
   }
   assert(list);
}

void destroyList(List **list){
   if (list != NULL) {
      List *tmp = *list;

      while (tmp != NULL) {
         List *next = tmp->next;

         free(tmp);
         tmp = next;
      }
      *list = NULL;
   }
}


int main() {
   srand(time(NULL));
   List *list = createList(createPoint(1, 5.123));
   assert(1 == getListSize(list));

   printf("printList: ");
   printList(list);

   insertElement(&list, createPoint(5, 5));
   assert(2 == getListSize(list));

   printf("\ngetElement: "); printPoint(getElement(list));
   printf("\ndeleteElement: "); printPoint(deleteElement(&list));
   assert(1 == getListSize(list));

   for (int i = 0; i < 10; ++i) {
      double x = -50 + (rand() % 10001) * 0.01;
      double y = -50 + (rand() % 10001) * 0.01;
      insertElement(&list, createPoint(x, y));
   }
   assert(11 == getListSize(list));

   printf("\nprintList: ");
   printList(list);

   destroyList(&list);
   assert(0 == getListSize(list));

   return 0;
}