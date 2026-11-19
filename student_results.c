#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int n, i;
    struct Student s[100];

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll number: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\n--- Student Results ---\n");
    for (i = 0; i < n; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f | Result: %s\n",
               s[i].roll, s[i].name, s[i].marks,
               (s[i].marks >= 40) ? "Pass" : "Fail");
    }

    return 0;
}
