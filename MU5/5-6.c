#include <stdio.h>

#define MAX_SIZE 1000

// check to avoid duplications
int check_answer(int *answer_array, int *temp_array, int nums, int size) {
    int result_sum = 0; // Unique sum ?
    for (int i = 0; i < nums; ++i) {
        if (i == 0) {
            result_sum += temp_array[i];
        } else {
            result_sum -= temp_array[i];
        }
    }

    // check is this sum exist in array
    for (int i = 0; i < size; ++i) {
        if (answer_array[i] == result_sum) {
            return 0;
        }
    }

    // adding result sum to array
    for (int i = 0; i < size; ++i) {
        if (answer_array[i] == NULL) {
            answer_array[i] = result_sum;
            return 1;
        }
    }
    printf("\nError in answer array.\n");
    return 1;
}


void find(int index, int sum, int nums, int size, int *array, int *temp_array, int answer, int *answer_array, int *found) {
    if ((sum == answer) && (nums > 1) && (check_answer(answer_array, temp_array, nums, size)) ) {
        *found = 1;
        printf("Sum can be: ");
        for (int i = 0; i < nums; ++i) {
            if (i == 0) {
                printf("%d", temp_array[i]);
            } else {
                if (temp_array[i] < 0) {
                    printf(" - %d", -temp_array[i]);
                } else {
                    printf(" + %d", temp_array[i]);
                }
            }
        }
        printf("\n");
    }

    if (index == size) {
        return;
    }

    temp_array[nums] = array[index];
    find(index + 1, sum + array[index], nums+1, size, array, temp_array, answer, answer_array, found);

    find(index + 1, sum, nums, size, array, temp_array, answer, answer_array, found);
}


int main() {
    long x;
    int size; // size of input array


    printf("Please enter number x, then array size(less that %d), then array values.\n", MAX_SIZE);
    printf("Program will check if from sum of some array values can get number x and print these numbers.\n");

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
            if (size > 0 && size < MAX_SIZE) {
                printf("Size entered successfully(%d).\n\n", size);
                break; 
            } else {
                printf("!!! Error, size must be positive and less than %d: ", MAX_SIZE);
            }
        }
        else {
            while (getchar() != '\n');
            printf("!!! Error, please enter whole number: ");
        }
    }

    int array[size];
    int temp_array[size];
    int answer_array[size];
    for (int i = 0; i < size; ++i) {
        answer_array[i] = 0;
    }

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
    } printf("\n");

    printf("Results(x=%ld):\n", x);
    int found = 0;

    // index, sum, how already used, array, temporary array for used nums, needed sum, array for storing unique results to avoid print duplication, if function found something.
    find(0, 0, 0, size, array, temp_array, x, answer_array, &found);

    if (!found) {
       printf("Program not found needed numbers in array to collect needed sum.\n");
    }

    return 0;
}