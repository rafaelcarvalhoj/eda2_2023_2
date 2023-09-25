#include <stdlib.h>
#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois (celula *p){
    if (p->prox == NULL) return 0;
    celula *rm = p->prox;
    if(rm->prox == NULL) p->prox = NULL;
    else p->prox = rm->prox;
    free(rm);
    return 1;
}

void remove_elemento (celula *le, int x){
    while(le->prox != NULL && le->prox->dado != x)
        le = le->prox;

    remove_depois(le);
}

void remove_todos_elementos (celula *le, int x){
    while(le->prox != NULL){
        if(le->prox->dado == x) remove_depois(le);
        else le = le->prox;
    }
}
