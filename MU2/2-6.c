#include <stdio.h>


int Max(int x, int y, int z) {
    int max1 = (x >= y) ? x : y;
    int max = (max1 >= z) ? max1 : z;
    return max;
}

void test() {
    int test_array[16][4] = {
        //{test value 1, test value 2, test value 3, result}

        // tests
        {10, 32, 33, 33}, // {1, 2, 3}
        {5, 25, 12, 25}, // {1, 3, 2}

        {300, 115, 355, 355},  // {2, 1, 3}
        {24, 63, 15, 63},  // {2, 3, 1}

        {23, 22, 12, 23},  // {3, 2, 1}
        {366, 155, 236, 366},  // {3, 1, 2}

        {50, 50, 50, 50},  // {1, 1, 1}

        {1, 1, 2, 2},  // {1, 1, 2}
        {1, 2, 1, 2},  // {1, 2, 1}
        {2, 1, 1, 2},  // {2, 1, 1}

        {2, 2, 1, 2},  // {2, 2, 1}
        {2, 1, 2, 2},  // {2, 1, 2}
        {1, 2, 2, 2},  // {1, 2, 2}


        //random tests
        {57, 322, 113, 322},
        {26, 51, 21, 51},
        {11, 25, 32, 32},

        };

        int result;
        int x, y, z;

        for (int i = 0; i<16; i++) {
            x = test_array[i][0];
            y = test_array[i][1];
            z = test_array[i][2];
            result = Max(x, y, z);

            if (result == test_array[i][3])
                printf("  Test Nr. %d  Passed\n", i+1);
            else
                printf("  Test Nr. %d  NPassed, test Max: %d, real max: %d\n", i+1, result, test_array[i][3]);
        };
}

void error() {
    printf("    Invalid input, try again...\n");
            while(getchar() != '\n');
}

int main() {

    printf("Running tests:\n");
    test();
    printf("\n\n");

    int x = 1;
    int y = 1;
    int z = 1;
    int max;

    while (1) {
        if (!x && !y && !z) break;

        printf("Enter 3 number please(x y z (all zeros to exit)): ");
        ((scanf("%d %d %d", &x, &y, &z) == 3) && (getchar() == '\n')) ?
            printf("Max: %d\n\n", max = Max(x, y, z))
        :
            error();
        
    }

    return 0;
}