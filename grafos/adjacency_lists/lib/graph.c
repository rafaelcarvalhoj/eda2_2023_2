#include <stdlib.h>
#include "graph.h"
#include "stack/stack.h"

graph *create_graph(int n){
    graph *g = malloc(sizeof(graph));
    g->n = n;
    g->adjacency_list = malloc(sizeof(node*) * n);
    for(int i = 0; i < n; i++){
        g->adjacency_list[i] = NULL;
    }

    return g;
}

void destroy_graph(graph *g){
    for(int i = 0; i < g->n ; i++){
        node *current = g->adjacency_list[i];
        while(current != NULL){
            node *next = current->next;
            free(current);
            current = next;
        }
    }
    free(g->adjacency_list);
    free(g);
}

void add_edge(graph *g, int u, int v){
    //v -> u
    node *new_v = malloc(sizeof(node));
    new_v->vertex = u;
    new_v->next = g->adjacency_list[v];
    g->adjacency_list[v] = new_v;
    
    // u -> v
    if(g->directed == FALSE){
        node *new_u = malloc(sizeof(node));
        new_u->vertex = u;
        new_u->next = g->adjacency_list[u];
        g->adjacency_list[u] = new_u;
    }
}

void remove_edge(graph *g, int u, int v){
    // v -> u
    node *current = g->adjacency_list[v];
    node *prev = NULL;
    while(current != NULL AND current->vertex != u){
        prev = current;
        current = current->next;
    }
    if(current != NULL){
        if (prev == NULL)
            g->adjacency_list[v] = current->next != NULL ? current->next : NULL;
        else
            prev->next = current->next != NULL ? current->next : NULL;
        free(current);
    }

    // u -> v
    if(g->directed == FALSE){
        current = g->adjacency_list[u];
        prev = NULL;
        while(current != NULL AND current->vertex != v){
            prev = current;
            current = current->next;
        }
        if(current != NULL){
            if (prev == NULL)
                g->adjacency_list[u] = current->next != NULL ? current->next : NULL;
            else
                prev->next = current->next != NULL ? current->next : NULL;
            free(current);
        }
    }
}

int has_edge(graph *g, int u, int v){
    node *current = g->adjacency_list[u];
    while(current != NULL AND current->vertex != v){
        current = current->next;
    }
    return current != NULL;
}

void print_graph(graph *g){
    for(int i = 0; i < g->n; i++){
        printf("%d: ", i);
        node *current = g->adjacency_list[i];
        while(current != NULL){
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

int *find_ways(graph *g, int s){
    int *prev = malloc(sizeof(int) * g->n);
    for(int i = 0 ; i < g->n; i++)
        prev[i] = -1;
    dfs(g, prev, s, s);
    return prev;
}

void dfs(graph *g, int *prev, int parent, int current){
    prev[current] = parent;
    for(node *tmp = g->adjacency_list[current] ; current != NULL ; current = NEXT(current))
        if(prev[tmp->vertex] == -1)
            dfs(g, prev, current, NEXT(tmp));
}

void print_reversed_way(int v, int *prev){
    printf("%d ", v);
    if(prev[v] != v)
        print_reversed_way(prev[v], prev);
}

void print_way(int v, int *prev){
    if(prev[v] != v)
        print_reversed_way(prev[v], prev);
    printf("%d ", v);
}