#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct DLL {
   char *str;
   struct DLL *previous;
   struct DLL *next;
} DoublyLinkedList;

DoublyLinkedList* sort(DoublyLinkedList *start, DoublyLinkedList *end);
void rec_quicksort(DoublyLinkedList *start, DoublyLinkedList *end);


DoublyLinkedList* create_dll_list(char *str){
   DoublyLinkedList *list = calloc(1, sizeof(DoublyLinkedList));

   if (str != NULL && list != NULL) {
      list->str = str;
   }
   return list;
}

void insert_element(DoublyLinkedList **list, char* str) {
   DoublyLinkedList *new = create_dll_list(str);

   if (new != NULL && list != NULL) {
      new->next = *list;
      (*list)->previous = new;
      *list = new;
   } else {
      if (*list == NULL) {
         *list = NULL;
      }
   }
}

void destroyList(DoublyLinkedList **list){
   if (list != NULL && *list != NULL) {
      DoublyLinkedList *tmp = *list;

      if ((*list)->previous != NULL) {
         while (tmp->previous != NULL) {
            tmp = tmp->previous;
         }
      }

      while (tmp != NULL) {
         DoublyLinkedList *next = tmp->next;

         free(tmp);
         tmp = next;
      }
      *list = NULL;
   }
}

void swap(DoublyLinkedList *first, DoublyLinkedList *second) {
   if (first != NULL && second != NULL) {
      char *tmp = first->str;
      first->str = second->str;
      second->str = tmp;
   }

}

void print_list(DoublyLinkedList *list) {
    DoublyLinkedList *tmp = list;

    while (tmp->previous != NULL) tmp = tmp->previous;
    while (tmp != NULL) {
        printf("%s\n", tmp->str);
        tmp = tmp->next;
    }
}

void sort_alphabet(DoublyLinkedList **list) {

}

void sort_min_to_max(DoublyLinkedList **list, int reverse) {
   if (list != NULL && *list != NULL) {
      DoublyLinkedList *end = *list; 
      while (end->next != NULL) {
         end = end->next;
      }

      rec_quicksort(*list, end);
   }

}


int main() {
   DoublyLinkedList *list = create_dll_list("First");
   assert(list != NULL);

   insert_element(&list, "Hello world");
   assert(list != NULL);
   assert(list->next != NULL);

   insert_element(&list, "second");
   assert(list != NULL);

   sort_min_to_max(&list, 0);

   print_list(list);
   destroyList(&list);

   return 0;
}



DoublyLinkedList* sort(DoublyLinkedList *start, DoublyLinkedList *end) {
    // Base element
    int base_str = strlen(end->str);

    // Starting point
    DoublyLinkedList *i = start->previous;

    // Sorting
   for (DoublyLinkedList *j = start; j != end; j = j->next) {
      if (strlen(j->str) < base_str) {
            i = (i == NULL) ? start : i->next;
            swap(i, j);
      }
   }

    // New base
    i = (i == NULL) ? start : i->next;
    swap(i, end);
    return i;

}

void rec_quicksort(DoublyLinkedList *start, DoublyLinkedList *end) {
    // If more than 1 element
    if (start != end && start != NULL && end != NULL) {

        // Sort + return new base
        DoublyLinkedList *base = sort(start, end);

         // Recursion for left and right side of base element
         if(base != NULL) {
            if (base->previous != NULL) rec_quicksort(start, base->previous);
            if (base->next != NULL) rec_quicksort(base->next, end);
         }
        
    }
}
