#include <stdio.h>
#include <math.h>

int main()
{
    // Declaration/initialization
    int counter = 1;
    int min = 0;
    int max = 0;
    int input = 0;

    // Infinity loop for ensuring correct setup 
    while (1) {

        // 1st input handling
        printf("Please enter 1 number: ");
        if ((scanf("%d", &input) == 1) && (getchar() == '\n'))
        {
            // Setup
            min = input;
            max = input;
            break;
        }
        else
        {
            // Error
            while (getchar() != '\n')
                ;
            printf("Error...");
        }
    }

    // Main loop
    while ((min * 2) != max)
    {
        // printf("\nDebug: min:%d max:%d\n", min, max);

        // Input handling
        printf("Please enter %d number: ", counter + 1);
        if ((scanf("%d", &input) == 1) && (getchar() == '\n'))
        {
            // If input < min, setting new min value
            if (min > input)
                min = input;

            // If input > max, setting new max value
            else if (max < input)
                max = input;
            counter++;

            // Endless loop detection
            if (input == 0 || max > min * 2) {
                printf("\n !!! Detected infinity loop.");
                break;
            }
        }
        else
        {
            // Error
            printf("Error...\n");
        }
    }

    // Result printing
    printf("\n\n\nMax: %d", max);
    printf("\nMin: %d", min);
    printf("\nNumbers: %d\n\n", counter);

    // Waiting for exit input
    getchar();
    return 0;
}