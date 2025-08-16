#include <stdio.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int countDays(int day, int month, int year) {
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = day;
    for (int i = 0; i < month - 1; i++) {
        days += monthDays[i];
    }
    if (month > 2 && isLeapYear(year)) {
        days++;
    }
    for (int i = 1; i < year; i++) {
        days += isLeapYear(i) ? 366 : 365;
    }
    return days;
}
int main() {
    int d1, m1, y1;
    int d2, m2, y2;

    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d", &d1, &m1, &y1);

    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d", &d2, &m2, &y2);

    int days1 = countDays(d1, m1, y1);
    int days2 = countDays(d2, m2, y2);

    int diff = days1 - days2;
    if (diff < 0) diff = -diff;

    printf("Difference in days: %d\n", diff);

    return 0;
}
