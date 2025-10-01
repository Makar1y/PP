#include <stdio.h>
#include <stdint.h>


int clear_array(int *array) {
    for (int i = 0; i < 10; ++i) {
        array[i] = 0;
    }
}


int main() {
    long x, x_copy; // x and its copy //// on my pc long = int :)
    int size; // size of input array
    int temporary; // temporary values
    int cant = 0; // if from x digits cant make other nums
    int num_digits_frequency[10] = {0}; // digits frequency for x
    int x_digits_frequency[10] = {0}; // digits frequency for number

    printf("Please enter positive number x, then array size(less that 1000), then array values.\n");
    printf("Program will check if from number x digits can get all arrays numbers.\n");

    // x entering
    printf("Please enter x: ");
    while(1) {
        if (scanf("%ld", &x) == 1 && getchar() == '\n') {
            printf("Number x=%ld entered successfully.\n\n", x);
            break;
        }
        else {
            while (getchar() != '\n');
            printf("!!! Error, please enter whole number: ");
        }
    }


    // size entering
    printf("Please enter size: ");
    while(1) {
        if (scanf("%d", &size) == 1 && getchar() == '\n') {
            if (size > 0 && size < 1000) {
                printf("Size entered successfully(%d).\n\n", size);
                break; 
            } else {
                printf("!!! Error, size must be positive and less than 1000: ");
            }
        }
        else {
            while (getchar() != '\n');
            printf("!!! Error, please enter whole number: ");
        }
    }

    int array[size];

    // values entering
    for (int i = 0; i < size; ++i) {
        printf("Please enter %d number: ", i + 1);
        while (1) {
            if (scanf("%d", &array[i]) == 1 && getchar() == '\n') {
                printf("Number %d entered successfully.\n", array[i]);
                break;
            }
            else {
                while (getchar() != '\n');
                printf("!!! Error, please enter whole number: ");
            }  
        }
    }




    x_copy = x;
    while (x_copy)
    {
        ++x_digits_frequency[ x_copy % 10];
        x_copy /= 10;
    }

    // int num_digits_frequency[10];
    for (int i = 0; i < size; ++i) {
        temporary = array[i];
        clear_array(num_digits_frequency);

        while (temporary) {
            ++num_digits_frequency[temporary % 10];
            temporary /= 10;
        }

        for (int j = 0; j < 10; ++j) {
            if (num_digits_frequency[j] > x_digits_frequency[j]) {
                cant = 1;
                break;
            }
        }
        
        if (cant) {
            break;
        }
    }


    // result printing
    if (cant) {
        printf("\nFrom number %d digits cant get all these numbers:\n", x);
    } else {
        printf("From number %d digits can get all these numbers:\n", x);
    }

    printf("{");
    for (int i = 0; i < size; ++i) {
        if (i == 0) {
            printf("%d", array[i]);
        } else {
            printf(", %d", array[i]);
        }
    } printf("}\n");

    return 0;
}