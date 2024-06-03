#include <iostream>
#include <cmath>

using namespace std; 

  class Point {
    public:
        Point(double _x, double _y){
            x = _x; 
            y = _y; 
        }

        double getX() {return x;}
        double getY() {return y;}
    private:
        double x, y;
  };

  class Segment {
    private: 
        Point start;
        Point end;
    public: 
        Segment(Point start, Point end): start(start), end(end){};

        double length(){
            double d = 0; 
            d = sqrt(pow(end.getX() - start.getX(), 2) + pow(end.getY() - start.getY(), 2));
            return d; 
        }
        Point getEnd(int a){
            return (a == 0)?start:end; 
        }
        void displayDistance(){
            cout << length() << "\n"; 
        }

};

int main(){

    return 0; 
}