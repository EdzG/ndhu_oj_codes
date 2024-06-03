#include <stdio.h>
#include <math.h>

int main()
{
    int distance, price; 
    scanf("%d", &distance);
    
    if(distance > 200){
        int over;
        over = distance - 200;
        price = round((200 * 1.2) + (over * 1.2 * 0.75));
    } else {
        price = round(distance * 1.2); 
    }
    
    printf("%d", price);

    return 0;
}
