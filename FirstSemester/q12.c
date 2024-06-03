#include <stdio.h>

int main()
{
    int num = 0, tester = 0;
    scanf("%d", &num);
    
    while (num != 0) {
        
    if(num % 10 == 4){ //gets the last digit in the number
    printf("Yes");
    tester = 1;
    break;
    }
    num /= 10; //removes the last digit from the number
  }
  
  if (!tester){
      printf("No");
  }
  
    return 0;
}