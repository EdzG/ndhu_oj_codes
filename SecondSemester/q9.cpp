#include <iostream>
#include <cmath>

using namespace std; 

class Toll{
    private:
        int distance;
    public:
        Toll(int d){
            distance = d; 
        }
        int calcToll(){
            if(distance <= 200){
                return round(distance * 1.2); 
            } else{
                return round((200 * 1.2) + ((distance - 200) * 1.2 * 0.75));
            }
        }
        void printToll(){
            cout << calcToll(); 
        }

};

int main(){
    int distance; 
    cin >> distance; 
    Toll obj(distance); 
    obj.printToll(); 

    return 0; 
}