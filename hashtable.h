#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 10

typedef struct Node {
    char name[50];
    char phone[20];
    struct Node* next;
} Node;

void initHashTable(Node* buckets[]);
unsigned int hash(char *str);
void insert(Node* buckets[], char *name, char *phone);
char* search(Node* buckets[], char *name);
void deleteNode(Node* buckets[], char *name);
void printTable(Node* buckets[]); 
void freeHashTable(Node* buckets[]);

#endif
