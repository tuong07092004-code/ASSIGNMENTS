#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Khởi tạo stack
void init(Stack *s) {
    s->top = -1;
}

// Kiểm tra stack trống
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Thêm phần tử
void push(Stack *s, int val) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = val;
    } else {
        printf("Stack day!\n");
    }
}

// Lấy phần tử
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1;
}

// In phần tử đỉnh
void printTop(Stack *s) {
    if (!isEmpty(s)) {
        printf("Phan tu dinh: %d\n", s->data[s->top]);
    } else {
        printf("Stack trong!\n");
    }
}

// Nhân bản
void duplicate(Stack *s) {
    if (!isEmpty(s)) {
        if (s->top < MAX_SIZE - 1) {
            int topVal = s->data[s->top];
            push(s, topVal);
            printf("Da nhan ban phan tu %d\n", topVal);
        } else {
            printf("Stack day, khong the nhan ban!\n");
        }
    }
}
// hoán đổi
void swap(Stack *s) {
    if (s->top >= 1) {
        int temp = s->data[s->top];
        s->data[s->top] = s->data[s->top - 1];
        s->data[s->top - 1] = temp;
        printf("Da hoan doi hai phan tu tren cung.\n");
    } else {
        printf("Khong du phan tu de hoan doi!\n");
    }
}

// xóa stack
void clear(Stack *s) {
    s->top = -1;
    printf("Da xoa sach Stack.\n");
}

int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printTop(&s);
    duplicate(&s);
    printTop(&s);
    swap(&s);
    push(&s, 40);
    swap(&s);
    printTop(&s);
    clear(&s);
    if (isEmpty(&s)) printf("Bay gio Stack dang trong.\n");

    return 0;
}
