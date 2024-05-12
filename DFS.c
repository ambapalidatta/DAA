#include<stdio.h>
#include<stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int A[7][7] = {
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

void dfs(int node){
    printf("%d ", node);
    visited[node] = 1;
    for(int j = 0; j < 7; j++){
        if(A[node][j] == 1 && visited[j] == 0)
        dfs(j);
    }
}

int main(){
    dfs(1);

    return 0;
}
