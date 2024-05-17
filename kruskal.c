#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INF 9999

int find(int arr[], int v){
    if(arr[v] == v) return v;
    return find(arr, arr[v]);
}


void uniOn(int arr[], int u, int v){
    u = find(arr, u);
    v = find(arr, v);

    arr[u] = v;
}


void krusk(int graph[MAX][MAX], int n){
    int arr[MAX];

    for(int i = 0; i < n; i++){
        arr[i] = i;
    }

    int edgeCount = 0;

    while(edgeCount < n - 1){
        int min = INF, u, v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(find(arr, i) != find(arr, j) && graph[i][j] < min){
                    min = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        uniOn(arr, u, v);
        printf("Edge: %d (%d --> %d) Weight: %d\n", edgeCount++, u, v, min);
    }
}

int main(){
    // int n;
    // printf("Enter the no. of vertices: ");
    // scanf("%d", &n);

    int n = 5;

    int graph[MAX][MAX] = {
        {0, 2, INF, 6, INF},
        {2, 0, 3, 8, 5},
        {INF, 3, 0, INF, 7},
        {6, 8, INF, 0, 9},
        {INF, 5, 7, 9, 0}
    };


    krusk(graph, n);

    return 0;
}
