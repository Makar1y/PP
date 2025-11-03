#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE_PART 5

typedef struct {
   int *ptr;
   int size;
} Stack;


void initStack(Stack *stack) {
   stack->ptr = NULL;
   stack->size = 0;
}

void printStack(Stack *stack) {
   if (stack != NULL) {
      for (int i = 0; i < stack->size; ++i) {
         printf("%d ", stack->ptr[i]);
      }
   }
}

/// @return Stack size if possible, otherwise error code -1.
int getStackSize(Stack *stack) {
   if (stack != NULL)
      return stack->size;
   return -1;
}

/// @result If possible pushes and updates stack,
/// otherwise silent fail.
void push(Stack *stack, int value) {
   if (stack != NULL) {
      if (stack->size == 0 || (stack->size % SIZE_PART == 0)) {
         int *tmp = realloc(stack->ptr, (stack->size + SIZE_PART) * sizeof(int));

         if (tmp == NULL) {
            return;
         }

         stack->ptr = tmp;
      }
      stack->ptr[stack->size] = value;
      ++stack->size;
   }
}

/// @return If possible -> stack element or 0 if stack empty,
/// otherwise -> undefined behavior.
int top(Stack *stack) {
   if (stack != NULL) {
      if (stack->size > 0) {
         return stack->ptr[stack->size - 1];
      }
      return 0;
   }
}

/// @return If possible -> stack element or 0 if stack empty,
/// otherwise -> undefined behavior.
int pop(Stack *stack) {
   if (stack != NULL) {
      int result = top(stack);
      if (stack->size > 0) {
         --stack->size;
      }
      return result;
   }
}

void destroyStack(Stack *stack) {
   if (stack != NULL) {
      if (stack->ptr != NULL) {
         free(stack->ptr);
         stack->ptr = NULL;
         stack->size = 0;
      }
   }
}

int main() {
   Stack stack;
   initStack(&stack);

   push(&stack, 25);
   assert(getStackSize(&stack) == 1);
   assert(top(&stack) == 25);

   push(&stack, -45);
   assert(getStackSize(&stack) == 2);
   printStack(&stack);

   assert(pop(&stack) == -45);

   assert(getStackSize(&stack) == 1);
   assert(top(&stack) == 25);
   assert(getStackSize(&stack) == 1);

   destroyStack(&stack);
   assert(getStackSize(&stack) == 0);
   printStack(&stack);

   printf("\n(0^0)");
   return 0;
}