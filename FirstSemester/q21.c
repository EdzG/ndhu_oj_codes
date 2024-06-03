#include <stdio.h>
#include <stdlib.h> 

int isPrime(int a);
int compare(int a, int b);


int main() {
     int n = 0;
     scanf("%d", &n);
     int arr[n];
     for (int i = 0; i < n; i++){
         scanf("%d", &arr[i]);
     }
     for (int i = 0; i < n; i++){
         for (int j = 0; j < n - i -1; j++){
             if(compare(arr[j], arr[j+1])==1){
                 int temp = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = temp;
             }
         }
     }
     
     for (int i = 0; i < n; i++){
         printf("%d ", arr[i]);
     }

    return 0;
}

int isPrime(int a){
    //If it is a prime return 1 for true.
    //If it is not a prime return 0 for false.
    int divisor;
    if (a <= 1)
        return 0;
    for (divisor = 2; divisor * divisor <= a; divisor++){
        if (a % divisor == 0)
            return 0;
    }
    return 1;
}

int compare(int a, int b){
    
    int aResult = isPrime(a); 
    int bResult = isPrime(b);
    if (aResult != bResult){
        if (aResult == 0 && bResult == 1) return 1; //swap a and b;;
        else return 0; //prime is already first. 
    }
    else if(aResult == 1 && bResult == 1){ //if both numbers are prime
        if(a < b) return 1; //bigger prime number comes first
        else return 0; //It is already in the correct order
        
    } else if (aResult == 0 && bResult == 0){
        if(a > b) return 1; //smaller non-prime comes first
        else return 0; //already in the correct order. 
        
    }
return 0;
    
}