#include <stdio.h>
#include <stdlib.h>

#define hash(hash_table, key) (hash_table)->tb+((key)%(hash_table->M))

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

typedef struct{
    celula *tb;
    int M;
    int N;
}TH;

int THbusca (TH *h, int ch){
    celula *ptr = hash(h, ch);
    while(ptr->prox != NULL && ptr->dado != ch)
        ptr = ptr->prox;
    return ptr->dado == ch;
}

void THinsere (TH *h, int ch){
    if(THbusca(h, ch)) return;
    celula *ptr = hash(h, ch);
    celula *novo = malloc(sizeof(celula));
    novo->dado = ch;
    novo->prox = ptr->prox;
    ptr->prox = novo;
    h->N += 1;
}
int THremove (TH *h, int ch){
    if(!THbusca(h, ch)) return -1;
    celula *ptr = hash(h, ch);
    while(ptr->prox->dado != ch)
        ptr = ptr->prox;

    celula *rm = ptr->prox;
    ptr->prox = rm->prox;
    free(rm);
    h->N -= 1;
    return 0;
}