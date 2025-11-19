#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef DEBUG
   #define assert(ignore) ((void) 0);
#endif

typedef struct
{
   int data;
   void *next;
} List;


void* create_List() {
   return calloc(1, sizeof(List));
};

void* add_List_element(List *list, int element) {
   if (list) {
      List *current = list;

      while (current->next) {
         current = current->next;    
      }

      List *ptr = calloc(1, sizeof(List));
      if (ptr) {
         current->next = ptr;
         ptr->data = element;
         return ptr;
      }
   }
   return NULL;
}

void destroy_List(List *list) {
   List *current = list;
   List *for_free = current;
   while (current) {
      for_free = current;
      current = current->next;
      free(for_free);
   }
}

void print_List(List *list) {
   if(list) {
      List *current = list;

      while (current) {
         printf("%d ", current->data);
         current = current->next;
      }
      printf("\n");
   }
}


void reverse_list(List **list) {
   if (list && (*list)->next) {
      List *previous = NULL;
      List *current = *list;
      List *next = (*list)->next;
         
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
   List *list = create_List();
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