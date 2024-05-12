#include<stdio.h>

void maxmin(int a[],int s, int e, int res[]){
    int max = 0, min = 0;

    if(s >= e) {
        max = min = a[s];
        res[0] = (min < res[0])?min:res[0];
        res[1] = (max > res[1])?max:res[1];
        return;
    }

    if(s == e - 1){
        min = (a[s] < a[e])?a[s]:a[e];
        max = (a[s] < a[e])?a[e]:a[s];
        res[0] = (min < res[0])?min:res[0];
        res[1] = (max > res[1])?max:res[1];
        return;
    }

    int mid = s + (e - s) / 2;
    maxmin(a, s, mid, res);
    maxmin(a, mid + 1, e, res);


}

int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements in the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int res[2];

    res[0] = res[1] = a[0];

    maxmin(a, 0, n - 1, res);

    printf("The minimum element: %d \n", res[0]);
    printf("The maximum element: %d \n", res[1]);

    return 0;
}
