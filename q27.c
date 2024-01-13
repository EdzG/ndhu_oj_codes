#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define funcLength 5

struct blockData{
    int blockNum, *ptr, *prevPtr; 
};

void onto(struct blockData data[], int a);
int over(struct blockData data[], int b);
void move(struct blockData data[], int a, char* actSpec, int b);
void printData(struct blockData data[], int size);
void pile(struct blockData data[], int a, char* actSpec, int b);
int tester(struct blockData data[], int a, int b);

int main(){
    char act[funcLength], actSpec[funcLength];
    int blockA, blockB, blocks;
    scanf("%d", &blocks); 
    struct blockData data[blocks]; 
    
    for(int i =0; i < blocks; i++){
        data[i].blockNum = i; 
        data[i].ptr = NULL;
        data[i].prevPtr = NULL; 
        //printf("%d", data[i].blockNum);
    }
    
    while(scanf("%s", act) == 1){
        
        if(strcmp(act, "quit") == 0) break; 
        scanf("%d %s %d", &blockA, actSpec, &blockB);
        if((blockA != blockB) && tester(data, blockA, blockB) != 1){ 
            //if() continue; 
            if(strcmp(act, "move") == 0){
                move(data, blockA, actSpec, blockB);
            } else if(strcmp(act, "pile") == 0){
                pile(data, blockA, actSpec, blockB); 
            }
        }
        
    }
    
    printData(data, blocks);

    return 0; 
}

//clear the blocks at the top the given block. 
void onto(struct blockData data[], int a){
    int *ptrChecker = data[a].ptr; 
    data[a].ptr = NULL; //removes all the blocks on top of a

    while(ptrChecker != NULL){ //checks to see if the block is pointing to another block; 
        int num = *ptrChecker; //assigns num the value at which a was pointing to.
        data[num].prevPtr = NULL;//removes the link to the previous num. 
        ptrChecker = data[num].ptr; //updates the ptrChecker
        data[num].ptr = NULL;//IF CODE GOES WRONG DELETE THIS. 
    }
}

//returns the last block on top of the given block - if there is not block on top, it returns the same block
int over(struct blockData data[], int b){
    int *ptrChecker = data[b].ptr; 
    int num = b; 
    while(ptrChecker != NULL){
        num = *ptrChecker;
        ptrChecker = data[num].ptr; 
    }
    return num; 
}


void move(struct blockData data[], int a, char* actSpec, int b){
    if(strcmp(actSpec, "onto") == 0){
       onto(data, a); //removes all the blocks on top of a
        //checks to see if there was any number below a and removes the link between them.
        if(data[a].prevPtr!=NULL){
            int num = *data[a].prevPtr; //assigns num the value at which a was pointing to.
            data[num].ptr = NULL;//removes the link to the previous num. 
            data[a].prevPtr = NULL;// 
        }

       onto(data, b); //removes all the blocks on top of b
       data[b].ptr = &data[a].blockNum; //block b points to block a - means that a is on top of b
       data[a].prevPtr = &data[b].blockNum;; //updates the prevPtr of block to represent that block b is below it.

    } else if(strcmp(actSpec, "over") == 0) {
        onto(data, a); //remvoes all the blocks on top of a 

        //checks to see if there was any number below a and removes the link between them.
        if(data[a].prevPtr!=NULL){
            int num = *data[a].prevPtr; //assigns num the value at which a was pointing to.
            data[num].ptr = NULL;//removes the link to the previous num. 
            data[a].prevPtr = NULL;// 
        }

        int num = over(data, b); //finds the last block on top of block b and returns it.
        data[num].ptr = &data[a].blockNum;//the last block on top of black b points to block a
        data[a].prevPtr = &data[num].blockNum; //updates the prevPtr
        
    } 
}


void pile(struct blockData data[], int a, char* actSpec, int b){
    
    if(strcmp(actSpec, "onto") == 0){
        onto(data, b); //removes all the blocks on top of block b
        //removes the link of block a and the block directly below block a - if there is any
        if(data[a].prevPtr != NULL){
            int num = *data[a].prevPtr;
            data[a].prevPtr = NULL;
            data[num].ptr = NULL;
        }
        data[b].ptr = &data[a].blockNum; 
        data[a].prevPtr = &data[b].blockNum;
    } else if(strcmp(actSpec, "over") == 0) {
        //removes the link between block a and any block that is below block a
         if(data[a].prevPtr != NULL){
            int temp = *data[a].prevPtr;
            data[a].prevPtr = NULL;
            data[temp].ptr = NULL;
        }
        int num = over(data, b);
        data[num].ptr = &data[a].blockNum;
        data[a].prevPtr = &data[num].blockNum;
    } 
}

int tester(struct blockData data[], int a, int b){
    //checks the numbers after a
    int *ptrChecker = data[a].ptr; 
    while(ptrChecker != NULL){ //checks to see if the block is pointing to another block; 
        int num = *ptrChecker; //assigns num the value at which a was pointing to.
        if(num == b) return 1; //block b is in the same stack as a. 
        ptrChecker = data[num].ptr; //updates the ptrChecker
    }
    //checks the numbers before block a.
    ptrChecker = data[a].prevPtr; 
     while(ptrChecker != NULL){ //checks to see if the block is pointing to another block; 
        int num = *ptrChecker; //assigns num the value at which a was pointing to.
        if(num == b) return 1; //block b is in the same stack as a. 
        ptrChecker = data[num].prevPtr; //updates the ptrChecker
    }
    
    return 0; 
    
}


void printData(struct blockData data[], int size){
    for(int i = 0; i < size; i++){
        printf("%d:", i);
        if(data[i].prevPtr == NULL){
           //printf(" |%d %d %d", i, data[i].prevPtr, data[i].ptr); //It is the first number in that position; 
            printf(" %d", i); 
            int *ptrChecker = data[i].ptr; 

            while(ptrChecker != NULL){
                int num = *ptrChecker; 
                //printf(" |%d %d %d| ", num, data[num].prevPtr, data[num].ptr);//prints the block that was being pointed to. 
                printf(" %d", num); 
                ptrChecker = data[num].ptr; //updates the pointerChecker.
                
            }
        }
        if(i < size - 1) printf("\n"); 
    }
}

