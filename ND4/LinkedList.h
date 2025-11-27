#ifndef linked_list_h
#define linked_list_h

struct list_struct {
   int data;
   struct list_struct *next;
};

typedef struct list_struct linked_list;

void *create_list_with_element(int number);

void *add_element_to_list(linked_list *list, int number);

void destroy_list(linked_list *list_head);

void print_list(linked_list *list_head);
#endif