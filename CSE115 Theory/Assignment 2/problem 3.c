#include <stdio.h>
#include <string.h>

int isAnagram(char str1[], char str2[]) {
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    int i = 0;
    while (str1[i] != '\0') {
        int freq1 = 0;
        int freq2 = 0;

        for (int j = 0; str1[j] != '\0'; j++) {
            if (str1[i] == str1[j]) {
                freq1++;
            }
        }
        for (int j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                freq2++;
            }
        }

        if (freq1 != freq2) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    if (isAnagram(str1, str2)) {
        printf("Strings are Anagram\n");
    } else {
        printf("Strings are not Anagram\n");
    }

    return 0;
}
