#include <iostream>

using namespace std; 

class Point {
    double x, y;

    public:
    void setX(double _x) {
        x = _x;
    }
    void setY(double _y) {
        y = _y;
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
    Point coord; 
    double x = 0, y = 0; 
    while(n--){
        cin >> x >> y; 
        coord.setX(x); 
        coord.setY(y); 
        coord.displayPoint(); 
    }
    return 0; 
}