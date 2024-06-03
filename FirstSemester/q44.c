#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char col[MAX]; 
} Input; 

int checkNeighbors(int rows, int cols, int gameState[rows][cols], int i, int j);
void playGame(int rows, int cols, int gameState[rows][cols]);

int main(){
    
    int numOfRounds = 0, rows = 0, cols = 0; 
    scanf("%d", &numOfRounds);
    Input gameState[MAX];
    while(scanf("%s", gameState[rows].col) != EOF){
        rows++; 
    }
    cols = strlen(gameState[0].col); 

    int arr[rows][cols]; 
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = gameState[i].col[j] - '0'; 
        }
    }

    for(int i = 0; i < numOfRounds; i++){
        playGame(rows, cols, arr); 
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d", arr[i][j]); 
        }
        printf("\n"); 
    }

    return 0;
}

void playGame(int rows, int cols, int gameState[rows][cols]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int count = checkNeighbors(rows, cols, gameState, i, j);
            if(count >= 4 || count <= 1){
                if(gameState[i][j] == 1) gameState[i][j] = -1; 
            } else if(count == 3){
                if(gameState[i][j] == 0) gameState[i][j] = -2; 
            }
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(gameState[i][j] == -1) gameState[i][j] = 0; 
            else if(gameState[i][j] == -2) gameState[i][j] = 1; 
        }
    }
}

int checkNeighbors(int rows, int cols, int gameState[rows][cols], int i, int j){
    int count = 0; 
    if(j > 0){ //can check the column left to the space; 
        if(i > 0){//can check the row that is to the top of the space; 
            if(gameState[i-1][j-1] == 1 || gameState[i-1][j-1] == -1) count++; 
        }
        if(gameState[i][j-1] == 1 || gameState[i][j-1] == -1) count++; 
        if(i <= rows - 2){//can check the row that is to the bottom of the space
            if(gameState[i+1][j-1] == 1 || gameState[i+1][j-1] == -1) count++;
        }   
    }
    if(j <= cols - 2){
        if(i > 0){//can check the row that is to the top of the space; 
            if(gameState[i-1][j+1] == 1 || gameState[i-1][j+1] == -1) count++; 
        }
        if(gameState[i][j+1] == 1 || gameState[i][j+1] == -1) count++; 
        if(i <= rows - 2){//can check the row that is to the bottom of the space
            if(gameState[i+1][j+1] == 1 || gameState[i+1][j+1] == -1) count++;
        } 
    }
    if( i > 0){
        if(gameState[i-1][j] == 1 || gameState[i-1][j] == -1) count++; 
    }
    if(i <= rows-2){
        if(gameState[i+1][j] == 1 || gameState[i+1][j] == -1) count++; 
    }

    return count; 
}