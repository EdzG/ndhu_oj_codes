#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOP 3 
#define size 20

typedef struct {
  char studentID[20];
  int programming, programmingLab, calculus;
} Student;

int cmpfunc(const void* a, const void* b);

int main(){

    int n = 0, score[TOP] = {}, totalScore = 0; 
    char first[size], second[size], third[size]; 
    scanf("%d", &n);
    Student data[n]; 

    for(int i = 0; i < n; i++){
        scanf("%s %d %d %d", &data[i].studentID, &data[i].programming, &data[i].programmingLab, &data[i].calculus); 
    }
    //sort it in descending order based on the totalScore
     qsort(data, n, sizeof(data[0]), cmpfunc);

    for(int i = 0; i < n; i++){
        totalScore = data[i].programming + data[i].programmingLab + data[i].calculus;
            if(totalScore > score[0]){
                score[0] = totalScore; 
                strcpy(first, data[i].studentID); 
            } else if(totalScore > score[1]){
                score[1] = totalScore; 
                strcpy(second, data[i].studentID);
            } else if(totalScore > score[2]){
                score[2] = totalScore;
                strcpy(third, data[i].studentID);
            }
        
    }
 
    printf("%s\n%s\n%s", first, second, third); 

    return 0; 
}


//compare function for qsort
int cmpfunc(const void* a, const void* b){
    Student student1 = *(Student*)a; 
    Student student2 = *(Student*)b; 
    int totalScore1 = student1.programming + student1.programmingLab + student1.calculus;
    int totalScore2 = student2.programming + student2.programmingLab + student2.calculus;
    return (totalScore2 - totalScore1); 
}