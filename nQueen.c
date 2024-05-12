#include<stdio.h>
#include<stdlib.h>

int validate

void placing(){
    // Base Case
    if(col >= len){
        res.add(construct(board));
        return res;
    }

    for(int row = 0; row < n; row++){
        if(validate()){
            graph[row][col] = 'Q';
            placing();
            graph[row][col] = '.';
        }
    }
    return res;
}

int main(){

}
