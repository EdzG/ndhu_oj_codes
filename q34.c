#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct course{
    int sid;
    int student_id; 
    int course_id;
};
struct score{
    int sid;
    int score; 
};

int cmpfunc(const void* a, const void* b); 
int failedClass(struct score score_data[], int sid, int n);
int numOfClass_FailedOneStudent(struct course course_data[], struct score score_data[], int m, int n);

int main() {
    int m = 0, n = 0, count = 1; 
    scanf("%d %d", &m, &n); 
    struct course course_data[m]; 
    struct score score_data[n]; 

    //getting data
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &course_data[i].sid, &course_data[i].student_id, &course_data[i].course_id); 
    }
    for(int i = 0; i < n; i++){
        scanf("%d %d", &score_data[i].sid, &score_data[i].score); 
    }

    //sorting the data based on student id. 
    qsort(course_data, m, sizeof(course_data[0]), cmpfunc);
    
    //count how many students are in the table. 
    for(int i = 0; i < m - 1; i++){
        if(course_data[i].student_id != course_data[i+1].student_id){
            count++; 
        }
    }
    int failedClasses = numOfClass_FailedOneStudent(course_data, score_data, m, n); 
    printf("%d %d", count, failedClasses); 
    return 0; 
}

//returns the num of classes that had atleast one student that failed. 
int numOfClass_FailedOneStudent(struct course course_data[], struct score score_data[], int m, int n){
    int classFailed[m], count = 0, flag = 0; 
    memset(classFailed, -1, m*sizeof(classFailed[0])); //set classFailed array to -1; keeps tracked of the class with atleast one student failed. 
    for(int i = 0; i < m; i++){
        flag = 0; 
        for(int j = 0; j < m; j++){
            //checks to see if someone has already failed the class; if yes, ignore it
            if(course_data[i].course_id == classFailed[j]){
                flag = 1; 
            }
        }
        if(flag != 1){
            //if the student failed the class, add it to the array. 
            if(failedClass(score_data, course_data[i].sid ,n)){
                classFailed[i] = course_data[i].course_id; 
            }

        }
    }

    //count how many classes had atleast one student failing. 
    for(int i =0; i < m; i++){
        if(classFailed[i] != -1) count++; 
    }

    return count; 

}

//returns 1 if the student failed the class; 0 if passed. 
int failedClass(struct score score_data[], int sid, int n){
    double average = 0; 
    int count = 0; 
    for(int i = 0; i < n; i++){
        if(sid == score_data[i].sid){
            average += score_data[i].score; 
            count++; 
        }
    }
    average /= count; 
    if(average < 60) return 1; 
    else return 0; 
}

//compare function for qsort
int cmpfunc(const void* a, const void* b){
    struct course student1 = *(struct course*)a; 
    struct course student2 = *(struct course*)b; 
    return(student1.student_id-student2.student_id); 
}