#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  init();
  char *str = s;
  int sum = 0, num = 0, length = 0; 
  char chr = '\0'; 
  length = strlen(str); 
  char *p = str; 

  while(length--){
    chr = *p; 
    if(isdigit(chr)){
        num = (num * 10) + (chr - '0'); 
        char temp = *(p + 1); 
        if(!isdigit(temp)){
            sum += num; 
            num = 0; 
        }
    }
    p++; 
    
  }

  printf("%d", sum);

  return 0;
}