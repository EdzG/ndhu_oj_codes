#include <iostream>

class Max_length{
    public:
        Max_length(int i, int j): start(i), end(j){}
        int cycle_length(int num){
            int length = 1; 
            while(num != 1){
                length++; 
                if(num % 2 != 0) num = (3*num) + 1;
                else num /=2; 
            }
            return length; 
        }
        int max(){
            int maximum = 0; 
            int i = start < end ? start : end; 
            int j = start < end ? end : start; 
            while(j >= i){
                int length = cycle_length(j); 
                if(maximum < length) maximum = length; 
                j--; 
            }
            return maximum; 
        }
        void display(){
            std::cout << start << " " << end << " " << max(); 
        }

    private:
        int start; 
        int end; 
};

int main(){

    int i, j; 
    while(std::cin >> i >> j){
        Max_length obj(i, j); 
        obj.display(); 
        std::cout << std::endl; 
    }

    return 0; 
}