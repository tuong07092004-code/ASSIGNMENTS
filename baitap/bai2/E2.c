#include <stdio.h>
#include <ctype.h>
#include <string.h>

int same_type(char a, char b) {
    return (islower(a) && islower(b)) ||
           (isupper(a) && isupper(b)) ||
           (isdigit(a) && isdigit(b));
}

void expand(char s1[], char s2[]) {
    int i = 0, k = 0;

    while (s1[i] != '\0') {
        if (s1[i] == '-' && i > 0 && s1[i+1] != '\0') {
            char start = s1[i-1];
            char end = s1[i+1];

            if (same_type(start, end) && start < end) {
                for (char c = start + 1; c < end; c++) {
                    s2[k++] = c;
                }
                i++; // bỏ qua end, sẽ xử lý tiếp
            } else {
                s2[k++] = '-';
            }
        } else {
            s2[k++] = s1[i];
        }
        i++;
    }

    s2[k] = '\0';
}

int main() {
    char s1[1000];
    char s2[2000];

    printf("Nhap chuoi s1: ");
    fgets(s1, sizeof(s1), stdin);

    // Xóa newline '\n' nếu có
    s1[strcspn(s1, "\n")] = '\0';

    expand(s1, s2);

    printf("Ket qua: %s\n", s2);

    return 0;
}
