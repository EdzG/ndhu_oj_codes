#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col; 

    scanf("%d %d", &row, &col); 
    int arr[row][col]; 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d ", &arr[i][j]);       
        }
    }
    int rowStart = 0, rowEnd = row, colStart = 0, colEnd = col; 
    int num = row * col; 
    while(num){
        //prints all the numbers from the starting col until the ending col. 
        for(int i = colStart; i < colEnd; i++){
            printf("%d ", arr[colStart][i]);
            num--;
        }
        //the first row has been printed so remove it.
        rowStart++; 

       //prints all the numbers from the last column

        for(int i = rowStart; i < rowEnd; i++){
            printf("%d ", arr[i][colEnd-1]);
            num--;
        }
        //the last col has been printed so remove it. 
        colEnd--; 
       
        //prints all the numbers from the bottom row.
        for(int i = colEnd-1; i >= colStart; i--){
            printf("%d ", arr[rowEnd-1][i]);
            num--;
        }
        //the last row has been printed so remove it. 
        rowEnd--; 

        //prints all the numbers from the first column. 
        for(int i = rowEnd-1; i >= rowStart; i--){
            printf("%d ", arr[i][colStart]);
            num--; 
        }
        //the first column has been printed so remove.
        colStart++; 
       

    }
    
    return 0; 
}
