#include <stdio.h>
#include <stdlib.h>

#define size 19

struct stone{
    char stoneColor;
    int count;
};

int cmp(char a, char b);
int checkVertical(char board[size][size]);
int checkHorizontal(char board[size][size]);
int checkDiagonal(char board[size][size]); 
int checkIndexDiagonal(char board[size][size], int i, int j, int side);
int findWinner(char board[size][size]); 

int main(){
    char board[size][size]; 
    for(int i = 0; i < size; i++){
        scanf("%s", &board[i]); 
    }

    int ans = findWinner(board); 
    if(ans == 1){
        printf("Black"); 
    } else if(ans == 0){
        printf("White"); 
    } else printf("No winner"); 
    

    return 0;
}
int findWinner(char board[size][size]){
    int ans = -1; 
    ans = checkHorizontal(board);
    if(ans != -1) return ans; 
    ans = checkVertical(board);
    if(ans != -1) return ans; 
    ans = checkDiagonal(board);
    return ans; 


}

int checkIndexDiagonal(char board[size][size], int i, int j, int side){ //side => 0 means left, 1 means right; 
    int num = 4, count = 0; 
    char chr = board[i][j]; 

    if(cmp(chr, '_') != 0) count++; 
    else return -1; 


    while(num--){
        if(side == 0){
            i+=1; 
            j+=1; 
            if(cmp(chr, board[i][j]) == 0)count++; 
            else break; 
            if(count >= 5){
                if(cmp(chr, 'O') == 0) return 0; 
                else return 1; 
            }  
        } else {
            i += 1; 
            j -= 1; 
            if(cmp(chr, board[i][j]) == 0)count++; 
            else break; 
            if(count >= 5){
                if(cmp(chr, 'O') == 0) return 0; 
                else return 1; 
            } 
        }
       
    }

    return -1; 
}

int checkDiagonal(char board[size][size]){
    // -1 -> no winner, 0 - white wins, 1 -> x wins.
    //check diagonal start from the left
    int num = size - 5, flag = -1; 
    for (int i = 0; i <= num; i++){
        for(int j = 0; j <= num; j++){
            flag = checkIndexDiagonal(board, i, j, 0); 
            if(flag != -1) return flag; 
            
        }
    }
    flag = -1; 
    for(int i = 0; i <= num; i++){
        for(int j = size-1; j >= 4; j--){
            flag = checkIndexDiagonal(board, i, j, 1); 
            if(flag != -1) return flag; 
        }
    }

    return flag; 

} 

int checkHorizontal(char board[size][size]){
    // -1 -> no winner, 0 - white wins, 1 -> x wins. 
    //struct stone data; 
    int flag = -1; 
    int count = 0; 
    char stone = '_';

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            char chr = board[i][j];
            if(cmp(chr, '_') != 0){
                if(cmp(chr, stone) == 0){
                    count++; 
                } else {
                    stone = chr; 
                    count = 1; 
                }
            }
            if(count >= 5){
                if(cmp(stone, 'X') == 0) return 1; 
                else return 1; 
            }
        }
        count = 0; 
    }

    return -1; 
}

int checkVertical(char board[size][size]){
    // -1 -> no winner, 0 - white wins, 1 -> x wins. 
    struct stone data[size]; 
    int flag = -1; 
    for(int i = 0; i < size; i++){
        data[i].stoneColor = 'a'; 
        data[i].count = 0; 
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            char chr = board[i][j];
            if(cmp(chr, '_') != 0){
                if(cmp(chr, 'O') == 0){
                    char temp = data[j].stoneColor; 
                    if(cmp(temp, 'X') == 0){
                        data[j].stoneColor = 'O';
                        data[j].count = 1;
                    } else {
                        data[j].stoneColor = chr; 
                        data[j].count++; 
                        if(data[j].count >= 5) {
                            flag = 0; 
                            break; 
                        }
                    }
                } else if(cmp(chr, 'X') == 0){
                    char temp = data[j].stoneColor; 
                    if(cmp(temp, 'O') == 0){
                        data[j].stoneColor = 'X'; 
                        data[j].count = 1; 
                    } else{
                        data[j].stoneColor = chr; 
                        data[j].count++; 
                        if(data[j].count >= 5){
                            flag = 1; 
                            break; 
                        }
                    }
                }
            }
            
        }
        if(flag != -1){
            return flag; 
        }
    }

    return flag; 
}

int cmp(char a, char b){
    if(a == b) return 0; 
    else return 1; 
}