#include<stdio.h>
#include<stdbool.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int arr[], int n){
    printf("The job ID's: ");
    for(int i = 0; i < n; i++){
        if(arr[i] != -1)
        printf("%d ", arr[i]);
    }
}

void calculation(int deadline[], int profit[], int id[], int n){
    // Finding the deadline which is having maximum among others.
    int max = 0;
    for(int i = 0; i < n; i++){
        if(max < deadline[i]){
            max = deadline[i];
        }
    }

    int arr[max + 1];

    // Initializing all the values of an array to -1
    for(int i = 0; i <= max; i++)
    arr[i] = -1;

    int jobProfit = 0, jobCount = 0;

    for(int i = 0; i < n; i++){
        for(int j = deadline[i]; j > 0; j--){
            if(arr[j] == -1){
                arr[j] = id[i];
                jobProfit += profit[i];
                jobCount++;
                break;
            }
        }
    }

    printf("The profit: %d\n", jobProfit);
    printf("Total number of jobs done: %d\n", jobCount);

    print(arr + 1, max);
}

int main(){
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    int profit[n];
    int deadline[n];
    int id[n];

    printf("Enter the deadline and profit simultaneously for each job:\n");
    for(int i = 0; i < n; i++){
        id[i] = i;
        scanf("%d", &deadline[i]);
        scanf("%d", &profit[i]);
    }

    // Sort deadlines and profit
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(profit[i] < profit[j]){
                swap(&deadline[i], &deadline[j]);
                swap(&profit[i], &profit[j]);
                swap(&id[i], &id[j]);
            }
        }
    }

    calculation(deadline, profit, id, n);


    return 0;
}
