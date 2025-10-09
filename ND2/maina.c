#include <stdio.h>
#include <stdlib.h>

void welcome_print() {
    printf("Enter numbers one by one and ending with not number to stop.\n"
           "Program will count and print Min and Max numbers,\n"
           "Set [MIN , MIN+(MAX-MIN)/3]\n"
           "Set [MIN+(MAX-MIN)/3 , MIN+(MAX-MIN)*2/3]\n"
           "Set [MIN+(MAX-MIN)*2/3 , MAX]\n\n");
}

void fill_array(int aray[], int *size, int *max, int *min) {
    while (1) {
        printf("Enter number %d: ", *size + 1);

        // Scan
        if (scanf("%d", &aray[*size]) != 1) {
            printf("All numbers entered.");
            return;
        }

        // Min & Max finding
        if (*size == 0)
            *max = *min = aray[*size];
        else {
            if (*max < aray[*size])
                *max = aray[*size];
            else if (*min > aray[*size])
                *min = aray[*size];
        }

        *size += 1;
        aray = realloc(aray, *size * sizeof(int));
    }
}


int main() {
    int size = 0;
    int max = 0, min = 0;
    int first = 1;
    int *dynamic_array = calloc(1, sizeof(int));

    if (dynamic_array == NULL) {
        printf("Error, unable to locate memory.");
        return 1;
    }

    welcome_print();


    // Nums entering
    fill_array(dynamic_array, &size, &max, &min);

    printf("\n\nMin: %d    Max: %d", min, max);


    // Printing [MIN , MIN+(MAX-MIN)/3]
    //                       |
    //     ------------------
    //    |
    int nums12 = min + (max - min) / 3;

    printf("\n\n[MIN , MIN+(MAX-MIN)/3] [%d, %d]", min, min+(max-min)/3);
    printf("\n{");

    for (int i = 0; i < size; ++i) {
        if ( (min <= dynamic_array[i]) && (dynamic_array[i] <= nums12) ) {
            if (first == 1) {
                printf("%d", dynamic_array[i]);
                first = 0;
            } else
                printf(", %d", dynamic_array[i]);
        }
    }
    first = 1;

    printf("}");


    // Printing [MIN+(MAX-MIN)/3 , MIN+(MAX-MIN)*2/3]
    //                 |                        |
    //     ------------                         |
    //    |                                     |
    int nums21 = min + (max - min) / 3; //      |
    int nums22 = min + (max - min) * 2 / 3; // -|

    printf("\n\n[MIN+(MAX-MIN)/3 , MIN+(MAX-MIN)*2/3] [%d, %d]", min+(max-min)/3, min+(max-min)*2/3);
    printf("\n{");

    for (int i = 0; i < size; i++) {
        if ( (nums21 <= dynamic_array[i]) && (dynamic_array[i] <= nums22) ) {
            if (first == 1) {
                printf("%d", dynamic_array[i]);
                first = 0;
            } else
                printf(", %d", dynamic_array[i]);
        }
    }
    first = 1;

    printf("}");



    // Printing [MIN+(MAX-MIN)*2/3 , MAX]
    //                 |
    //     ------------
    //    |
    int nums31 = min + (max - min) * 2 / 3;

    printf("\n\n[MIN+(MAX-MIN)*2/3 , MAX] = [%d, %d]", min+(max-min)*2/3, max);
    printf("\n{");

    for (int i = 0; i < size; i++) {
        if ( (nums31 <= dynamic_array[i]) && (dynamic_array[i] <= max) ) {
            if (first == 1) {
                printf("%d", dynamic_array[i]);
                first = 0;
            } else
                printf(", %d", dynamic_array[i]);
        }
    }

    printf("}");

    free(dynamic_array);
    return 0;
}
