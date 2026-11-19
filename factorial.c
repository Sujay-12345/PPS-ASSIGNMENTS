#include <stdio.h>

int fact_loop(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int fact_rec(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fact_rec(n - 1);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial not defined for negative numbers.\n");
    } else {
        printf("Factorial without recursion: %d\n", fact_loop(n));
        printf("Factorial with recursion: %d\n", fact_rec(n));
    }

    return 0;
}
