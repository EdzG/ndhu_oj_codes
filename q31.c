#include <stdio.h>
#include <stdlib.h>

int main() {
    int row = 0, col = 0, numOfElements; 
    scanf("%d %d %d", &row, &col, &numOfElements); 
    int arr[row][col];
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            arr[i][j] = 0; 
        }
    }
    for(int i = 0; i < numOfElements; i++){
        int row, col, val;
        scanf("%d %d %d", &row, &col, &val);
        arr[row][col] = val; 
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
