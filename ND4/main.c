#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "LinkedList.h"

#define TEST_SIZE 10


void reverse_list(linked_list ** list) {
   if (list && (*list)->next) {
      linked_list *previous = NULL;
      linked_list *current = *list;
      linked_list *next = (*list)->next;
         
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

int main() {
   linked_list *list_head = create_list_with_element(0);
   assert(list_head);

   for (int i = 1; i < TEST_SIZE; ++i) {
      add_element_to_list(list_head, i);
   }

   print_list(list_head);
   reverse_list(&list_head);
   print_list(list_head);

   destroy_list(list_head);
   return 0;
}