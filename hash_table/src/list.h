#ifndef
#define LIST_H
typedef int Item;

typedef struct node{
    Item data;
    struct node *next;
}node;

node *Linsert(node *h, Item key);
int Lremove(node *h, Item key);
int Lsearch(node *h, Item key);

#endif
