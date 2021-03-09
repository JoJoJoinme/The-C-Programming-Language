#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year
    argument: year, month, day
    return: day of year
*/
int day_of_year(int year, int month, int day)
{
    int leap, yearday = 0;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month > 12 || month < 1 || day > daytab[leap][month] || day < 1)
        return -1;
    while (month--)
        yearday += daytab[leap][month];
    return yearday + day;
}

/* month_day 
    argument: year, yearday
    return: month and day
*/
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap, i;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;   
    if ((!leap && yearday > 365) || (leap && yearday > 366) || yearday < 1)
        return -1;
    for(i = 0; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main(void)
{
    int year, month, day, yearday;
    printf("Please input year:\n");
    scanf("%d", &year);
    printf("Please input month:\n");
    scanf("%d", &month);
    printf("Please input day:\n");
    scanf("%d", &day);
    yearday = day_of_year(year, month, day);
    printf("year:%d, month:%d, day:%d -> %d-th day of year\n", year, month, day, yearday);
    printf("Please input yearday:\n");
    scanf("%d", &yearday);
    month_day(year, yearday, &month, &day);
    printf("year:%d, %d-th day of year -> month:%d, day:%d\n", year, yearday, month, day);

}