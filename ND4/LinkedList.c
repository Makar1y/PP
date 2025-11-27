#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

linked_list *create_list_with_element(const int number) {
   linked_list *list = calloc(1, sizeof(linked_list));
   list->data = number;
   return list;
}

linked_list *add_element_to_list(linked_list *list, const int number) {
   if (list) {
      linked_list *current = list;

      while (current->next) {
         current = current->next;
      } /* finding last element */

      linked_list *ptr = calloc(1, sizeof(linked_list));
      if (ptr) {
         current->next = ptr;
         ptr->data = number;
         return ptr;
      } /* create element if possible */
   }
   return NULL;
}
 
void destroy_list(linked_list *list) {
   linked_list *current = list;
   linked_list *for_free = current;
   while (current) {
      for_free = current;
      current = current->next;
      free(for_free);
   }
}

void print_list(linked_list *list) {
   if (list) {
      linked_list *current = list;

      while (current) {
         printf("%d ", current->data);
         current = current->next;
      }
      printf("\n");
   }
}
