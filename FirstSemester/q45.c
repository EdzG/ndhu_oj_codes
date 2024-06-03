#include <stdio.h>
#include <stdlib.h>

#define dimension 9

int judgeW = 0, judgeB = 0, total = 0;
char ans[dimension][dimension];

void spread(int x, int y);

int main() {
    int times, W = 0, B = 0;
    scanf("%d", &times);

    for (int i = 0; i < times; i++) { //the number of boards 

        for (int m = 0; m < dimension; m++){
            for (int k = 0; k < dimension; k++){
                scanf(" %c", &ans[m][k]);
            }
        }

        for (int m = 0; m < dimension; m++) {
            for (int k = 0; k < dimension; k++) {
                if (ans[m][k] == '.') {
                    spread(m, k);
                    if (judgeW > 0 && judgeB == 0)
                        W += total;
                    else if (judgeB > 0 && judgeW == 0)
                        B += total;

                    total = 0;
                    judgeB = 0;
                    judgeW = 0;
                } else if (ans[m][k] == 'O')//counting white
                    W++;
                else if (ans[m][k] == 'X')//counting black
                    B++;
            }
        }
        //printing and resetting the counts. 
        printf("Black %d White %d\n", B, W);
        B = 0;
        W = 0;
    }

    return 0;
}

void spread(int x, int y) {
    ans[x][y] = 't'; // it has been traversed
    total++; 

    if (x > 0 && ans[x - 1][y] == '.')
        spread(x - 1, y);
    if (y > 0 && ans[x][y - 1] == '.')
        spread(x, y - 1);
    if (x < 8 && ans[x + 1][y] == '.')
        spread(x + 1, y);
    if (y < 8 && ans[x][y + 1] == '.')
        spread(x, y + 1);

    if (x > 0 && ans[x - 1][y] == 'O')
        judgeW++;
    if (y > 0 && ans[x][y - 1] == 'O')
        judgeW++;
    if (x < 8 && ans[x + 1][y] == 'O')
        judgeW++;
    if (y < 8 && ans[x][y + 1] == 'O')
        judgeW++;

    if (x > 0 && ans[x - 1][y] == 'X')
        judgeB++;
    if (y > 0 && ans[x][y - 1] == 'X')
        judgeB++;
    if (x < 8 && ans[x + 1][y] == 'X')
        judgeB++;
    if (y < 8 && ans[x][y + 1] == 'X')
        judgeB++;

    return;
}