#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int leap;
    char *p;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    p = daytab[leap];
    if (month < 1 || month > 12 || day < 1 || day > *(p + month)) {
        printf("error: invalid date %d/%d/%d\n", month, day, year);
        return -1;
    }

    while (--month > 0)
        day += *(++p);

    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap;
    char *p;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (yearday < 1 || yearday > (leap ? 366 : 365)) {
        printf("error: invalid yearday %d for year %d\n", yearday, year);
        *pmonth = 0;
        *pday = 0;
        return -1;
    }

    p = daytab[leap];
    int i = 1;
    while (yearday > *(p++)) {
        yearday -= *p;
        i++;
    }

    *pmonth = i;
    *pday = yearday;
    return 0;
}

int main(void) {
    int month, day;

    /* valid leap year test */
    month_day(2024, 60, &month, &day);
    printf("2024 day 60 -> %d/%d\n", month, day);

    /* valid non-leap year test */
    month_day(2023, 60, &month, &day);
    printf("2023 day 60 -> %d/%d\n", month, day);

    /* invalid yearday test */
    month_day(2023, 400, &month, &day);
    printf("2023 day 400 -> %d/%d\n", month, day);

    /* test day_of_year */
    printf("March 1, 2023 -> day %d\n", day_of_year(2023, 3, 1));
    printf("Feb 29, 2024 -> day %d\n", day_of_year(2024, 2, 29));
    printf("Feb 29, 2023 -> day %d\n", day_of_year(2023, 2, 29));

    return 0;
}
