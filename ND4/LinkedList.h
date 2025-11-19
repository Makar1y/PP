#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct
{
   int data;
   void *next;
} LinkedList;

void* create_List();

void* add_List_element(LinkedList *list, int element);

void destroy_List(LinkedList *list);

void print_List(LinkedList *list);
#endif