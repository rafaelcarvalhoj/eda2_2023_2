//MC-202 Grafos, Prof. Rafael Schouery
#include <stdlib.h>

typedef struct {
    int **adj;
    int n;
}graph;

graph *create_graph(int n){
    graph *g = malloc(sizeof(graph));
    g->n = n;
    g->adj = malloc(sizeof(graph));
    for(int i = 0 ; i < n ; i++)
        g->adj[i] = malloc(n * sizeof(int *));

    for(int i = 0; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            g->adj[i][j] = 0;

    return g;
}

void free_graph(graph *g){
    for(int i = 0 ; i < g->n ; i++)
        free(g->adj[i]);
    free(g->adj);
    free(g);
}

void insert_edge(graph *g, int u, int v){
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void remove_edge(graph *g, int u, int v){
    g->adj[u][v] = 0;
    g->adj[v][u] = 0;
}

int has_edge(graph *g, int u, int v){
    return g->adj[u][v] == 1;
}

graph *read_graph(){
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    graph *g = create_graph(n);
    for(int i = 0; i < m ; i++){
        scanf("%d %d", &u, &v);
        insert_edge(g, u, v);
    }
    return g;
}

void print_edges(graph *g){
    for(int u = 0 ; u < g->n ; u++)
        for(int v = 0; v < g->n ; v++)
            if(g->adj[u][v]) printf("{%d %d}\n", u, v);
}

int degree(graph *g, int u){
    int degree = 0;
    for(int v = 0 ; v < g->n ; v++)
        if(g->adj[u][v]) degree++;

    return degree;
}

int max_degree(graph *g){
    int max_degree = degree(g, 0), max = 0, current, current_degree;
    for(current = 1 ; current < g->n; current++){
        current_degree = degree(g, current);
        if(current_degree > max_degree){
            max_degree = current_degree;
            max = current;
        }
    }
    return max;
}

int is_connected(graph *g, int s, int t){
    int founded, *visited;
    visited = malloc(sizeof(g->n));
    for(int i = 0 ; i < g->n ; i++)
        visited[i] = 0;
    founded = rec_search(g, visited, s, t);
    free(visited);
    return founded;
}

int rec_search(graph *g, int *visited, int s, int t){
    if(s == t) return 1;
    visited[s] = 1;
    for(int i = 0 ; i < g->n ; i++)
        if(!visited[i] && g->adj[s][i])
            if(rec_search(g, visited, i, t));
                return 1;
    return 0;
}