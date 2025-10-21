#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE_PART 1

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
   Point *points;
   int size;
} Stack;


void printPoint(Point p) {
    printf("(%f, %f)", p.x, p.y);
}

Point createPoint(double x, double y) {
    Point result = {x, y};
    return result;
}

double getDistance(Point a, Point b) {
    double x_square = (a.x - b.x) * (a.x - b.x);
    double y_square = (a.y - b.y) * (a.y - b.y);

    return sqrt(x_square + y_square);
}


void initStack(Stack *stack) {
   stack->points = NULL;
   stack->size = 0;
}

void printStack(Stack *stack) {
   if (stack != NULL) {
      Point zero = {0, 0};
      for (int i = 0; i < stack->size; ++i) {
         double x = stack->points[i].x;
         double y = stack->points[i].y;
         double distance = getDistance(zero, stack->points[i]);

         printf("%d Point (%.2f, %.2f), Distance to (0, 0): %f\n", i + 1, x, y, distance);
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
void push(Stack *stack, Point value) {
   if (stack != NULL) {
      if (stack->size == 0 || (stack->size % SIZE_PART == 0)) {
         Point *tmp = realloc(stack->points, (stack->size + SIZE_PART) * sizeof(Point));

         if (tmp == NULL) {
            return;
         }

         stack->points = tmp;
      }
      stack->points[stack->size].x = value.x;
      stack->points[stack->size].y = value.y;
      ++stack->size;
   }
}

/// @return If possible -> stack element or 0 if stack empty,
/// otherwise -> undefined behavior.
Point top(Stack *stack) {
   if (stack != NULL) {
      if (stack->size > 0) {
         return stack->points[stack->size - 1];
      }

      Point zero = {0, 0};
      return zero;
   }
}

/// @return If possible -> stack element or 0 if stack empty,
/// otherwise -> undefined behavior.
Point pop(Stack *stack) {
   if (stack != NULL) {
      Point result = top(stack);
      if (stack->size > 0) {
         --stack->size;
      }
      return result;
   }
}

void destroyStack(Stack *stack) {
   if (stack != NULL) {
      if (stack->points != NULL) {
         free(stack->points);
         stack->points = NULL;
         stack->size = 0;
      }
   }
}

int main() {
   Stack stack;
   initStack(&stack);
   srand(time(NULL));

   for (int i = 0; i < 5; ++i) {
      // 100 / 0.01 = 10 000
      // + 0 = 10 001
      double x = -50 + (rand() % 10001) * 0.01;
      double y = -50 + (rand() % 10001) * 0.01;

      push(&stack, createPoint(x, y));
   }

   printStack(&stack);

   
   destroyStack(&stack);
   return 0;
}