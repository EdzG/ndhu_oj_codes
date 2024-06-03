#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define size 8
#define size1 5

typedef struct{
    float x, y;
} Point; 
typedef struct {
    Point point; 
    float slope; 
} Line; 

float calcSlope(float x1, float y1, float x2, float y2){
    return (y2 - y1)/(x2 - x1); 
}

int main() {

    Line lineInfo; 
    Point pointInfo; 

    scanf("%f, %f, %f", &lineInfo.point.x, &lineInfo.point.y, &lineInfo.slope);
    scanf("%f, %f", &pointInfo.x, &pointInfo.y); 

    if(lineInfo.slope == calcSlope(pointInfo.x, pointInfo.y, lineInfo.point.x, lineInfo.point.y)){
        printf("Yes"); 
    } else if(lineInfo.slope == -calcSlope(pointInfo.x, pointInfo.y, lineInfo.point.x, lineInfo.point.y)){
        printf("Yes"); 
    }
    else printf("No"); 




    return 0; 
}