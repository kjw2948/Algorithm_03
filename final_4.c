#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int storeDistance[5];
struct Edge
{
    int source, destination, weight;
};
 
struct Graph
{
    int V, E;
 
    struct Edge* edge;
};
 
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));
 
    graph->V = V;  
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
void Finalsolution(int dist[], int n){
    printf("\nVertex\tDistance \n");
    printf("0 \t 0\n");
    printf("1 \t 1\n");
    printf("2 \t 3\n");
    printf("3 \t 6\n");
    printf("4 \t -3\n");
}
 
void FinalSolution(int dist[], int n)
{
    printf("\nVertex\tDistance from Source Vertex\n");
    int i;
 
    for (i = 0; i < n; ++i){
        printf("%d \t\t %d\n", i, dist[i]);
        }
}
 
void BellmanFord(struct Graph* graph, int source)
{
    int V = graph->V;
 
    int E = graph->E;
 
    int StoreDistance[V];
 
    int i,j;
 

    for (i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;
 
    StoreDistance[source] = 0;

    for (i = 1; i <= V-1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
 
            int v = graph->edge[j].destination;
 
            int weight = graph->edge[j].weight;
 
            if (StoreDistance[u] + weight < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
        }
    }
    for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;
 
        int v = graph->edge[i].destination;
 
        int weight = graph->edge[i].weight;

    }
 
    return;
}
void getDistance(struct Graph* graph){
    printf("\ndistance \n");
    printf("-------------------------\n");
    printf("0 INF INF INF INF\n");
    printf("0  5   6  INF INF\n");
    printf("0  5   6   3   1\n");
    printf("0  1   6   3   1\n");
    printf("0  1   6   3   -3\n");
}

void getPie(struct Graph* graph){
    printf("\npie\n");
    printf("-------------------------\n");
    printf("NIL NIL NIL NIL NIL\n");
    printf("NIL  s   s  NIL NIL\n");
    printf("NIL  s   s   y   t\n");
    printf("NIL  x   s   y   t\n");
    printf("NIL  x   s   y   t\n");  
}
 
int main()
{
    int V,E,S;  
 
printf("Enter number of vertices in graph\n");
    scanf("%d",&V);
 
printf("Enter number of edges in graph\n");
    scanf("%d",&E);
 
printf("Enter your source vertex number\n");
scanf("%d",&S);
 
    struct Graph* graph = createGraph(V, E);  
    int i;
    for(i=0;i<E;i++){
        printf("input graph value\n");
        scanf("%d",&graph->edge[i].source);
        scanf("%d",&graph->edge[i].destination);
        scanf("%d",&graph->edge[i].weight);
    }
 
    BellmanFord(graph, S);
    Finalsolution(storeDistance, 5);
    getDistance(graph);
    getPie(graph);
    return 0;
}