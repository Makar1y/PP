#include <stdio.h>
#include <string.h>

#define BUFFER 100


int valid_date(int year, int month, int day) {
    if (year < 1 || (month < 1 || month > 12) || day < 1) {
        return 0;
    }

    int leap = ( (((year % 4) == 0) && ((year % 100) != 0))   ||   ((year % 400) == 0) ) ? 1 : 0;
    int month_days;

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            month_days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            month_days = 30;
            break;
        case 2:
            month_days = (leap) ? 29 : 28;
            break;
        default:
            return 0;
    }

    return day <= month_days;
}


int main() {
    int day, year, month;
    char day_s[10], year_s[10], month_s[10];
    int day_of_week;
    char weekday_str[BUFFER];
    int file_correct = 0;

    // https://en.wikipedia.org/wiki/Zeller%27s_congruence
    int q, k, j, m;

    printf("Please enter date in format \"YYYY-MM-DD\"\n");
    printf("And program will print day of week(Ensure that week.txt contain 7 lines with names of the days).\n\n");
    printf("Please enter date: ");

    while (2) {
        if (scanf("%4[0-9]-%2[0-9]-%2[0-9]", year_s, month_s, day_s) == 3 && getchar() == '\n') {
            if ( (strlen(year_s) == 4) && (strlen(month_s) == 2) && (strlen(day_s) == 2) ) {
                sscanf(year_s, "%d", &year);
                sscanf(month_s, "%d", &month);
                sscanf(day_s, "%d", &day);

                if (valid_date(year, month, day)) {
                    break;
                } else {
                    printf("!!! Error, enter valid date: ");
                }
            } else {
                printf("!!! Error, enter valid date: ");
            }
        } else {
            while(getchar() != '\n');
            printf("!!! Error, enter date in specified format: ");
        }
    }
    printf("Data %4.4d-%2.2d-%2.2d entered successfully.\n\n", year, month, day);
    



    // Zeller's congruence   https://en.wikipedia.org/wiki/Zeller%27s_congruence
    q = day;
    if (month == 1 || month == 2) {
        m = month + 12;
        --year;
    } else {
        m = month;
    }
    k = year % 100;
    j = year / 100;

    day_of_week = (q + ((13 * (m + 1)) / 5 ) + k + (k / 4) + (j / 4) - 2 * j) % 7;
    day_of_week = ((day_of_week + 5) % 7) + 1; 




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
        perror("!!! Error -> week.txt");
        printf("!!! Printing number value.\n");
        printf("!!! Day of week: %d\n", day_of_week);
        return 1;
    }

    return 0;
}