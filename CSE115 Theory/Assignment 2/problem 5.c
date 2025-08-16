#include <stdio.h>

struct Employee {
    char name[50];
    int age;
    float salary;
};

int main() {
    struct Employee employees[100];
    int count = 0;

    FILE *file = fopen("employees.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fscanf(file, "%s %d %f", employees[count].name, &employees[count].age, &employees[count].salary) == 3) {
        count++;
    }

    fclose(file);

    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    return 0;
}
