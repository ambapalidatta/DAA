// Add element from the rear side and remove element fromt the front side.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue{
    int size, f, r;
    int *arr;
};

bool isFull(struct queue* q)
{
    if(q -> r == q -> size - 1)    // If the rear(last) index is at index of size - 1(at the end).
    return 1;
    return 0;
}

bool isEmpty(struct queue* q)
{
    if(q -> r == q -> f)           // If the front(starting) index is equal to the rear(last) index.
    return 1;
    return 0;
}

void enqueue(struct queue* q, int val)
{
    q -> r++;                      // Increase the index of rear(end).
    q -> arr[q -> r] = val;        // Add value at the rear index.
}

int dequeue(struct queue* q)
{
    int a = -1;                     

    q -> f++;                      // Increment the value of front(start).
    a = q -> arr[q -> f];          // Store the element of the front index.
    return a;                      // Return the element.
}

void bfs(struct queue* q, int a[][7], int visited[], int i){
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);
    while(!isEmpty(q)){
        int node = dequeue(&q);
        for(int j = 0; j < 7; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
}

int main()
{
    struct queue q;
    int val;
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size * sizeof(int));

    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    bfs(&q, a, visited, 0);

    return 0;
}
