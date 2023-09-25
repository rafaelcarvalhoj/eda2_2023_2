#include "list.h"
node* Linsert(node *h, Item key){
    node *new = (node*)malloc(sizeof(node));
    new->data = key;
    new->next = h;
    return new;
}

void Lremove(node *h, Item key){
    if(h == NULL || h->next == NULL) return;
    if(h->next->data == key){
        node *r = h->next;
        h->next = h->next->next;
        free(r)
        return;
    }
    return Lremove(h->next, key);
}

int Lsearch(node *h, Item key){
    if(h->data == key) return 1;
    if(h->next == NULL) return 0;
    return Lsearch(h->next, key);
}
