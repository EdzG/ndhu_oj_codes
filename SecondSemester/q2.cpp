#include <iostream>
#include <cmath>

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
};

class Segment {
    Point start; 
    Point end; 

    public: 
        void setStart(Point _start){
            start = _start; 
        }
        void setEnd(Point _end){
            end = _end; 
        }

        Segment(){}; 
        Segment(Point start, Point end){
            setStart(start); 
            setEnd(end); 
        }

        double calcDistance(){
            double d = 0; 
            d = sqrt(pow(end.getX() - start.getX(), 2) + pow(end.getY() - start.getY(), 2));
            return d; 
        }
        void displayDistance(){
            cout << calcDistance() << "\n"; 
        }

};

int main(){

    int n = 0; 
    cin >> n; 
    Point start, end; 
    Segment seg; 
    while (n--){
        double x, y, x2, y2;  
        cin >> x >> y >> x2 >> y2; 
        start.setX(x); 
        start.setY(y); 
        end.setX(x2); 
        end.setY(y2); 
        seg.setStart(start); 
        seg.setEnd(end); 
        seg.displayDistance(); 

    }
    
    return 0; 
}