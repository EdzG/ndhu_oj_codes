#include <stdio.h>

int main()
{
    int num; 
    scanf("%d", &num);
    if( (num % 3 == 2) && (num % 7 == 5) && (num % 11 == 7)){
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
