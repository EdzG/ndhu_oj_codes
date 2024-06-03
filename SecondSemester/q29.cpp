#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std; 

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
        bool operator!=(Point &b){
            return !(x == b.x && y == b.y); 
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
        Point getStart(){return start;}
        Point getEnd(){return end;}
    private:
        Point start, end; 
};

class Shape {
    public:
        Shape(): edgeCount(0){}
        Shape(Segment *ptr, int _edgeCount){ // to construct a shape with a serial of segment. Throw an invalid_argument if the segment can not construct a close path.
           
            Point firstSeg = ptr[0].getStart(); 
            Point lastSeg = ptr[_edgeCount-1].getEnd(); 
            if(firstSeg != lastSeg)
                throw std::invalid_argument("something went wrong"); 
            this->edgeCount = _edgeCount; 
            for(size_t i = 0; i < _edgeCount; i++){
                seg[i] = ptr[i]; 
            }

        }
        virtual float getArea() = 0;
        double getPerimeter() {
            double perimeter = 0; 
            for(size_t i = 0; i < edgeCount; i++){
                perimeter += getSeg(i).getLength(); 
            }
            return perimeter; 
        }
        Segment &getSeg(int index)
        {
            return seg[index];
        }
    private:
        Segment seg[10];
        int edgeCount;
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