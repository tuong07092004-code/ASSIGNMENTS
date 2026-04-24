#include <stdio.h>

int main() {
    int n;
    int a[256] = {0};

    while ((n = getchar()) != EOF) {
        a[n]++;
    }

    for (int i = 0; i < 256; i++) {
        if (a[i] > 0) {
            if (i == '\n')
                printf("\\n: ");
            else if (i == '\t')
                printf("\\t: ");
            else if (i == ' ')
                printf("' ': ");
            else
                printf("%c: ", i);

            for (int j = 0; j < a[i]; j++) {
                putchar('*');
            }
            putchar('\n');
        }
    }

    return 0;
}
