#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(int n, char s[], int b) {
    int i, sign;
    unsigned int n_abs;
    sign = n;
    if (n < 0) {
        n_abs = -n;
    } else {
        n_abs = n;
    }

    i = 0;
    do {
        int digit = n_abs % b;
        if (digit < 10) {
            s[i++] = digit + '0';
        } else {
            s[i++] = (digit - 10) + 'a';
        }
    } while ((n_abs /= b) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    int n = 255;
    char s[100];
    itob(n, s, 16);
    printf("So %d he co so 16: %s\n", n, s);
    itob(n, s, 2);
    printf("So %d he co so 2: %s\n", n, s);
    itob(-1234, s, 10);
    printf("So %d he co so 10: %s\n", -1234, s);
    return 0;
}
