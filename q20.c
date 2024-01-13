#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int main() {

    int num;
    while(scanf("%d", &num) == 1){

        int mid = 0, mid2 = 0, counter = 0;
        int arr[num];

        //gets the data from the user
        for(int i = 0; i < num; i++){
            scanf("%d", &arr[i]);
        }

        qsort(arr, num, sizeof(int), compare);

        mid = arr[(num - 1)/2];
        mid2 = arr[num/2];


        //records the number of time the min value was produced
        for (int i = 0; i < num; i++){
            if (mid == arr[i] || mid2 == arr[i]){
                counter++;
            }
        }


        printf("%d %d %d\n", mid, counter, mid2 - mid + 1);

     }


    return 0;
}