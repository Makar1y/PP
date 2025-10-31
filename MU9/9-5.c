#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct DLL {
   char *str;
   struct DLL *previous;
   struct DLL *next;
} DoublyLinkedList;


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
   if (*list == NULL) return;
   DoublyLinkedList *sorted = NULL;
   DoublyLinkedList *current = *list;

   while (current != NULL) {
      DoublyLinkedList *next = current->next;

      if (sorted == NULL || strcmp(sorted->str, current->str) >= 0) {
         current->next = sorted;

         if (sorted != NULL) sorted->previous = current;

         sorted = current;
         sorted->previous = NULL;

      } else {
         DoublyLinkedList *current_sorted = sorted;

         while (current_sorted->next != NULL && strcmp(current_sorted->next->str, current->str) < 0) {
            current_sorted = current_sorted->next;
         }

         current->next = current_sorted->next;

         if (current_sorted->next != NULL)
            current_sorted->next->previous = current;

            current_sorted->next = current;
            current->previous = current_sorted;
      }
      current = next;
   }
   *list = sorted; // return
}

void sort_min_to_max(DoublyLinkedList **list, int reverse) {
   if (*list == NULL) return;
   DoublyLinkedList *sorted = NULL;
   DoublyLinkedList *current = *list;

   while (current != NULL) {
      DoublyLinkedList *next = current->next;
      int curr_str_len = strlen(current->str);
      int sorted_str_len = (sorted && (sorted->str != NULL)) ? strlen(sorted->str) : 0;

      int reverse_direction = reverse ? (sorted_str_len <= curr_str_len) : (sorted_str_len >= curr_str_len);
      if (sorted == NULL || reverse_direction) {
         current->next = sorted;

         if (sorted != NULL) sorted->previous = current;

         sorted = current;
         sorted->previous = NULL;

      } else {
         DoublyLinkedList *current_sorted = sorted;
         int current_sorted_next_str_len = strlen(current_sorted->next->str);

         if (reverse) {
            while (current_sorted->next != NULL && current_sorted_next_str_len > curr_str_len) {
               current_sorted = current_sorted->next;
               current_sorted_next_str_len = strlen(current_sorted->next->str);
            }
         } else {
            while (current_sorted->next != NULL && current_sorted_next_str_len < curr_str_len) {
               current_sorted = current_sorted->next;
               current_sorted_next_str_len = strlen(current_sorted->next->str);
            }
         }

         current->next = current_sorted->next;

         if (current_sorted->next != NULL)
            current_sorted->next->previous = current;

            current_sorted->next = current;
            current->previous = current_sorted;
      }
      current = next;
   }
   *list = sorted; // return
}


int main() {
   DoublyLinkedList *list = create_dll_list("First");
   assert(list != NULL);

   insert_element(&list, "Hello world");
   assert(list != NULL);
   assert(list->next != NULL);

   insert_element(&list, "clarify");
   insert_element(&list, "duke");
   insert_element(&list, "green");
   insert_element(&list, "abolish");
   insert_element(&list, "recession");
   insert_element(&list, "apparatus");
   insert_element(&list, "turn");
   insert_element(&list, "thumb");
   insert_element(&list, "rise");
   insert_element(&list, "progressive");
   assert(list != NULL);

   printf("Min to max:\n");
   sort_min_to_max(&list, 0);
   print_list(list);

   printf("\nMax to min:\n");
   sort_min_to_max(&list, 1);
   print_list(list);

   printf("\nAlphabetical:\n");
   sort_alphabet(&list);
   print_list(list);

   destroyList(&list);
   return 0;
}
