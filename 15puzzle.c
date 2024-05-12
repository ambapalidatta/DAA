#include<stdio.h>
#include<stdbool.h>

#define SIZE 4
int blank_row, blank_col;


int board[SIZE][SIZE];

void print(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] == 0){
                printf(" \t");
            }
            else
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}



void create(){
    printf("Enter the numbers between 1 to 15 sequentially and add '0' at any random place.\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            scanf("%d", &board[i][j]);
            if(board[i][j] == 0){
                blank_row = i;
                blank_col = j;
            }
        }
    }
    // board[SIZE - 1][SIZE - 1] = 0;  // Blank 

}



void perform(){
    int move;
    printf("The moves:\n1.MOVE UP\n2.MOVE DOWN\n3.MOVE LEFT\n4.MOVE RIGHT\n");
    printf("Enter your choice: ");
    scanf("%d", &move);
    switch (move)
    {
    case 1: // MOVE UP
    if(blank_row > 0){
        swap(&board[blank_row][blank_col], &board[blank_row - 1][blank_col]);
        blank_row--;
    }
    break;

    case 2: // MOVE DOWN
    if(blank_row < SIZE - 1){
        swap(&board[blank_row][blank_col], &board[blank_row + 1][blank_col]);
        blank_row++;
    }
    break;

    case 3: // MOVE LEFT
    if(blank_col > 0){
        swap(&board[blank_row][blank_col], &board[blank_row][blank_col - 1]);
        blank_col--;
    }
    break;

    case 4: // MOVE RIGHT
    if(blank_col < SIZE - 1){
        swap(&board[blank_row][blank_col], &board[blank_row][blank_col + 1]);
        blank_col++;
    }
    break;
    
    default:
        break;
    }
}



bool isSolved(){
    int num = 1;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if((board[i][j] != num) && !(i == SIZE - 1 && j == SIZE - 1 && board[i][j] == 0))
            return false;
            num = (num + 1) % (SIZE * SIZE);  // Increment num modulo SIZE*SIZE
        }
    }
    return true;
}


int main(){
    create();

    while(!isSolved()){
        print();
        perform();
    }

    printf("Congratulations! Your puzzle is solved");
    print();
    printf("HIII");

    return 0;
}
