#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, d, temp;
    
    scanf("%d%d%d%d", &a, &b, &c, &d);
    
    //set the segments in order from smallest to largest
    if ( a > b){
        temp = a;
        a = b;
        b = temp;
    }
    if (c > d){
        temp = c;
        c = d;
        d = temp;
    }
    
    
    if (a < c){
        if(b > c){
            printf("overlay");
        }else {
            printf("no overlay");
        }
    } else {
        if (d > a){ // c d a b becomes the new order of segments so we check if d is greater than a for an overlay
            printf("overlay");
        }else {
            printf("no overlay");
        }
    }
    

  
    return 0;
}