#include <stdio.h>

void sumArrays(int *arr1, int *arr2, int *sum, int size) {
    for (int i = 0; i < size; i++) {
        *(sum + i) = *(arr1 + i) + *(arr2 + i);
    }
}

int main() {
    int n;
    printf("Enter size of arrays: ");
    scanf("%d", &n);

    int arr1[n], arr2[n], sum[n];

    printf("Enter elements for first array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr1 + i));
    }

    printf("Enter elements for second array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr2 + i));
    }

    sumArrays(arr1, arr2, sum, n);

    printf("Sum of arrays: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(sum + i));
    }

    return 0;
}
