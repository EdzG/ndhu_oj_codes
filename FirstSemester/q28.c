#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coordinate{
    int x;
    int y; 
};

double calcXCoordinate(struct coordinate data[], int height);
int cmpfunc(const void* a, const void* b);
double calcLength(struct coordinate data[], int y1, double x1);
int getNextCoord(struct coordinate data[], int height);

int coord; 

int main() {
    int numOfTestCase = 0, numOfCoord = 0;
    scanf("%d", &numOfTestCase); 
    

    while(numOfTestCase--){
        int height = 0; 
        double length = 0; 
        scanf("%d", &numOfCoord); 
        struct coordinate data[numOfCoord];
        coord = numOfCoord - 2; //start from the second to last coordinate
        for(int i = 0; i < numOfCoord; i++){
            scanf("%d %d", &data[i].x, &data[i].y); 
        }

        qsort(data, numOfCoord, sizeof(data[0]), cmpfunc);

        while(coord >= 0){
            if (coord == numOfCoord -2){
                length += calcLength(data, data[coord+1].y, data[coord+1].x);
                height = data[coord].y;
                //printf("%d this is the height\n", height);
            } 
            if(getNextCoord(data, height) == 1){
                double x = calcXCoordinate(data, height); 
                //printf("%f this is the x coordinate", x);
                length += calcLength(data, height, x); 
                
                height = data[coord].y; 

            } else break; //there is no higher peak

        }
        // length = round(length * 100) / 100;

        printf("%.2f\n", length); 

        // for(int i = numOfCoord - 2; i >= 0; i--){//start at the second to last coordinate
        //     printf("%d %d\n", data[i].x, data[i].y); 
        // }
    
    } 
   

    return 0;
}
//gives y1
int getNextCoord(struct coordinate data[], int height){
    for(int i =  coord; i >= 0; i--){
        if(data[i].y > height){
            coord = i; //gets the coord of the next hightest peak. 
            return 1; 
        }
    }
    return 0; 
}
//give x1
double calcXCoordinate(struct coordinate data[], int height){
    double slope, c, x; 
    int y2, y1, x2, x1; 
    y2 = data[coord].y; 
    y1 = data[coord+1].y;
    x2 = data[coord].x; 
    x1 = data[coord+1].x; 
    slope = (double)(y2 - y1)/(x2-x1); 
    c = (double)y2 - (slope * x2); 
    x = (double)(height - c)/slope; 
    
    return x;
}
//calculates the length; 
double calcLength(struct coordinate data[], int y1, double x1){
    int y2, x2;
    double a, b, c; 
    y2 = data[coord].y; 
    x2 = data[coord].x; 
    a = y2 - y1; 
    b = x2 - x1; 
    c = pow(a, 2) + pow(b, 2); 
    c = sqrt(c); 

    return c; 
}
int cmpfunc(const void* a, const void* b){
    struct coordinate coord1 = *(struct coordinate*)a; 
    struct coordinate coord2 = *(struct coordinate*)b; 
    return(coord1.x-coord2.x); 
}

