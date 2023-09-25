#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *input;
    struct node *next;
}node;

void insert(node *stack, char str[]){
    node *new = malloc(sizeof(node));
    new->input = malloc(sizeof(char)*101);
    strcpy(new->input, str);
    new->next = stack->next;
    stack->next = new;
}

char *pop(node *stack){
    node *ptr = stack->next;
    stack->next = stack->next->next;
    return ptr->input;
}

int is_empty(node *stack) { return stack->next == NULL; }

int main(){
    node *stack = malloc(sizeof(node));
    char op[10];
    while(scanf("%s",op) != EOF){
        if(!strcmp(op, "inserir")){  
            char *str = malloc(sizeof(char)*101);
            scanf(" %[^\n]s",str);
            insert(stack, str);
        }
        else { printf("%s\n", is_empty(stack)? "NULL" : pop(stack)); }
    }
    return 0; 
}
