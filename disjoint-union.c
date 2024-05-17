#include<stdio.h>

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int find(int arr[], int x){
    if(arr[x] != x) arr[x] = find(arr, arr[x]);
    return x;
}

void uniOn(int arr[], int rank[], int a, int b, int n){
    int x = find(arr, a);
    int y = find(arr, b);


    if(x == y){
        printf("Cycle detected\n");
        print(arr, n);
        return;
    } 
    if(rank[x] < rank[y]) arr[x] = y;

    else if(rank[y] < rank[x]) arr[y] = x;

    else{
        arr[y] = x;
        rank[y] = rank[y] + 1;
    }
}
 
int main(){
    int n;
    printf("Enter the number of edges: ");
    scanf("%d", &n);

    int arr[n];
    int rank[n];

    for(int i = 0; i < n; i ++){
        arr[i] = i;
    }

    int a, b, choice = 1;

    while(choice){
        printf("Enter two numbers: ");
        scanf("%d", &a);
        scanf("%d", &b);
        
        if(a < n && b < n) uniOn(arr, rank, a, b, n);
        else{
            if(a >= n){
                printf("The first input is out of bound. Try again!\n");
                scanf("%d", &a);
            }
            if(b >= n){
                printf("The second input is out of bound. Try again!\n");
                scanf("%d", &b);
            }
            uniOn(arr, rank, a, b, n);
        }

        printf("Do you want to continue(1 for yes 0 for no): ");
        scanf("%d", &choice);
    }

    printf("The final condition: ");
    print(arr, n);

    return 0;
}
