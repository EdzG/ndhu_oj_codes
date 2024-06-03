#include <stdio.h>
#include <stdlib.h>

int main() {
  init();
  void *p = &block;
 	int a = *(int*)p;
  	p+=4; 
  	char b = *(char*)p; 
  	p+=1; 
  	float c = *(float*)p; 
  printf("%d, %c, %f",a, b, c);
  return 0;
}