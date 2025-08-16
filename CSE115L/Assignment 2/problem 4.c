#include <stdio.h>

int main() {
    int size, num;
    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to search: ");
    scanf("%d", &num);

    int *ptr = arr;
    int found = 0;

    printf("\nOccurrences of %d:\n", num);
    for (int i = 0; i < size; i++) {
        if (*(ptr + i) == num) {
            printf("Index: %d, Address: %p\n", i, (ptr + i));
            found = 1;
        }
    }

    if (!found) {
        printf("Number not found in array.\n");
    }

    return 0;
}
