#include <iostream>

using namespace std; 

class Point {
    private:
        double x, y;
    public:
        Point (double x, double y){
            this->x = x; 
            this->y = y; 
        }
        double getX() {
            return x;
        }
        double getY() {
            return y;
        }
        void displayPoint(){
            cout << "(" << x << ", " << y << ")\n"; 
        }
    
};

int main(){

    int n = 0; 
    cin >> n;  
    double x = 0, y = 0; 
    while(n--){
        cin >> x >> y; 
        Point coord(x,y); 
        coord.displayPoint(); 
    }

    return 0;
}