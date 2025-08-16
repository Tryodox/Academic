#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    float CGPA;
};

int main() {
    struct Student s1, s2;

    printf("Enter name, ID, and CGPA for student 1: ");
    scanf("%s %d %f", s1.name, &s1.id, &s1.CGPA);

    printf("Enter name, ID, and CGPA for student 2: ");
    scanf("%s %d %f", s2.name, &s2.id, &s2.CGPA);

    if (s1.CGPA > s2.CGPA) {
        printf("Student with higher CGPA:\nName: %s\nID: %d\n", s1.name, s1.id);
    } else if (s2.CGPA > s1.CGPA) {
        printf("Student with higher CGPA:\nName: %s\nID: %d\n", s2.name, s2.id);
    } else {
        printf("Both students have the same CGPA.\n");
    }

    return 0;
}
