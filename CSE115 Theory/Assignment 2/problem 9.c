#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int marks;
};

int main() {
    struct Student students[100];
    int count = 0;
    FILE *file = fopen("students.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while (fscanf(file, "ID:%d, Name: %[^,], Marks: %d",
                  &students[count].id,
                  students[count].name,
                  &students[count].marks) == 3) {
        count++;
    }
    fclose(file);

    int searchID;
    printf("Enter ID to search: ");
    scanf("%d", &searchID);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id == searchID) {
            printf("Name: %s, Marks: %d\n", students[i].name, students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found\n");
    }

    return 0;
}
