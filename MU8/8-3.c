#include <stdio.h>

int swap(int *a, int *b) {
    if ((a != NULL) && (b != NULL)) {
        int tmp = *a;
    
        *a = *b;
        *b = tmp;

        return 1;
    }
    return 0;
}


int main() {
    int a = 5, b = 10;
    swap(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}