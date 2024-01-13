#include <stdio.h>
#include <string.h>

int main()
{
    int odd = 0, even = 0; 
    char a[1001];
    while (1) {
        scanf("%s", a);
        if (strcmp(a, "0") == 0)
            break;
        else {
            for (int i = 0; i < strlen(a); i++){
                if (i % 2 == 0 || i == 0){
                    even += a[i] - '0';
                    //printf("%d\n", even);
                }
                else {
                    odd += a[i] - '0';
                    //printf("%d\n", odd);
                }
                
            }
            if ( (even - odd) % 11 == 0){
                printf("%s is a multiple of 11.\n", a);
            }else {
                printf("%s is not a multiple of 11.\n", a);
            }
            
            even = 0;
            odd = 0;
        }
    }
    return 0;
}