#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {

    char prevprevChr = '.'; //sets condition for the first letter of the first sentence to be capitalized!
    char prevChr = ' ', currChr = '\0'; //sets condition. 


    while ((currChr = getchar()) != EOF) { //runs until it reaches the end of the file. 
        
        if ((prevprevChr == '.' && prevChr == ' ') || (prevChr == '\n') || ( prevprevChr == '\n' && prevChr == '\"')){
            currChr = toupper(currChr); // Capitalize the current character
        }
     

        putchar(currChr); //Displays the character
        prevprevChr = prevChr; //Updates the previous previous character. 
        prevChr = currChr; // Update the previous character
       

            
        
    }

    return 0;
}