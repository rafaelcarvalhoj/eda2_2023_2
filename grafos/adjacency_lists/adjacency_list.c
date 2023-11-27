// THE Algorithm Desing MANUAL - Steven S. Skiena
// Adjacency List Graph Implemetation
#include <stdio.h>
#include <stdlib.h>

typedef enum {TRUE = 1, FALSE = 0} bool;

#define MAXV 1000

typedef struct edgenode{
    int y;
    int weight;
    struct edgenode *next;    
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    bool directed;
} graph;

void initialize_graph(graph *g, bool directed) {
    int i;
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    for(int i = 0 ; i < MAXV ; i++) {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}

void insert_edge(graph *g, int x, int y, bool directed) {
    edgenode *p;
    
    p = malloc(sizeof(edgenode));

    p->weight = NULL;
    p->y = y;
    p->next = g->edges[x];

    g->edges[x] = p;

    g->degree[x] ++;

    if(directed == FALSE)
        insert_edge(g, y, x, TRUE);
    else
        g->nedges ++;
}

void free_edge(edgenode *e){
    if(e!=NULL){
        free_edge(e->next);
        free(e);
    }
}

void free_graph(graph *g){
    for(int u = 0; u < g->nedges ; u++){
        free_edge(g->edges[u]);
    }
    free(g);
}

void read_graph(graph *g, bool directed) {
    int i, m, x, y;

    initialize_graph(g, directed);

    scanf("%d %d", &(g->nvertices), &m);

    for(int i = 1 ; i <= m ; i++) {
        scanf("%d %d", &x, &y);
        insert_edge(g, x, y, directed);
    }
}

void print_graph (graph *g) {
    edgenode *p;
    for (int i = 1 ; i < g->nvertices ; i++) {
        printf("%d: ",i);
        p = g->edges[i];
        while(p != NULL) {
            printf(" %d", p->y);
            p = p->next;
        }
        printf("/n");
    }
}