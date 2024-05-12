#include<stdio.h>
#define INF 9999

int main(){
    int n, row, col, sum = 0, edge = 0, min = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int graph[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }


    // Testing purpose
    // int graph[5][5] = {
    //     {0, 2, 5, INF, INF},
    //     {2, 0, INF, 3, 4},
    //     {5, INF, 0, 1, INF},
    //     {INF, 3, 1, 0, INF},
    //     {INF, 4, INF, INF, 0}
    // };
    // n = 5;

    int visited[n];

    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    visited[0] = 1;

    while(edge < n - 1){
        min = INF;
        for(int i = 0; i < n; i++){
            if(visited[i] == 1){
                for(int j = 0; j < n; j++){
                    if(visited[j] == 0 && graph[i][j] < min){
                        min = graph[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }
        printf("The row: %d\tThe column: %d\tThe weight: %d\n", row, col, min);
        sum += min;
        edge++;
        visited[col] = 1;
    }

    printf("The sum: %d", sum);

    return 0;
}
