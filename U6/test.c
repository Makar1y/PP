#include <stdio.h>

int main() {

    for(int sum = 0, i = 1; i < 10; sum = i++)
        printf("%d", sum);

    return 0;
}