#include <stdio.h>
#include <stdlib.h>

int isOdd(int num);
void sort(int *a,int *b);

int main(){

    int num1 = 0, num2 = 0, counter = 0, k = 0, max = 0, i = 0, j = 0; 

   while(scanf("%d %d", &num1, &num2) == 2){
        max = counter = 0; //assigns 0 to both counter and max
        //stores the original values for the two numbers. 
        i = num1; 
        j = num2; 
        
        sort(&num1, &num2);//sorts the numbers from smallest to biggest. 
        k = num2; //assigns the biggest number to k. 
        
        while(k >= num1){//runs the loop for all the values between num1 and num2
            while(1){
                counter++; 
                if(num2 == 1) break; 
                if(isOdd(num2)) 
                    num2 = (3 * num2) + 1; 
                else 
                    num2 /= 2; 
            }
        

            k -= 1;
            num2 = k; //changes the starting number
            if(max < counter) max = counter; //checks to see if the current number had the a greater cycle length
            counter = 0; 
        }
        printf("%d %d %d\n", i, j, max); 

    }

    return 0; 
}

//sorts two number from smallest to biggest
void sort(int *a,int *b)
{

    if(*a > *b){
        int tmp;
        tmp = *a; 
        *a=*b;    
        *b=tmp;   
    }
}

//checks to see if a number is odd
int isOdd(int num){

    if(num % 2 != 0) return 1; 
    else return 0; 
}
