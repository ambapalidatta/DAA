#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int min(int a, int b){
    return ((a < b)?a:b);
}

int matrixchain(int a[], int n){
    int dp[n][n];
    for(int i = 0; i < n; i++)
    dp[i][i] = 0;

    for(int len = 1; len < n; len++){
        for(int row = 0, col = len; row < n - len; row++, col++){
            dp[row][col] = INT_MAX;
            for(int k = row; k < col; k++){
                dp[row][col] = min(dp[row][col], dp[row][k] + dp[k + 1][col] + a[row]*a[k]*a[col]);
            }
        }
    }
    return dp[0][n - 1];
}

int main(){
    // Example matrix dimensions
    int matrix[] = {1, 2, 2, 3, 3, 4};  // Each matrix is represented by two consecutive integers: (rows, columns)
    int n = sizeof(matrix) / sizeof(matrix[0]) / 2; // Number of matrices
    
    int result = matrixchain(matrix, n);
    printf("Minimum number of scalar multiplications needed: %d\n", result);

    return 0;
}
