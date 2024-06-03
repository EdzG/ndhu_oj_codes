#include <iostream>
#include <cmath>

class Point {
    public:
        Point(){
            x = 0; 
            y = 0; 
        }
        Point(double _x, double _y): x(_x), y(_y){}
        void printPoint(){
            std::cout << "(" << x << ", " << y << ")"; 
        }
        void setX(double x) {this->x = x;}
        void setY(double y) {this->y = y;} 
        double getX() {return x;}
        double getY() {return y;}
        double getDistance(Point &a){
            double result = pow((a.x - x),2) + pow((a.y - y),2);
            return sqrt(result); 
        }
    private:
        double x, y; 
};

class Segment{
    public:
        Segment() :start(0, 0), end(0, 0) {}
        Segment(Point start, Point end) : start(start), end(end) {}
        double getLength() {
            return start.getDistance(end); 
        }
    private:
        Point start, end; 
};
int main(){
    Point p1(3.0f, 4.0f);
    Point p2(0.0f, 0.0f);
    p1.printPoint();
    p2.printPoint();
    std::cout << "Distance between p1 and p2: " << p1.getDistance(p2) << std::endl;

    // Test the Segment class
    Segment segment(p1, p2);
    std::cout << "Length of the segment: " << segment.getLength() << std::endl;

    return 0; 
}