#include <stdio.h>

int main() {
  
  //The representation of values in roman numeral. 
  char *romanNumeral[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
  //the value is equivalent to the roman numeral with the same index. 
  int arabicNumeral[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    int num;
    scanf("%d", &num);
    int i = 12; //starting with the largest roman numeral. 
    while (num > 0){
        //represents the number of times the loop will run (1 or 0)
        //Displays the largest roman numeral number that can go into the arabic num. 
        int div = num / arabicNumeral[i];
        
        //becomes the remainder as the biggest number has already been displayed.
        num %= arabicNumeral[i]; 
        
        for (int j = 0; j < div; j++){
            //displays the roman numerals representation from largest to smallest. 
            printf("%s", romanNumeral[i]);
        }
        i--; //decrements. 
    }
    return 0;
}