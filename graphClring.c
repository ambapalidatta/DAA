#include<stdio.h>
#include<stdbool.h>

#define N 4

bool isSafe(int graph[][N], int color[], int node, int col){
    for(int i = 0; i < N; i++){
        if(graph[node][i] == 1 && color[i] == col)
        return false;
    }
    return true;
}

bool graphClr(int graph[][N], int color[], int n, int m, int node){
    // Base Case
    if(node == n){
        return true;
    }

    for(int i = 0; i < m; i++){
        if(isSafe(graph, color, node, i)){
            color[node] = i;
            if(graphClr(graph, color, n, m, node + 1)) return true;
            color[node] = 0;
        }
    }
    return false;
}

void print(int color[]){
    for(int i = 0; i < N; i++){
        printf(" %d ", color[i]);
    }
}

int main(){
    int graph[N][N] = {
    {0, 1, 0, 1},
    {1, 0, 1, 1},
    {0, 1, 0, 1},
    {1, 1, 1, 0}
};

    int m = 3; // Number of colors

    int color[N];

    for(int i = 0; i < m; i++){
        color[i] = 0;
    }

    if(graphClr(graph, color, N, m, 0))
    print(color);

    else
    printf("No solution exists");

    return 0;
}
