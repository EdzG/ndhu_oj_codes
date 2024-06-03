/*******************************************
function name: replace
description: When mode is 1, replace the first target finded in source with the replacement.
             When mode is 2, replace left-most target by replacement until there are no targets in the source.
return value: Return the result after replace.
*******************************************/
char *replace(char *source, char *target, char *replacement, int mode) {
    if(mode == 1){
        rep(source, target, replacement); 
    } else if(mode == 2){
        while(1){
            int hasSubString = rep(source, target, replacement);
            if(hasSubString == 0) return source;  
        }
    }
    return source; 
}

int rep(char *source, char *target, char *rep){
    char *p = strstr(source, target); 
    if(p == NULL) return 0; //if there is no more instances of target in the source; 
    int size = strlen(source); 
    int sizeToBeReplaced = strlen(target) - strlen(rep); 
    char newStr[size + 1];
    int j = 0; 
    //copying the characters before the replacement; 
    for(char *i = source; i < p; i++){
        newStr[j] = source[j];  
        j++;
    }
    //copying the replacement to the newStr; 
    for(int i = 0; i < strlen(rep); i++){
        newStr[j] = rep[i]; 
        j++; 
    }
    int index = j + sizeToBeReplaced; 
    //copying the rest of the source str into newStr; 
    for(int i = index; i < strlen(source);i++){
        newStr[j] = source[i];
        j++;  
    }
    newStr[j] = '\0'; 
    for(int i = 0; i < strlen(source); i++){
        source[i] = newStr[i]; 
    }

    return 1; 
}
