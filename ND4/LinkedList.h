#ifndef linked_list_h
#define linked_list_h

struct list_struct {
   int data;
   struct list_struct *next;
};

typedef struct list_struct linked_list;

linked_list *create_list_with_element(const int number);

linked_list *add_element_to_list(linked_list *list, const int number);

void destroy_list(linked_list *list_head);

void print_list(linked_list *list_head);
#endif