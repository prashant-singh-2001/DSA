#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge *edge;
};

// Creates a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge *)malloc(graph->E * sizeof(struct Edge));

    return graph;
}

// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};

// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    if (subsets[x].rank < subsets[y].rank)
        subsets[x].parent = y;
    else if (subsets[x].rank > subsets[y].rank)
        subsets[y].parent = x;
    else
    {
        subsets[y].parent = x;
        subsets[x].rank++;
    }
}

int cmp(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight > b1->weight;
}
// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[V]; 
    int e = 0;             
    int i = 0;    
    int totalWeight=0;         

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), cmp);

    // Allocate memory for creating V subsets
    struct subset *subsets =
        (struct subset *)malloc(V * sizeof(struct subset));

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        {
            printf("%d -- %d == %d\n", result[i].src, result[i].dest,
               result[i].weight);
               totalWeight+=result[i].weight;
        }
    printf("Total Weight : %d",totalWeight);
    return;
}

int main()
{
    printf("\n\nName : Prashant Singh \n");
    printf("Roll Number : MCAN1CA22019\n\n");
    printf("** Kruskal Algo.'s Implementation **\n\n");

    // Weighted graph
    //     10
    //   0----1
    //   | \  |
    // 6 | 5\ |15
    //   |   \|
    //   2----3
    //      4
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    struct Graph *graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);
}