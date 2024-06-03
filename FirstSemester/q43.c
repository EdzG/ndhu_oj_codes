#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001

typedef struct {
    char integer[1000];
    char decimal[1000];
} DeciVar;

void getInput(DeciVar *num);
int calcSum(int result[], char firstNum[], char secondNum[], int carry);
void printData(int integer[], int decimal[]); 

int main(){

    int integer[MAX] = {}, decimal[MAX] = {}; 
    DeciVar firstNum, secondNum; 

    getInput(&firstNum); 
    getInput(&secondNum); 
    int carry = calcSum(decimal, firstNum.decimal, secondNum.decimal, 0); 
    calcSum(integer, firstNum.integer, secondNum.integer, carry); 
    printData(integer, decimal); 

    return 0; 
}

void getInput(DeciVar *num)
{
    char entireNum[MAX];
    int dotIndex = 0, i = 0, j= 0;
    //gets both the integer part and decimal part of a num together. 
    fgets(entireNum, 2 * MAX, stdin);
    for(j = 0; j < strlen(entireNum); j++){
        if(entireNum[j] == '.') dotIndex = j; //finds Index of the dot
        if(entireNum[j] == '\n') {
            entireNum[j] = '\0';
        } //removes new line char
    }
    
    for (i = 0; i < dotIndex; i++)
    {
        num->integer[i] = entireNum[i];
    }
    num->integer[i] = '\0'; //makes the last character a null character -> end of string. 
    j = 0; //so that decimal indexing starts from 0 as well
    for (i = dotIndex+1; i < strlen(entireNum); i++)
    {
        num->decimal[j] = entireNum[i];
        j++;
    }
    num->decimal[j] = '\0';

}

int calcSum(int result[], char firstNum[], char secondNum[], int carry){
    int biggerSize = 0, smallerSize = 0, flag = 0, num = 0, hadInitialCarry = 0; 

    if(carry){
        hadInitialCarry = 1;//flag
    }
    if(strlen(firstNum) > strlen(secondNum)){
        biggerSize = strlen(firstNum); 
        smallerSize = strlen(secondNum); 
        flag = 0; 
    } else {
        biggerSize = strlen(secondNum); 
        smallerSize = strlen(firstNum); 
        flag = 1; 
    }

    int j = smallerSize - 1; 
    
    for(int i = biggerSize-1; i >= 0; i--){
        if(j >= 0){
            if(flag) num = (firstNum[j]-'0') + (secondNum[i] - '0');
            else num = (firstNum[i] - '0') + (secondNum[j] - '0'); 
            j--; 
        } else {
            if(flag) num = secondNum[i] - '0';
            else num = firstNum[i] - '0'; 
        }
        num += carry;
        carry = num / 10; 
        num %= 10; 
        result[i+1] = num;
    }
    if(hadInitialCarry == 0) result[0] = 0; 
    else result[0] = carry;
    result[biggerSize+1] = -1; 

    return carry; 

}

void printData(int integer[], int decimal[]){
    int i = 0; 
    if(integer[0] == 0) i = 1; 
    while(integer[i] != -1){
        printf("%d", integer[i]); 
        i++; 

    }

    i = 0; 
    while(decimal[i] != -1){
        if(decimal[0] == 0) break; 
        else printf("."); 
        printf("%d", decimal[i]); 
        i++; 
    }
}
