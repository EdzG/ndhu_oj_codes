#include <stdio.h>

int main() {
 
    unsigned int num; //large enough to hold the value
    int arr[50]; //will store the binary answer
    scanf("%u", &num);
    int i = 0;
    while (num != 0){ //the loop runs until the num becomes 0
        arr[i] = num % 2; //gets the remainder when the num is divided by 2
        num /= 2; //changes num to its correct value after dividing by 2
        i++;
    }
    for (int j = i - 1; j >= 0; j--){ 
        //displays the binary answer.
        //The answer is in reverse so we start from the highest index first.
        printf("%d", arr[j]);
    }
    
    return 0;
}