#include <iostream>

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
    public:
        Segment(Point p1, Point p2);
        Point getEnd(int n);
        double length();
};

class Path{
    public: 
        Path(Segment arr[], int n){
            Point start = arr[0].getEnd(0); 
            Point end = arr[0].getEnd(1); 
            double length = arr[0].length(); 
            for(int i = 1; i < n; i++){
                Point tempS = arr[i].getEnd(0); 
                if(end.getX() == tempS.getX() && end.getY() == tempS.getY()){
                    end = arr[i].getEnd(1); 
                    length += arr[i].length(); 
                } else {
                    
                    length = -1; 
                    break; 
                } 
            }
            if(length == -1) cout << length; 
            else {
                if(arr[n-1].getEnd(1).getX() == start.getX() && arr[n-1].getEnd(1).getY() == start.getY()) length = -1; 
                cout << length; 
            }

        }
};


int main(){

    return 0; 
}