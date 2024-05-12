#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define V 5

int isSafe(int graph[][V], int path[], int pos, int v){
    if(graph[path[pos - 1]][v] == 0)
    return 0;

    for(int i = 0; i < pos; i++){
        if(path[i] == v)
        return 0;
    }
    return 1;
}

int hamil(int graph[][V], int path[], int pos){
    // Edge Case
    if(pos == V){
        if(graph[path[pos - 1]][path[0]] == 1)
        return 1;
        else
        return 0;
    }

    // Trying for all other vertices
    for(int v = 0; v < V; v++){
        if(isSafe(graph, path, pos, v) == 1){
            path[pos] = v;
            if(hamil(graph, path, pos + 1) == 1)
            return 1;
            path[pos] = -1;
        }
    }
    return 0;
}

void print(int path[]){        
    printf("Solution exist\n");

    for(int i = 0; i < V; i++){
        printf(" %d ", path[i]);
    }
    printf(" %d ", path[0]);
    printf("\n");
}

int main(){
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };

    int *path = (int*)malloc(V * sizeof(int));
    path[0] = 0;

    for(int i = 1; i < V; i++)
    path[i] = -1;

    if(hamil(graph, path, 1) == 0){
        printf("Solution does not exist\n");
        return 0;
    }
    
    print(path);
}
