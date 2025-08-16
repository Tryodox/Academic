#include <stdio.h>

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nElement occurrences:\n");
    for (int i = 0; i < n; i++) {
        int count = 1;
        int visited = 0;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                visited = 1;
                break;
            }
        }

        if (visited == 0) { 
            for (int k = i + 1; k < n; k++) {
                if (arr[i] == arr[k]) {
                    count++;
                }
            }
            printf("%d : %d\n", arr[i], count);
        }
    }

    return 0;
}
