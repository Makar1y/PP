#include <stdio.h>

void clear()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int to_binary(int hexadecimal)
{
    int input = 1;
    int input_w;
    long long result = 0;
    long long counter = 1;

    if (hexadecimal)
        printf("Hexadecimal to binary.\n\n");
    else
        printf("Decimal to binary.\n\n");

    while (input)
    {
        printf("Please enter number to convert to binary(0 exit to menu): ");
        if (hexadecimal)
        {
            if ((scanf("%x", &input) == 1) && (getchar() == '\n'))
                ;
            else
            {
                printf("error: Please enter one hexadecimal number!\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
        }
        else
        {
            if ((scanf("%d", &input) == 1) && (getchar() == '\n'))
                ;
            else
            {
                printf("error: Please enter one decimal number!\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
        }

        if (input == 0)
        {
            printf("This number in binary is 0\n\n");
            return 0;
        }

        result = 0;
        counter = 1;
        input_w = input;
        while (input_w)
        {
            result += counter * (input_w % 2);
            input_w /= 2;
            counter *= 10;
        }

        printf("This number in binary is %lld\n\n", result);
    }
}

int binary_to(int hexadecimal)
{
    long long binary = 1;
    long long binary_w;

    if (hexadecimal)
        printf("Binary to hexadecimal.\n\n");
    else
        printf("Binary to decimal.\n\n");

    while (binary)
    {
        printf("Please enter binary number(0 exit to menu): ");

        if ((scanf("%lld", &binary) == 1) && (getchar() == '\n'))
        {
            for (long long i = binary; i != 0; i /= 10)
            {
                if ((i % 10 != 1) && (i % 10 != 0))
                {
                    printf("error: It looks like it not binary number or it too long, please enter binary number!\n");
                    binary = 1;
                    break;
                }
            }
        }
        else
        {
            printf("error: Please enter one binary number!\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        int result = 0;
        int counter = 1;
        if (binary == 0)
        {
            printf("This binary number in %s is 0", (hexadecimal) ? "hexadecimal" : "decimal");
            return 0;
        }

        binary_w = binary;
        while (binary_w)
        {
            int last_digit = binary_w % 10;
            binary_w /= 10;
            result += last_digit * counter;
            counter *= 2;
        }

        if (hexadecimal)
            printf("This binary number in hexadecimal is %x\n\n", result);
        else
            printf("This binary number in decimal is %d\n\n", result);
    }
}

void hexadecimal_to_decimal()
{
    printf("Hexadecimal to decimal.\n\n");
    int hexadecimal = 0x1;
    while (hexadecimal)
    {
        printf("Please enter hexadecimal number(0 exit to menu): ");
        if ((scanf("%x", &hexadecimal) == 1) && (getchar() == '\n'))
            ;
        else
        {
            printf("error: Please enter one hexadecimal number!\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        printf("This hexadecimal number in decimal is %d\n\n", hexadecimal);
    }
}

void decimal_to_hexadecimal()
{
    printf("Decimal to hexadecimal.\n\n");
    int decimal = 1;
    while (decimal)
    {
        printf("Please enter decimal number(0 - exit menu): ");
        if ((scanf("%d", &decimal) == 1) && (getchar() == '\n'))
            ;
        else
        {
            printf("error: Please enter one decimal number!\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        printf("This decimal number in hexadecimal is %x\n\n", decimal);
    }
}

int main()
{
    int menu_num = 1;

    // Menu
    clear();
    while (menu_num)
    {
        printf("Menu:\n");
        printf("    1 - Decimal to binary\n");
        printf("    2 - Binary to decimal\n");
        printf("    3 - Hexadecimal to decimal\n");
        printf("    4 - Decimal to hexadecimal\n");
        printf("    5 - Hexadecimal to binary\n");
        printf("    6 - Binary to hexadecimal\n");
        printf("    0 - Exit\n\n");
        printf(": ");

        if ((scanf("%d", &menu_num) == 1) && (getchar() == '\n'))
        {

            if (menu_num >= 0 && menu_num <= 6)
            {
                clear();
                if (menu_num == 0)
                    return 0;

                else if (menu_num == 1)
                    to_binary(0);
                else if (menu_num == 2)
                    binary_to(0);
                else if (menu_num == 3)
                    hexadecimal_to_decimal();
                else if (menu_num == 4)
                    decimal_to_hexadecimal();
                else if (menu_num == 5)
                    to_binary(1);
                else if (menu_num == 6)
                    binary_to(1);
            }
            else
            {
                clear();
                printf("error: Please enter menu number!\n\n");
            }
        }
        else
        {
            clear();
            printf("error: Please enter one number!\n\n");
            while (getchar() != '\n');
        }
    }

    return 0;
}

// void input validation