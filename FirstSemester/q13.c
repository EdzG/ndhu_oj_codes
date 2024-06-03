#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N; 
    float avg, deviation; 
    scanf("%d", &N); 
    int arr[N]; //creates an array N numbers (specified by the user)
    
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
        avg += arr[i]; //used to calc avg (u)
    }
    
    avg /= N; 
   
    for (int i = 0; i < N; i++){
       
        deviation += pow(arr[i] - avg, 2); //sumation of the square of the data points minus the average
    }
    deviation = sqrt(deviation/N); 
    
    printf("%0.2f", deviation);
    


    return 0;
}
