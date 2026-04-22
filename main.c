#include <stdio.h>
#include "hashtable.h"

int main() {
    Node* hashtable[TABLE_SIZE];
    initHashTable(hashtable);

    printf("=== 1. TEST THEM LIEN HE ===\n");
    insert(hashtable, "Alice", "0123456789");
    insert(hashtable, "Bob", "0987654321");
    insert(hashtable, "Charlie", "0111222333");
    insert(hashtable, "David", "0222333444");
    insert(hashtable, "Eve", "0333444555");
    insert(hashtable, "Frank", "0444555666");
    insert(hashtable, "Grace", "0555666777");
    insert(hashtable, "Heidi", "0666777888");

    printTable(hashtable);

    printf("=== 2. TEST TIM KIEM ===\n");
    char* searchNames[] = {"Alice", "Eve", "Zack_Not_Exist"};
    for(int i = 0; i < 3; i++) {
        char* phone = search(hashtable, searchNames[i]);
        if (phone) {
            printf("Tim thay [%s]: So DT la %s\n", searchNames[i], phone);
        } else {
            printf("Loi: Khong tim thay lien he ten [%s]\n", searchNames[i]);
        }
    }

    printf("\n=== 3. TEST XOA LIEN HE ===\n");
    deleteNode(hashtable, "Bob");
    deleteNode(hashtable, "Grace");
    
    printTable(hashtable);

    freeHashTable(hashtable);
    return 0;
}
