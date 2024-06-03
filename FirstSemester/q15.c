#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, counter = 0; 
    float avg; 
    scanf("%d", &N); 
    int arr[N]; //creates an array N numbers (specified by the user)
    
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
        avg += arr[i];
    }
    
    avg /= N;
     for (int i = 0; i < N; i++){
       if (arr[i] < avg){
           counter++;
       }
    }
    
    printf("%d\n", counter);
    
   


    return 0;
}