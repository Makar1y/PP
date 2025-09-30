#include <stdio.h>

#define SIZE 10

int main() {
    int size = SIZE;
    int index = 0;
    int value = 0;


    // 1
    int array[SIZE] = {0};

    // 2
    printf("Clear array:\n");
    printf("{");
    for (int i = 0; i < size; ++i) {
        if (i!=0)
            printf(", %d", array[i]);
        else
            printf("%d", array[i]);
    }
    printf(" }\n\n");


    // 3
    array[0] = 1; array[3] = 2; array[9] = 3;


    // 4
    --size;

    for (int i = 2; i < size; ++i) {
        array[i] = array[i + 1];
    }


    // 5
    for (int i = size - 1; i > 6; --i) {
        array[i + 1] = array[i];
    } array[6] = 4;

    ++size;


    // 6
    printf("Not clear array:\n");
    printf("{");
    for (int i = 0; i < size; ++i) {
        if (i!=0)
            printf(", %d", array[i]);
        else
            printf("%d", array[i]);
    }
    printf(" }\n\n");


    // 7
    printf("Please enter array index to set value(from 0 to 9).\n");
    printf(": ");
    while (1)
    {
        if (scanf("%d", &index) == 1 && getchar() == '\n') {
            if (index > 9 || index < 0) {
                printf("Error, please enter number from 0 to 9.\n");
                printf(": ");
            } else {
                printf("Index successfully set to %d.\n", index);
                break;
            }
        } else {
            while (getchar() != '\n');
            printf("Error, please enter whole number.\n");
            printf(": ");
        }
    }

    printf("Now please enter value for this index.\n");
    printf(": ");
    while (1)
    {
        if (scanf("%d", &value) == 1 && getchar() == '\n') {
            printf("Value successfully set to %d.\n", value);
            break;
        } else {
            while (getchar() != '\n');
            printf("Error, please enter whole number.\n");
            printf(": ");
        }
    }
    array[index] = value;
    printf("Changes applied.\n\n");


    // 8
    printf("Now please enter index to remove from array.\n");
    printf(": ");
    while (1)
    {
        if (scanf("%d", &index) == 1 && getchar() == '\n') {
            if (index > 9 || index < 0) {
                printf("Error, please enter number from 0 to 9.\n");
                printf(": ");
            } else {
                printf("Index %d will be removed.\n", index);
                break;
            }
        } else {
            while (getchar() != '\n');
            printf("Error, please enter whole number.\n");
            printf(": ");
        }
    }

    --size;

    for (int i = index; i < size; ++i) {
        array[i] = array[i + 1];
    }
    printf("Changes applied.\n");
    printf("Now array have 9 elements.\n\n");


    // 9
    printf("To add element to array enter value and index where this value should stand.\n");
    printf("Please enter index(from 0 to 9).\n");
    printf(": ");
    while (1)
    {
        if (scanf("%d", &index) == 1 && getchar() == '\n') {
            if (index > 9 || index < 0) {
                printf("Error, please enter number from 0 to 9.\n");
                printf(": ");
            } else {
                printf("Index successfully set to %d.\n", index);
                break;
            }
        } else {
            while (getchar() != '\n');
            printf("Error, please enter whole number.\n");
            printf(": ");
        }
    }

    printf("Now please enter value for this index.\n");
    printf(": ");
    while (1)
    {
        if (scanf("%d", &value) == 1 && getchar() == '\n') {
            printf("Value successfully set to %d.\n", value);
            break;
        } else {
            while (getchar() != '\n');
            printf("Error, please enter whole number.\n");
            printf(": ");
        }
    }

    for (int i = size - 1; i > index; --i) {
        array[i + 1] = array[i];
    } array[index] = value;

    ++size;


    array[index] = value;
    printf("Changes applied.\n");
    printf("Now array have 9 elements.\n\n0");

    
    // 10
    printf("Final array:\n");
    printf("{");
    for (int i = 0; i < size; ++i) {
        if (i!=0)
            printf(", %d", array[i]);
        else
            printf("%d", array[i]);
    }
    printf(" }\n");        

    return 0;
}