#include <stdio.h>
#include <math.h>

int main()
{
    float num;
    
    scanf("%f", &num);
    printf("%0.2f\n", num);
    printf("%0.2f\n", num-0.005);

    return 0;
}
