#include <stdio.h>

void welcome_print() {
    printf("Enter how numbers will be used, then numbers.\n"
           "Program will count and print Min and Max numbers,\n"
           "Set [MIN , MIN+(MAX-MIN)/3]\n"
           "Set [MIN+(MAX-MIN)/3 , MIN+(MAX-MIN)*2/3]\n"
           "Set [MIN+(MAX-MIN)*2/3 , MAX]\n\n");
}

void fill_array(int aray[], int size, int *max, int *min) {
    for (int i = 0; i < size; i++) {
        printf("Enter number %d: ", i + 1);

        // Scan
        scanf("%d", &aray[i]);

        // Min & Max finding
        if (i == 0)
            *max = *min = aray[i];
        else {
            if (*max < aray[i])
                *max = aray[i];
            else if (*min > aray[i])
                *min = aray[i];
        }
    }
}


int main() {
    int size = 0;
    int max = 0, min = 0;

    welcome_print();

    // Entering number n
    printf("Please enter how numbers will be used: ");
    scanf("%d", &size);

    printf("\nNumber n=%d entered successfully.\n", size);
    printf("Now enter %d numbers.\n\n", size);

    int nums[size];

    // Nums entering
    fill_array(nums, size, &max, &min);

    printf("\n\nMin: %d    Max: %d", min, max);


    // Printing [MIN , MIN+(MAX-MIN)/3]
    //                       |
    //     ------------------
    //    |
    int nums12 = min + (max - min) / 3;

    printf("\n\n[MIN , MIN+(MAX-MIN)/3] [%d, %d]", min, min+(max-min)/3);
    printf("\n{ ");

    for (int i = 0; i < size; i++) {
        if ( (min <= nums[i]) && (nums[i] <= nums12) ) {
            printf("%d ", nums[i]);
        }
    }

    printf("}");


    // Printing [MIN+(MAX-MIN)/3 , MIN+(MAX-MIN)*2/3]
    //                 |                        |
    //     ------------                         |
    //    |                                     |
    int nums21 = min + (max - min) / 3; //      |
    int nums22 = min + (max - min) * 2 / 3; // -|

    printf("\n\n[MIN+(MAX-MIN)/3 , MIN+(MAX-MIN)*2/3] [%d, %d]", min+(max-min)/3, min+(max-min)*2/3);
    printf("\n{ ");

    for (int i = 0; i < size; i++) {
        if ( (nums21 <= nums[i]) && (nums[i] <= nums22) ) {
            printf("%d ", nums[i]);
        }
    }

    printf("}");


    // Printing [MIN+(MAX-MIN)*2/3 , MAX]
    //                 |
    //     ------------
    //    |
    int nums31 = min + (max - min) * 2 / 3;

    printf("\n\n[MIN+(MAX-MIN)*2/3 , MAX] = [%d, %d]", min+(max-min)*2/3, max);
    printf("\n{ ");

    for (int i = 0; i < size; i++) {
        if ( (nums31 <= nums[i]) && (nums[i] <= max) ) {
            printf("%d ", nums[i]);
        }
    }

    printf("}");

    return 0;
}