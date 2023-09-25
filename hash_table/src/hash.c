#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "list.h"

int create_table(HashTable *t, int size){
    t->M = size;
    t->HT = malloc(size*sizeof(node));
}

void insert(HashTable *t, Item key, int p){
    t->HT[p] = Linserir(t->HT[p], key);
}

void remove(HashTable *t, Item key, int p){
    Lremove(t->HT[p], key);
}

int search(HashTable *t, Item key, int p){
    return Lsearch(t->HT[p], key);
}
