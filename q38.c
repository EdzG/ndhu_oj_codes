#include <string.h>
int main() {
  init();
  char *str = s1;
  char *key = s2;
  int count = 0;
  int size = strlen(key); 
  char arr[size]; 
  int lenght = strlen(str) - (size - 1); 
  for(int i = 0; i < lenght; i++){
    char *p = str + i; 
    	for(int j = 0; j < size; j++){
          arr[j] = *p; 
          p++; 
        }
    arr[size]='\0';
    if(strcmp(arr, key) == 0) count++; 
  }
  printf("%d", count);
  return 0;
}