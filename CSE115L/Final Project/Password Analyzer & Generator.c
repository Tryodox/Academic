#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BREACHED 10000

char *breach_list[MAX_BREACHED];
int breach_list_size = 0;

void load_breach_list() {
    FILE *file = fopen("breached_passwords.txt", "r");
    if (!file) {
        printf("Warning: Could not open breached.txt\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) && breach_list_size < MAX_BREACHED) {
        line[strcspn(line, "\n")] = '\0';
        breach_list[breach_list_size] = strdup(line);
        breach_list_size++;
    }

    fclose(file);
}

int is_in_breach_list(char pass[]) {
    for (int i = 0; i < breach_list_size; i++) {
        if (strcmp(pass, breach_list[i]) == 0)
            return 1;
    }
    return 0;
}
void save_analysis_history(char *report) {
    FILE *file = fopen("analysis_history.txt", "a");
    if (file) {
        time_t now = time(NULL);
        fprintf(file, "\n[%s] %s\n", ctime(&now), report);
        fclose(file);
    }
}

void save_generation_history(char *password) {
    FILE *file = fopen("generation_history.txt", "a");
    if (file) {
        time_t now = time(NULL);
        fprintf(file, "[%s] Generated Password: %s\n", ctime(&now), password);
        fclose(file);
    }
}

void view_history(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("No history found.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF)
        putchar(ch);

    fclose(file);
}

void history_menu() {
    int opt;
    printf("_________Password Generation and Analysis History_________\n");
    printf("1. View Password Generation History\n");
    printf("2. View Password Analysis History\n");
    printf("3. Back to Main Menu\n");
    printf("__________________________________________________________\n");
    printf("Choose an option: ");
    scanf("%d", &opt);
    getchar();

    if (opt == 1) {
        view_history("generation_history.txt");
    } else if (opt == 2) {
        view_history("analysis_history.txt");
    } else {
        return;
    }
}

void pass_analyzer() {
    char pass[100], report[1000] = "";
    int len, has_upper = 0, has_lower = 0, has_digit = 0, has_symbol = 0;
    int i, pool = 0;

    getchar();
    printf("Enter your password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';

    len = strlen(pass);
    for (i = 0; i < len; i++) {
        if (isupper(pass[i])) has_upper = 1;
        else if (islower(pass[i])) has_lower = 1;
        else if (isdigit(pass[i])) has_digit = 1;
        else has_symbol = 1;
    }

    if (has_upper) pool += 26;
    if (has_lower) pool += 26;
    if (has_digit) pool += 10;
    if (has_symbol) pool += 32;

    double entropy = len * log2(pool);
    double crack_seconds = pow(2, entropy) / 1e9;

    sprintf(report + strlen(report), "Length: %d\nIncludes: ", len);
    if (has_upper) strcat(report, "Uppercase ");
    if (has_lower) strcat(report, "Lowercase ");
    if (has_digit) strcat(report, "Digit ");
    if (has_symbol) strcat(report, "Symbol ");
    strcat(report, "\n");

    char crack_info[100];
    if (crack_seconds < 60)
        sprintf(crack_info, "%.2f seconds", crack_seconds);
    else if (crack_seconds < 3600)
        sprintf(crack_info, "%.2f minutes", crack_seconds / 60);
    else if (crack_seconds < 86400)
        sprintf(crack_info, "%.2f hours", crack_seconds / 3600);
    else if (crack_seconds < 31536000)
        sprintf(crack_info, "%.2f days", crack_seconds / 86400);
    else
        sprintf(crack_info, "%.2f years", crack_seconds / 31536000);

    sprintf(report + strlen(report), "Estimated Entropy: %.2f bits\n", entropy);
    sprintf(report + strlen(report), "Estimated crack time: %s\n", crack_info);

    strcat(report, "Password Strength: ");
    if (entropy < 30) strcat(report, "\x1b[31mWeak\x1b[0m\n");
    else if (entropy < 60) strcat(report, "\x1b[33mModerate\x1b[0m\n");
    else strcat(report, "\x1b[32mStrong\x1b[0m\n");

    if (is_in_breach_list(pass))
        strcat(report, "This password appears in a known data breach!\n");
    else
        strcat(report, "Doesn't match any breach data.\n");

    printf("\n_________________Analysis Report_________________\n");
    printf("%s", report);
    printf("__________________________________________________\n");

    save_analysis_history(report);
}

void pass_generator() {
    int length;
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    char password[100];

    srand(time(NULL));
    printf("Enter desired password length: ");
    scanf("%d", &length);

    if (length > 99 || length <= 0) {
        printf("Invalid length!\n");
        return;
    }

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[length] = '\0';

    printf("Generated Password: %s\n", password);
    printf("__________________________________________________\n");

    save_generation_history(password);
}

void menu() {
    int choice;
    while (1) {
        printf("________________Password Analyzer and Generator________________\n");
        printf("1. Analyze Your Password\n");
        printf("2. Generate Strong Password\n");
        printf("3. Password Generation and Analysis History\n");
        printf("4. Exit\n");
        printf("_______________________________________________________________\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pass_analyzer();
                break;
            case 2:
                pass_generator();
                break;
            case 3:
                history_menu();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return;
            default:
                printf("Invalid Option. Try again.\n");
        }
    }
}

int main() {
    load_breach_list();
    menu();
    return 0;
}
