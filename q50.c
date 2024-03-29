char *convert(int dec, int base, char *result){
    char hex[] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        if(dec == 0){
            return result; 
        }
        int temp = dec % base; 
        int size = strlen(result); 
        char ans[size+2];
        ans[0] = hex[temp]; 
        ans[1] = '\0'; 
        strcat(ans, result); 
        strcpy(result, ans); 
        return convert(dec / base, base, result); 
}

char *convertToDifferentBase(int dec, int base, char *result) {
    result[0] = '\0'; 
    return convert(dec, base, result); 
}