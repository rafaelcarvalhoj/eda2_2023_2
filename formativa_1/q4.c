#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
}celula;

celula *busca(celula *le, int x){
    for(celula *p = le->prox; p != NULL; p = p->prox) if(p->dado == x) return p;
    return NULL;
}

celula *busca_rec(celula *le, int x){
    if(le->prox == NULL) return NULL;
    if(le->prox->dado == x) return le->prox;
    return busca_rec(le->prox, x);
}
