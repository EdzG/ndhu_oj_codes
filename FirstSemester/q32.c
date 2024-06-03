#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define direction 4

int searchPath(int size, int maze[size][size], int r, int c, int dir); 
int checkBounds(int size, int dir, int r, int c); 
int flag = 0; //every recursive functinon has access to this. 

int main(){
    int size = 0; 
    scanf("%d", &size); 
    int maze[size][size]; 

    for(int row = 0; row < size; row++){
        for (int col = 0; col < size; col++){
            scanf("%d", &maze[row][col]); 
        }
    }

    if(searchPath(size, maze, 0, 0, 0)) printf("Yes"); 
    else printf("No");  

    return 0; 
}

int checkBounds(int size, int dir, int r, int c){
    //checks to see if the directions the program wants to search is not out of bound. 
    //returns 1 if it is within bounds, else returns 0
    if(dir == 0){
        if(r > 0) return 1; 
        else return 0; 
    }
    if(dir == 1){
        if(r <= size - 2) return 1; 
        else return 0; 
    }
    if(dir == 2){
        if(c > 0) return 1; 
        else return 0; 
    }
    if(dir == 3){
        if(c <= size - 2) return 1;
        else return 0; 
    }
}

//returns 1 if it found the exit, else it returns 0
int searchPath(int size, int maze[size][size], int r, int c, int dir){
    //indexes meaning -> 0 - top, 1 -> bottom, 2 - left, 3 - right
    //0 means searched. 
    int arr[direction], i = 0, count = 0; 
    memset(arr, -1, direction*sizeof(arr[0])); 
    arr[dir] = 0; //set the direction where it came in as searched. 
  
 
    if(maze[r][c] == 1) return 0;
    
    if(r == size -1 && c == size -1){
        flag = 1; 
        return 1; 
    }

    if(flag == 1) return 1;

    if(maze[r][c] == -1) return 0; 
   

    for(i = 0; i < direction; i++){
        if(checkBounds(size, i, r, c) && arr[i] == -1){
            int d; 
            maze[r][c] = -1;
           if(i == 0){
                d = 1; //entering from the bottom because it will search up
                if(maze[r-1][c] != -1) searchPath(size, maze, r-1, c, d);
           } 
           if(i == 1) {
                d = 0; //entering from the top
                if(maze[r+1][c] != -1) searchPath(size, maze, r+1, c, d);
                
           }
           if(i == 2) {
                d = 3; //entering from the right side. 
                if(maze[r][c-1] != -1) searchPath(size, maze, r, c-1, d);
                
           }
           if(i == 3) {
                d = 2;//entering from the left.  
                if(maze[r][c+1] != -1) searchPath(size, maze, r, c+1, d);    
           }
          
           
        }
        arr[i] = 0; //set the direction as searched. 
    }

    for (int i = 0; i < direction; i++){
        if(arr[i] == 0) count++;
    }
    if(flag == 1) return flag; //checks to see if it had reached the end. 

    //if it checks all the direction and didn't reach the end, return 0 for failed. 
    if(count == direction) return 0; 
    else return 1; 
    
}