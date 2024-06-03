#include <stdio.h>
#include <stdbool.h> 
#include <string.h> 
#include <stdlib.h>

int compare(int a, int b, int m);

int main() {
    
    int n = 0, m = 0; 

    
    while (scanf("%d%d", &n, &m)){
        
        
        if( n == 0 && m == 0) break; //ends the loop
        
        int arr[n];
        
        //getting the data
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        
        //sorting the data according to their modulos. 
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n - i - 1; j++){
                if(compare(arr[j], arr[j+1], m) == 1){
                    int temp;
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        
        printf("%d %d\n", n, m); 
        for (int i = 0; i < n; i++){
            printf("%d\n", arr[i]);
        }
        
    }
    
    printf("0 0");
    

    return 0;
}


int compare(int a, int b, int m){
    //a is the first num, b is the second num in the array
    // int aMod = abs(a) % m;
     //int bMod = abs(b) % m;
    int aMod = a % m; 
    int bMod = b % m;
    if(aMod > bMod) return 1; //swap a and b;
    if(aMod == bMod){
        if(abs(a)%2 != abs(b)%2){
            if (b%2 != 0) //means the second num is odd -> swap
                return 1;
            else 
                return 0; 
        }
        if (a%2 != 0 && b%2 != 0){
            if(a < b)
                return 1;
            else 
                return 0;
            
        }
        if(a%2 == 0 && b%2 == 0){
            if(a > b)
                return 1;
            else 
                return 0;
        }
    }
    if(aMod < bMod) return 0;
return 0;
    
}