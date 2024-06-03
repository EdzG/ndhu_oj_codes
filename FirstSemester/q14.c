#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
    int i, j, minIndex; 
  
    for (i = 0; i < n - 1; i++) { 
        // minimum num in the unsorted array
        minIndex = i; 
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; 
            }
        }
        // Swap the minimum and the first num in the array.
        swap(&arr[minIndex], &arr[i]); 
    } 
} 

int main()
{
    int N; 
    float truncNum = 0; 
    scanf("%d", &N); 
    int arr[N]; //creates an array N numbers (specified by the user)
    
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    
    selectionSort(arr, N);
    
    
    for (int i = 3; i < N-3; i++){
       
        truncNum += arr[i];
    }
    
    truncNum /= (N - 6);
    truncNum = round(truncNum * 100) / 100;
    printf("%0.2f",truncNum);
   


    return 0;
}