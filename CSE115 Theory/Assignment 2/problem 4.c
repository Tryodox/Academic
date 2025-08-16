#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char strs[100][100];

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", strs[i]);
    }

    char prefix[100];
    int i = 0;

    while (1) {
        char currentChar = strs[0][i];

        // Check if current character is the same in all strings
        for (int j = 1; j < n; j++) {
            if (strs[j][i] != currentChar || strs[j][i] == '\0') {
                prefix[i] = '\0'; // End of prefix
                printf("Longest Common Prefix: %s\n", prefix);
                return 0;
            }
        }

        // If matched, store it in prefix
        prefix[i] = currentChar;
        i++;
    }

    return 0;
}
