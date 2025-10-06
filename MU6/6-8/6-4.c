#include <stdio.h>
#include <string.h>
#include "custom_module.c"

#define BUFFER 100


int main() {
    int day, year, month;
    int day_of_week;
    char weekday_str[BUFFER];
    int file_correct = 0;

    printf("Please enter date in format \"YYYY-MM-DD\"\n");
    printf("And program will print day of week(Ensure that week.txt contain 7 lines with names of the days).\n\n");
    printf("Please enter date: ");

    while (! scan_date_yyyy_mm_dd(&year, &month, &day)) {
        printf("Try again: ");
    }

    printf("Data %4.4d-%2.2d-%2.2d entered successfully.\n\n", year, month, day);

    day_of_week = get_day_of_week_from_date(year, month, day);
    if (! day_of_week) {
        printf("!!! Error calculating day of week.");
        return 1;
    }


    // Localization?
    FILE *weekdays = fopen("week.txt", "r");

    if (weekdays != NULL) {
        for (int i = 1; fgets(weekday_str, sizeof weekday_str, weekdays); ++i) {
            if (i == day_of_week) {
                printf("Day of week: %s", weekday_str);
                file_correct = 1;
                break;
            }
        }

        if (!file_correct) {
            printf("!!! Error parsing week.txt file.\n");
            printf("!!! Printing number value.\n");
            printf("!!! Day of week: %d\n", day_of_week);
        }

        fclose(weekdays);
    } else {
        perror("!!! Error, week.txt");
        printf("!!! Printing number value.\n");
        printf("!!! Day of week: %d\n", day_of_week);
        return 1;
    }

    return 0;
}