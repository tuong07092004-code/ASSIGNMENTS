#include <stdio.h>

int main() {
    int n;
    int a = 0;

    while ((n = getchar()) != EOF) {
        if (n == ' ') {
            if (a == 0) {
                putchar(n);
                a = 1;
            }
        } else {
            putchar(n);
            a = 0;
        }
    }
    return 0;
}
