#include <iostream>

template < typename T > 
T *sort(T *array, int n){
    for(int i = 0; i < n - 1; i++){
        bool swapped = false; 
        for(int j = 0; j < n - i - 1; j++){
            if(array[j] > array[j+1]){
                T temp = array[j]; 
                array[j] = array[j + 1]; 
                array[j + 1] = temp; 
                swapped = true; 
            }
        }
        if(swapped == false) break; 
    }

    return array; 
}

int main(){

    int list[] = {1, 3, 2, 5, 0}; 
    sort<int>(list, 5); 
    for(int i = 0; i < 5; i++){
        std::cout << list[i] << " " << std::endl; 
    }

    return 0; 
}