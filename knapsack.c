#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int calculation(int profit[], int weight[], int M, int n){
    int finalVal = 0;

    for(int i = 0; i < n; i++){
        int wi = weight[i];
        int pi = profit[i];

        if(M > 0 && wi < M){
            M = M - wi;
            finalVal += pi;
        }

        else{
            // finalVal += pi * ((double)M / wi);
            finalVal += pi * ((double) M / wi);
        }
    }
    return finalVal;
}

int main() {
    int n, w;
    printf("Enter the number of elements to be entered in the array: ");
    scanf("%d", &n);

    printf("Enter the maximum weight: ");
    scanf("%d", &w);

    int profit[n];
    int weight[n];

    for(int i = 0; i < n; i++){
        printf("Enter the profit for item %d: ", i);
        scanf("%d", &profit[i]);

        printf("Enter the weight for item %d: ", i);
        scanf("%d", &weight[i]);
    }

    // Sort weight and profit
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(profit[i]/weight[i] < profit[j]/weight[j]){
                swap(&weight[i], &weight[j]);
                swap(&profit[i], &profit[j]);
            }
        }
    }

    printf("The maximum profit: %d", calculation(profit, weight, w, n));
}
