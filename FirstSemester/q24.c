#include <stdio.h>
#include <string.h>

int main() {
    
    int maxLength = 0, start = 0, startIdx = 0, endIdx = 0;
    char str[1000];
    int charIndex[256];//There are 256 possible characters
    //used to store the last index each character appeared.
    for (int i = 0; i < 256; i++) {
        charIndex[i] = -1;//initalized all the possible characters to -1(because 0 is an index)
        
    }
    scanf("%s", str); //getting the string from the user

    for (int end = 0; end < strlen(str); end++) {
        //checks if the current character has appeared after or at the same position as the start index of the current substring.
        if (charIndex[str[end]] >= start) {
            //updates the start index if the current character is already in the substring
            start = charIndex[str[end]] + 1;
        }
        //updating the last index of the current character; 
        charIndex[str[end]] = end;

        //checks to see if the current unique substring is the longest
        if (end - start + 1 > maxLength) { 
            maxLength = end - start + 1; //updates the max length
            //saves the start and end indexes of the longest substring. 
            startIdx = start; 
            endIdx = end; 
        }
    }

    for (int i = startIdx; i <= endIdx; i++) {
        printf("%c", str[i]);//printing each character from the longest unique substring. 
    }
    

    return 0;
}
