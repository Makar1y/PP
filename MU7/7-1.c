#include <stdio.h>

int isInRange (int number, int low, int high) {
    if((number >= low) && (number <= high) && (low <= high))
        return 1;
    return 0;
}

int main() {
    
    printf("%d", isInRange(5, 5, 10));
    return 0;
}