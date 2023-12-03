#ifndef STACK_H
#define STACK_H
typedef struct node {
    int value;
    struct node *next;
} snode;

typedef struct{
    snode *top;
    int n;
}stack;

stack *create_stack();

void destroy_stack(stack *s);

void push(stack *s, int v);

int pop(stack *s);

snode *top(stack *s);

#endif