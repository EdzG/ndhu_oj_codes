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
//   Point(double x, double y){
//     setX(x); 
//     setY(y); 
//   }
};

class Triangle {
    private: 
        Point pt1; 
        Point pt2; 
        Point pt3; 
    public: 
        void setPt1(Point pt1){
            this->pt1 = pt1; 
        }
        void setPt2(Point pt2) {
            this->pt2 = pt2; 
        }
        void setPt3(Point pt3) {
            this->pt3 = pt3; 
        }

        Triangle(Point pt1, Point pt2, Point pt3) {
            setPt1(pt1); 
            setPt2(pt2); 
            setPt3(pt3); 
        } 
        
        double calcPerimeter(){
            double d1 = 0, d2 = 0, d3 = 0;  
            d1 = sqrt(pow(pt1.getX() - pt2.getX(), 2) + pow(pt1.getY() - pt2.getY(), 2));
            d2 = sqrt(pow(pt2.getX() - pt3.getX(), 2) + pow(pt2.getY() - pt3.getY(), 2));
            d3 = sqrt(pow(pt1.getX() - pt3.getX(), 2) + pow(pt1.getY() - pt3.getY(), 2));
            return d1 + d2 + d3; 
        }

        void displayPerimeter(){
            cout << calcPerimeter() << "\n"; 
        }
  
};
int main() {
    int n = 0; 
    cin >> n; 
    Point pt1, pt2, pt3; 
    while (n--){
        double x = 0, y = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0; 
        cin >> x >> y >> x2 >> y2 >> x3 >> y3;
        pt1.setX(x);
        pt1.setY(y);
        pt2.setX(x2);
        pt2.setY(y2);
        pt3.setX(x3);
        pt3.setY(y3);
        Triangle triag(pt1, pt2, pt3); 
        triag.displayPerimeter(); 
    }

  return 0;
}
