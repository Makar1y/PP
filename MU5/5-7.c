#include <stdio.h>

#define MAX_SIZE 1000

// Check to avoid duplications.  // May be not print some results?
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


void find(int index, int sum, int nums, int size, int *array, int *temp_array, long answer, int *answer_array, int *found, int *temp_array_2) {
    if ((sum == answer) && (nums > 1) && (check_answer(answer_array, temp_array, nums, size)) ) {
        *found = 1;
        printf("Arrays can be: \n");
        printf("{");
        for (int i = 0; i < nums; ++i) {
            if (i == 0) {
                printf("%d", temp_array[i]);
            } else {
                printf(", %d", temp_array[i]);
            }
        } 
        printf("}\n");

        printf("{");
        int first = 0;
        for (int i = 0; i < size; ++i) {
            int ok = 1;
            for (int j = 0; j < nums; ++j) {
                if (temp_array_2[j] == i) {
                    ok = 0;
                }
            }

            if (ok){
                if (first == 0) {
                    printf("%d", array[i]);
                    first = 1;
                } else {
                    printf(", %d", array[i]);
                }
            }
        }
        printf("}\n\n");
    }

    if (index == size) {
        return;
    }

    temp_array[nums] = array[index];
    temp_array_2[nums] = index;
    find(index + 1, sum + array[index], nums+1, size, array, temp_array, answer, answer_array, found, temp_array_2);

    find(index + 1, sum, nums, size, array, temp_array, answer, answer_array, found, temp_array_2);
}


int main() {
    int size; // size of input array
    long sum = 0;
    int precision = 0;


    printf("Please enter array size(less that %d), then array values.\n", MAX_SIZE);
    printf("Program will check and print if array can split to two with elements sum +- equal.\n");


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
    int temp_array_2[size];
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
    } printf("\n\n");


    int found = 0;

    for(int i = 0; i < size; ++i) {
        sum += array[i];
    }

    if (sum / 10 == 0) {
        precision = (sum / 10) + 1;
    } else {
        precision = sum / 10;
    }

    // index, sum, how already used, array, temporary array for used nums, needed sum, array for storing unique results to avoid print duplication, if function found something.
    // second array for results and second nums counter.
    for (int i = 0; i <= precision; ++i) {
        find(0, 0, 0, size, array, temp_array, (sum / 2) + i, answer_array, &found, temp_array_2);
        if (found) {
            break;
        }
    }
    

    if (!found) {
       printf("Program not found how to split arrays:(\n");
    }

    return 0;
}