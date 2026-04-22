#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

void initHashTable(Node* buckets[]) {
    for (int i = 0; i < TABLE_SIZE; i++) buckets[i] = NULL;
}

unsigned int hash(char *str) {
    unsigned int hash_val = 0;
    while (*str) {
        hash_val = (hash_val * 31) + *str;
        str++;
    }
    return hash_val % TABLE_SIZE;
}

void insert(Node* buckets[], char *name, char *phone) {
    unsigned int index = hash(name);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = buckets[index];
    buckets[index] = newNode;
    printf("Da them: %s - %s (Bucket %d)\n", name, phone, index);
}

char* search(Node* buckets[], char *name) {
    unsigned int index = hash(name);
    Node* current = buckets[index];
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) return current->phone;
        current = current->next;
    }
    return NULL;
}

void deleteNode(Node* buckets[], char *name) {
    unsigned int index = hash(name);
    Node* current = buckets[index];
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) buckets[index] = current->next;
            else prev->next = current->next;
            free(current);
            printf("Da xoa lien he: %s\n", name);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Khong tim thay lien he %s de xoa.\n", name);
}

void printTable(Node* buckets[]) {
    printf("\n--- DANH BA DIEN THOAI ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* current = buckets[i];
        if (current == NULL) printf("Trong");
        while (current != NULL) {
            printf("[%s: %s] -> ", current->name, current->phone);
            current = current->next;
        }
        printf("\n");
    }
    printf("--------------------------\n\n");
}

void freeHashTable(Node* buckets[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}
