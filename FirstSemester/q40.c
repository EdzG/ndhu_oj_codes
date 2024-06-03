#include <stdio.h>
#include <stdlib.h>

int main() {
  int *a, *b;
  init(&a, &b);
  int sum = 0;
  int *i = a;

  while( i < b){	 
        sum += *i; 
  		i += 1;
  }
  printf("%d", sum);
  return 0;
}