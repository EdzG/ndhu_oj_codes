#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    
    scanf("%d%d%d", &a, &b, &c);
    if ((a + b) > c ) {
     
        if (pow(a,2) + pow(b, 2) == pow(c, 2)){
        printf("right triangle");
        }else if (pow(a,2) + pow(b, 2) > pow(c, 2)){
        printf("acute triangle");
        } else if(pow(a,2) + pow(b, 2) < pow(c, 2)){
        printf("obtuse triangle");
        }
    }else {
        printf("can not construct");
    }
  
    return 0;
}
