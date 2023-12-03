//MC-202 Grafos, Prof. Rafael Schouery
#ifndef GRAPH_H
#define GRAPH_H
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
#endif