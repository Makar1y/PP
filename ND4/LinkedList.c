#include <stdio.h>
#include <stdlib.h>

typedef struct
{
   int data;
   void *next;
} LinkedList;

void* create_List() {
   return calloc(1, sizeof(LinkedList));
};

void* add_List_element(LinkedList *list, int element) {
   if (list) {
      LinkedList *current = list;

      while (current->next) {
         current = current->next;    
      }

      LinkedList *ptr = calloc(1, sizeof(LinkedList));
      if (ptr) {
         current->next = ptr;
         ptr->data = element;
         return ptr;
      }
   }
   return NULL;
}

void destroy_List(LinkedList *list) {
   LinkedList *current = list;
   LinkedList *for_free = current;
   while (current) {
      for_free = current;
      current = current->next;
      free(for_free);
   }
}

void print_List(LinkedList *list) {
   if(list) {
      LinkedList *current = list;

      while (current) {
         printf("%d ", current->data);
         current = current->next;
      }
      printf("\n");
   }
}
