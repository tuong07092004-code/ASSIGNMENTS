#include <stdio.h>

int main() {
    int n;
    int a = 0;

    while ((n = getchar()) != EOF) {
        if (n == ' ') {
           printf("\\b");
           continue;
        } else if(n == '\t'){
           printf("\\t");
           continue;
        }
        putchar(n);
    }
    return 0;
}
