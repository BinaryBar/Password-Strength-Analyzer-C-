#include <stdio.h>
#include <string.h>
#include <ctype.h>

int hasUpper(const char *password) {
    for (int i = 0; password[i]; i++)
        if (isupper(password[i])) return 1;
    return 0;
}

int hasLower(const char *password) {
    for (int i = 0; password[i]; i++)
        if (islower(password[i])) return 1;
    return 0;
}

int hasDigit(const char *password) {
    for (int i = 0; password[i]; i++)
        if (isdigit(password[i])) return 1;
    return 0;
}

int hasSymbol(const char *password) {
    for (int i = 0; password[i]; i++)
        if (ispunct(password[i])) return 1;
    return 0;
}

void analyzePassword(const char *password) {
    int length = strlen(password);
    int score = 0;

    if (length >= 8) score++;
    if (hasUpper(password)) score++;
    if (hasLower(password)) score++;
    if (hasDigit(password)) score++;
    if (hasSymbol(password)) score++;

    printf("\nPassword Analysis:\n");

    switch (score) {
        case 5:
        case 4:
            printf("Strength: 🔒 Strong\n");
            break;
        case 3:
            printf("Strength: 🔐 Moderate\n");
            break;
        default:
            printf("Strength: ❗ Weak\n");
    }

    printf("Tips:\n");
    if (length < 8) printf("- Use at least 8 characters\n");
    if (!hasUpper(password)) printf("- Add uppercase letters\n");
    if (!hasLower(password)) printf("- Add lowercase letters\n");
    if (!hasDigit(password)) printf("- Add numbers\n");
    if (!hasSymbol(password)) printf("- Add special symbols (!, @, #, etc.)\n");
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    analyzePassword(password);

    return 0;
}
