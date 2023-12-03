#ifndef STACK_H
#define STACK_H
typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct{
    node *top;
    int n;
}stack;

stack *create_stack();

void destroy_stack(stack *s);

void push(stack *s, int v);

int pop(stack *s);

node *top(stack *s);

#endif