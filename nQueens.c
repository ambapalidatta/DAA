#include<stdio.h>
#include<stdbool.h>

void initialize(int n, char board[n][n], int leftrow[], int lowerdiag[], int upperdiag[]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            board[i][j] = '.';
        }
    }

    for(int i = 0; i < n; i++){
        leftrow[i] = 0;
    }

    for(int i = 0; i < (2 * n - 1); i++){
        lowerdiag[i] = 0;
        upperdiag[i] = 0;
    }
}

bool solve(int n, char board[n][n], int row, int leftrow[], int lowerdiag[], int upperdiag[]){
    if(row == n) return true;

    for(int col = 0; col < n; col++){
        if(leftrow[col] == 0 && lowerdiag[row + col] == 0 && upperdiag[(n - 1) + (col - row)] == 0){
            board[row][col] = 'Q';

            leftrow[col] = 1;
            lowerdiag[row + col] = 1;
            upperdiag[(n - 1) + (col - row)] = 1;

            if(solve(n, board, row + 1, leftrow, lowerdiag, upperdiag)) return true;

            board[row][col] = '.';

            leftrow[col] = 0;
            lowerdiag[row + col] = 0;
            upperdiag[(n - 1) + (col - row)] = 0;
        }
    }
    return false;
}

int main(){
    int n;
    printf("Enter the board size: ");
    scanf("%d", &n);

    char board[n][n];
    int leftrow[n];
    int lowerdiag[2 * n - 1];
    int upperdiag[2 * n - 1];

    initialize(n, board, leftrow, lowerdiag, upperdiag);

    if(solve(n, board, 0, leftrow, lowerdiag, upperdiag)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.')
                    printf("\t");
                else
                    printf("Q");
                // printf("%c ", board[i][j]);
            }
            printf("\n");
        }
    }
    else
    printf("No solution exists!");

    return 0;
}
