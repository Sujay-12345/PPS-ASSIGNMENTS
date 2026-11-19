#include <stdio.h>
#include <string.h>

int main() {
    int choice, result;
    char str1[100], str2[100], temp[100];

    do {
        printf("\n--- String Operations ---\n");
        printf("1. String Length (strlen)\n");
        printf("2. String Copy (strcpy)\n");
        printf("3. String Concatenation (strcat)\n");
        printf("4. String Comparison (strcmp)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf("%s", str1);
                printf("Length: %lu\n", strlen(str1));
                break;

            case 2:
                printf("Enter source string: ");
                scanf("%s", str1);
                strcpy(temp, str1);
                printf("Copied string: %s\n", temp);
                break;

            case 3:
                printf("Enter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 4:
                printf("Enter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);
                result = strcmp(str1, str2);
                if (result == 0) {
                    printf("Strings are equal\n");
                } else if (result > 0) {
                    printf("First string is greater\n");
                } else {
                    printf("Second string is greater\n");
                }
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}