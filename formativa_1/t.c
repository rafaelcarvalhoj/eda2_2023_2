#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le){
    while(le->prox != NULL){
        printf("%d -> ", le->dado);
        le = le->prox;
    }
    printf("%d -> NULL\n", le->dado);
}

void imprime_rec (celula *le){
    if(le->prox == NULL){
        printf("%d -> NULL\n", le->dado);
        return;
    }
    printf("%d -> ", le->dado);
    imprime_rec(le->prox);
}

// Função para inserir um novo elemento no início da lista
void insere(int valor, celula **le) {
    celula *nova_celula = (celula *)malloc(sizeof(celula));
    nova_celula->dado = valor;
    nova_celula->prox = *le;
    *le = nova_celula;
}

int main() {
    celula *lista = NULL; // Inicializa a lista como vazia

    // Insere elementos na lista
    insere(3, &lista);
    insere(2, &lista);
    insere(1, &lista);

    // Testa as funções de impressão
    printf("Iterativa:\n");
    imprime(lista);

    printf("\nRecursiva:\n");
    imprime_rec(lista);

    // Libera a memória alocada para a lista
    while (lista != NULL) {
        celula *temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}

