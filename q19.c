#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 1001

struct character{
    int val;
    int frequ;
};
 
int main() {
    
    
    
    char arr[MAX_LIMIT];
    struct character data[96] = {0}; //the amount of ascii char (ignoring first 32 and last 128)
    int startingValue = 32;
    int numOfChar = 96;
    int started = 0;

    
    //makes an array containing all the possible values a character can have. 
    for (int i = 0; i < numOfChar; i++){
        data[i].val = startingValue++;
    }
    
    
    
        while(fgets(arr, MAX_LIMIT, stdin)){
                
                //prints an empty line between the answers
                if(started)
                    printf("\n");
                
                if (strlen(arr) == 1) continue;
                
               //resets the frequency to 0
              for (int i = 0; i < numOfChar; i++){
                data[i].frequ = 0;
              }
            
            
            
            for (int i = 0; i < strlen(arr); i++){
                for (int j = 0; j < numOfChar; j++){
                    if (data[j].val == arr[i]){//goes through all the values until it finds the matching one
                        data[j].frequ++; //increments the value of the freq at the location of the matching
                        break; //already found the value of character and incremented the frequency
                    } 
    
                }
                
            }
           
            bool swapped;
           
            for (int i = 0; i < numOfChar - 1; i++) {
                swapped = false;
                for (int j = 0; j < numOfChar - i - 1; j++) {
                    if (data[j].frequ > data[j + 1].frequ) {
                        struct character temp;
                        temp = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = temp;
                        swapped = true;
                        
                    } else if (data[j].frequ == data[j+1].frequ){
                         if(data[j].val < data[j+1].val){
                        struct character temp;
                        temp = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = temp;
                        swapped = true;
                        
                        }
                    }
                }
         
                // If no two elements were swapped by inner loop,
                // then break
                if (swapped == false)
                    break;
            }
            
            
            //This works = prints the value and the frequency of the character
            for (int i = 0; i < numOfChar; i++){
                if (data[i].frequ != 0){
                    printf("%d %d\n", data[i].val, data[i].frequ);
                }
            }
            started =1;
    }
        
    
    
    return 0;
}