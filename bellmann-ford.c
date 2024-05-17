#include<stdio.h>

#define N 6
#define INF 9999


void print(int dist[]){
    for(int i = 0; i < N; i++){
        printf("%d\n", dist[i]);
    }
}


void calculation(int graph[][N]){
    int dist[N] = {INF, INF, INF, INF, INF, INF};

    dist[0] = 0;

    // Calculation
    for(int count = 0; count < (N - 1); count++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if((graph[i][j] != INF) && (dist[i] + graph[i][j] < dist[j]))
                dist[j] = dist[i] + graph[i][j];
            }
        }
    }

    // Checking for negative edges.
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph[i][j] != INF && dist[i] + graph[i][j] < dist[j]){
                printf("Graph contains negative weight cycle.\n");
                return;
            }
        }
    }

    // Printing
    print(dist);
}

int main(){

    int graph[N][N] = {{0, 5, INF, INF, INF, INF},
                    {INF, 0, -2, INF, INF, -3},
                    {INF, INF, 0, INF, 3, INF},
                    {INF, INF, 6, 0, -2, INF},
                    {INF, INF, INF, INF, 0, INF},
                    {INF, INF, INF, 1, INF, 0}};
    
    calculation(graph);
}
