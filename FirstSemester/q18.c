#include <stdbool.h>
#include <stdio.h>
 
int main() {
    
    int counter, n;
    scanf("%d", &n);
    
    while(n--) {
        int length;
        scanf("%d", &length);
   
        int arr[length];
        
      for (int i = 0; i < length; i++){ 
          scanf("%d", &arr[i]);
      }
    
        bool swapped;
        counter = 0;
        for (int i = 0; i < length - 1; i++) {
            swapped = false;
            for (int j = 0; j < length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp;
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                    counter++;
                }
            }
     
            // If no two elements were swapped by inner loop,
            // then break
            if (swapped == false)
                break;
        }
        
         printf("Optimal train swapping takes %d swaps.\n", counter);
        

    }
    
    
    return 0;
}