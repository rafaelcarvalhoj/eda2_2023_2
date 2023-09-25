#ifndef
#define HASH_H
typedef int Item;

typedef struct node{
    Item data;
    struct node *next;
}node;

typedef struct{
    node *HT;
    int M;
}HashTable;

void create_table(int size);

void insert(Item key);

void remove(Item key);

int search(Item key);
#endif
