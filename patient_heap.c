#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100

// Cấu trúc bệnh nhân
typedef struct {
    char name[50];
    int priority;
    int order; // Dùng để xử lý FCFS (Ai đến trước khám trước nếu cùng ưu tiên)
} Patient;

Patient heap[MAX_PATIENTS];
int size = 0;
int arrival_count = 0; // Biến đếm thứ tự đến bệnh viện

// Hàm hoán đổi 2 phần tử
void swap(Patient *a, Patient *b) {
    Patient temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm so sánh: Trả về 1 nếu p1 ưu tiên CẦN ĐƯỢC KHÁM TRƯỚC p2
int isHigherPriority(Patient p1, Patient p2) {
    // Mức ưu tiên cao hơn -> khám trước
    if (p1.priority > p2.priority) return 1;
    // Nếu cùng mức ưu tiên -> Ai có số order nhỏ hơn (đến trước) thì khám trước
    if (p1.priority == p2.priority && p1.order < p2.order) return 1;
    return 0;
}

// Đưa phần tử lên vị trí đúng (khi chèn)
void heapify_up(int index) {
    if (index == 0) return; // Đã ở gốc
    int parent = (index - 1) / 2;
    
    // Nếu nút hiện tại ưu tiên cao hơn nút cha -> hoán đổi
    if (isHigherPriority(heap[index], heap[parent])) {
        swap(&heap[index], &heap[parent]);
        heapify_up(parent);
    }
}

// Đưa phần tử xuống vị trí đúng (khi xóa gốc)
void heapify_down(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && isHigherPriority(heap[left], heap[largest]))
        largest = left;
    
    if (right < size && isHigherPriority(heap[right], heap[largest]))
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapify_down(largest);
    }
}

// 1. Thêm bệnh nhân vào hàng đợi (push)
void push(char* name, int priority) {
    if (size >= MAX_PATIENTS) {
        printf("Hang doi da day!\n");
        return;
    }
    strcpy(heap[size].name, name);
    heap[size].priority = priority;
    heap[size].order = ++arrival_count; // Gắn số thứ tự lúc đến
    
    heapify_up(size);
    size++;
}

// 3. Xem bệnh nhân ưu tiên cao nhất (peek)
Patient peek() {
    return heap[0];
}

// 2. Lấy bệnh nhân ưu tiên cao nhất ra khỏi hàng đợi (pop)
Patient pop() {
    Patient root = heap[0];
    heap[0] = heap[size - 1]; // Đưa phần tử cuối lên làm gốc
    size--;
    heapify_down(0); // Vun đống lại từ gốc
    return root;
}

// Mở rộng: In toàn bộ trạng thái mảng Heap
void printHeap() {
    printf("   [Trang thai Heap]: ");
    for(int i = 0; i < size; i++) {
        printf("(%s - P:%d) ", heap[i].name, heap[i].priority);
    }
    printf("\n");
}

int main() {
    printf("=== BO PHAN TIEP NHAN BENH NHAN ===\n\n");

    // Khai báo mảng data test (Cố tình cho E và F cùng mức ưu tiên 3)
    // E đến trước, F đến sau -> Lát nữa E phải được gọi ra trước F
    char* names[] = {"Nguyen Van A (Cam cum)", "Tran Thi B (Gay xuong)", "Le Van C (Dot quy)", "Pham Thi D (Dau rang)", "Hoang Van E (Dau ruot thua)"};
    int priorities[] = {1, 3, 5, 1, 3}; 

    // Nhập vào 5 bệnh nhân và in ra đầu hàng đợi sau mỗi lần thêm
    for(int i = 0; i < 5; i++) {
        printf("-> Them: %s (Muc uu tien: %d)\n", names[i], priorities[i]);
        push(names[i], priorities[i]);
        
        Patient top = peek();
        printf("   [!] Đau hang doi hien tai: %s (P:%d)\n", top.name, top.priority);
        printHeap(); // Gọi hàm mở rộng
        printf("\n");
    }

    printf("=== TIEN HANH GOI KHAM ===\n\n");
    int count = 1;
    while (size > 0) {
        Patient p = pop();
        printf("Luot %d: Moi benh nhan [%s] vao phong kham (Muc uu tien: %d, Thu tu den: %d)\n", 
               count++, p.name, p.priority, p.order);
    }

    return 0;
}
