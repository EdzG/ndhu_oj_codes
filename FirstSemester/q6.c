#include <stdio.h>

int main()
{
    int num = 0, ans = 0, temp;
    scanf("%d", &num);
    
    while (num != 0) {
        
    temp = num % 10; //gets the last digit in the number
    printf("%d", temp);
    num /= 10; //removes the last digit from the number
  }
  

  
  
    return 0;
}
