//MC-202 Grafos, Prof. Rafael Schouery
#ifndef GRAPH_H
#define GRAPH_H

#define AND &&
#define OR ||
#define NEXT(A) (A->next)
typedef enum {TRUE = 1, FALSE = 0} bool;

typedef struct node {
    int vertex;
    struct node *next;
} node;

typedef struct graph {
    node *adjacency_list;
    int n;
    bool directed;
} graph;

graph *create_graph(int n);

void destroy_graph(graph *g);

void add_edge(graph *g, int u, int v);

void remove_edge(graph *g, int u, int v);

int has_edge(graph *g, int u, int v);

void print_graph(graph *g);

int *find_ways(graph *g, int s);

void dfs(graph *g, int *prev, int u, int v);

void print_reversed_way(int v, int *prev);

void print_way(int v, int *prev);
#endif