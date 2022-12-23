#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int dest;
    struct Node *next;
};

struct AdjList
{
    struct Node *head;
};

struct Graph
{
    int V;
    struct AdjList *array;
};

// create a new adjacency list node
struct Node *new_adj_list_node(int dest)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

// create a graph with V vertices
struct Graph *create_graph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// add an edge to an undirected graph
void add_edge(struct Graph *graph, int src, int dest)
{
    struct Node *new_node = new_adj_list_node(dest);
    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;

    new_node = new_adj_list_node(src);
    new_node->next = graph->array[dest].head;
    graph->array[dest].head = new_node;
}

// print the adjacency list representation of graph
void print_graph(struct Graph *graph)
{
    for (int v = 0; v < graph->V; ++v)
    {
        struct Node *p = graph->array[v].head;
        printf("Adjacency list of vertex %d\n head ", v);
        while (p)
        {
            printf("-> %d", p->dest);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    int V = 5;
    struct Graph *graph = create_graph(V);
    
    printf("\n\nName : Prashant Singh \n");
    printf("Roll Number : MCAN1CA22019\n\n");
    printf("** Adjacency List of A Graph **\n\n");
    
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 2);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 2);
    add_edge(graph, 4, 3);
    print_graph(graph);
}