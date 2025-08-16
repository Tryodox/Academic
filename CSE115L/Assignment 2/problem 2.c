#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[50];
    struct Date dob;
    struct Date startDate;
    float salary;
};

int main() {
    struct Employee employees[4];
    int i;

    for (i = 0; i < 4; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);

        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';

        printf("Date of Birth (dd mm yyyy): ");
        scanf("%d %d %d", &employees[i].dob.day, &employees[i].dob.month, &employees[i].dob.year);

        printf("Starting Date (dd mm yyyy): ");
        scanf("%d %d %d", &employees[i].startDate.day, &employees[i].startDate.month, &employees[i].startDate.year);

        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    int highestSalaryIndex = 0;
    for (i = 1; i < 4; i++) {
        if (employees[i].salary > employees[highestSalaryIndex].salary) {
            highestSalaryIndex = i;
        }
    }

    int recentJoinIndex = 0;
    for (i = 1; i < 4; i++) {
        struct Date d1 = employees[i].startDate;
        struct Date d2 = employees[recentJoinIndex].startDate;

        if (d1.year > d2.year ||
           (d1.year == d2.year && d1.month > d2.month) ||
           (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day)) {
            recentJoinIndex = i;
        }
    }

    printf("\nEmployee with Highest Salary:\n");
    printf("Name: %s\n", employees[highestSalaryIndex].name);
    printf("DOB: %02d-%02d-%d\n", employees[highestSalaryIndex].dob.day, employees[highestSalaryIndex].dob.month, employees[highestSalaryIndex].dob.year);
    printf("Starting Date: %02d-%02d-%d\n", employees[highestSalaryIndex].startDate.day, employees[highestSalaryIndex].startDate.month, employees[highestSalaryIndex].startDate.year);
    printf("Salary: %.2f\n", employees[highestSalaryIndex].salary);

    printf("\nMost Recently Joined Employee:\n");
    printf("Name: %s\n", employees[recentJoinIndex].name);
    printf("DOB: %02d-%02d-%d\n", employees[recentJoinIndex].dob.day, employees[recentJoinIndex].dob.month, employees[recentJoinIndex].dob.year);
    printf("Starting Date: %02d-%02d-%d\n", employees[recentJoinIndex].startDate.day, employees[recentJoinIndex].startDate.month, employees[recentJoinIndex].startDate.year);
    printf("Salary: %.2f\n", employees[recentJoinIndex].salary);

    return 0;
}
