#include <stdio.h>
#include <stdlib.h>

typedef struct List {
   int value;
   struct List *next;
} List;


List *createList(int value) {
   List *list = malloc(sizeof(List));

   if (list != NULL){
      list->value = value;
      list->next = NULL;
   }

   return list;
}

void printList(List *list) {
   if (list != NULL) {
      printf("%d ", list->value);
      printList(list->next);
   }
}

int getListSize(List *list) {
   int counter = 0;
   List *tmp = list->next;
   
   while(tmp != NULL) {
      ++counter;
      tmp = tmp->next;
   }
   return counter;
}

void insertElement(List **list, int value) {
   List *ls = *list;
   int last = value;
   int i = 0;
   int tmp;

   while (ls->next != NULL) {
      tmp = ls->value;
      ls->value = last;
      last = tmp;

      ls = ls->next;
      ++i;
   }

   tmp = ls->value;
   ls->value = last;

   


}


int main() {
   List *list = createList(5);

   printList(list);
   
   getListSize(list);


   return 0;
}