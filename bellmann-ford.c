#include<stdio.h>

#define N 6
#define INF 9999


void print(int dist[]){
    for(int i = 0; i < N; i++){
        printf("%d\n", dist[i]);
    }
}


void calculation(int graph[][N]){
    int dist[N] = {9999, 9999, 99999, 9999, 9999, 9999};

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

    int graph[N][N] = {{0, 5, 9999, 9999, 9999, 9999},
                    {9999, 0, -2, 9999, 9999, -3},
                    {9999, 9999, 0, 9999, 3, 9999},
                    {9999, 9999, 6, 0, -2, 9999},
                    {9999, 9999, 9999, 9999, 0, 9999},
                    {9999, 9999, 9999, 1, 9999, 0}};
    
    calculation(graph);
}
