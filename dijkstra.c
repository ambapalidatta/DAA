#include<stdio.h>

#define N 6
#define INF 9999

void print(int dist[]){
    for(int i = 0; i < N; i++){
        printf("%d\n", dist[i]);
    }
}

void calculation(int graph[N][N]){
    int dist[N] = {INF, INF, INF, INF, INF, INF};
    dist[0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if((graph[i][j] != INF) && ((dist[i] + graph[i][j]) < dist[j])){
                dist[j] = dist[i] + graph[i][j];
            }
        }
    }
    print(dist);
}



int main(){
    int graph[N][N] = {{0, 4, 4, INF, INF, INF},
                    {4, 0, 2, INF, INF, INF},
                    {4, 2, 0, 3, 1, 6},
                    {INF, INF, 3, 0, INF, 2},
                    {INF, INF, 2, INF, 0, 3},
                    {INF, INF, 6, 2, 3, 0}};
    
    calculation(graph);

    return 0;
}
