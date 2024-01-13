#include <stdio.h>

int main(){
  int integer;
  float floatNum;
  char character;
  
  scanf("%d %f %c", &integer, &floatNum, &character);
  
  printf( "%d\n", integer);
  printf( "%f\n", floatNum);
  printf( "%c\n", character);
  
  return 0;
}