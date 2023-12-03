#include <stdlib.h>
#include "stack.h"

stack *create_stack(){
    stack *new = malloc(sizeof(stack));
    new->n = 0;
    new->top = NULL;
    return new;
}

void destroy_stack(stack *s) {
    while (s->top != NULL) {
        node *rm = s->top;
        s->top = s->top->next;
        free(rm);
    }
    free(s);
}

void push(stack *s, int v){
    node *new = malloc(sizeof(node));
    new->value = v;
    new->next = s->top;
    s->top = new;
    s->n ++;
}

int pop(stack *s){
    if(s->n == 0) return -1;
    int tmp = s->top->value;
    node *rm = s->top;
    s->top = s->top->next;
    free(rm);
    s->n --;
    return tmp;
}

node *top(stack *s){
    return s->top != NULL ? s->top->value : NULL;
}