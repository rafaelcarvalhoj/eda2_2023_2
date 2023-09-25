#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
    char city[26];
    struct node *next;
} node;

typedef struct{
    node *end;
    node *beggin;
    int size;
}queue;

queue *init(){
    queue *ptr = malloc(sizeof(queue));
    ptr->end = NULL;
    ptr->beggin = NULL;
    ptr->size = 0;
    return ptr;
}

void show(queue *q){
    node *ptr = q->beggin;
    int i = q->size;
    while(i--){
        printf("%s\n",ptr->city);
        ptr = ptr->next;
    }
}

void push(queue *q, char city[]){
    node *new = malloc(sizeof(node));
    strcpy(new->city, city);
    if(q->beggin == NULL){
        q->beggin = new;
        q->end = new;
    }
    else{
        q->end->next = new;
        q->end = q->end->next;
    }
    q->size += 1;
}

void to_end(queue *q, node *ptr){
    node *toEnd = ptr->next;
    ptr->next = ptr->next->next;
    q->end->next = toEnd;
    q->end = toEnd;
    toEnd->next = NULL;
}

int main(){
    queue *q = init();
    char *str = malloc(sizeof(char)*26);
    while(scanf("%s",str) != EOF){
        push(q, str);
    }

    int k = q->size - 1;
    node *ptr1 = q->beggin;
    node *ptr2 = ptr1->next;
    while(k-- ){
        int size_ptr1 = strlen(ptr1->city);
        if(tolower(ptr1->city[size_ptr1 - 1]) == tolower(ptr2->city[0])){
            to_end(q, ptr1);
        }
        ptr1 = ptr1->next;
        ptr2 = ptr1->next;
    }

    show(q);
    return 0;
}
