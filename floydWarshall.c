#include <stdio.h>
#include <limits.h>
#define V 7 
#define INF 99999

void printSolution(int dist[][V]) {
printf("Shortest distances between every pair of vertices:\n");
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
if (dist[i][j] == INF)
printf("%7s", "INF");
else
printf("%7d", dist[i][j]);}
printf("\n");}}

void floydWarshall(int graph[][V]) {
// int dist[V][V];
int i, j, k;
// for (i = 0; i < V; i++)
// for (j = 0; j < V; j++)
// dist[i][j] = graph[i][j];

for (k = 0; k < V; k++) {
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][k] + graph[k][j] < graph[i][j])
                graph[i][j] = (graph[i][j] < (graph[i][k] + graph[k][j])) ? graph[i][j] : (graph[i][k] + graph[k][j]);
        }
    }
}

printSolution(graph);
}

// Main function
int main() {
int graph[V][V] = {{0, 5, INF, 10, 10, 6, 7},
{INF, 0, 3, INF, 6, 9, 2},
{INF, 4, 0, 4, 5, 9, 1},
{INF, 4, 3, 0, 5, 9, INF},
{7, 8, 3, INF, 0, 3, 2},
{INF, INF, 6, 1, 9, 0, 5},
{INF, INF, INF, 5, 7, 2, 0}};
floydWarshall(graph);
return 0;
}
