#include <stdio.h>

int main(){
  float num1, num2, num3;
  float average;
  scanf("%f %f %f", &num1, &num2, &num3);
  
  average = (num1 + num2 + num3) / 3; 
  printf("%f", average);
 return 0; 
}