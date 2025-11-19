#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "LinkedList.h"


void reverse_list(LinkedList **list) {
   if (list && (*list)->next) {
      LinkedList *previous = NULL;
      LinkedList *current = *list;
      LinkedList *next = (*list)->next;
         
      while (current) {
         next = current->next;
         current->next = previous;
         previous = current;
         current = next;
      }
      *list = previous;
   }
   return;
}

int main()
{
   LinkedList *list = create_List();
   assert(list);

   for (int i = 1; i < 10; ++i) {
      add_List_element(list, i );
   }

   print_List(list);
   reverse_list(&list);
   print_List(list);

   destroy_List(list);
   return 0;
}