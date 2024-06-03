#include <iostream>
#include <cmath>

using namespace std; 

class Segment{
    private:
        int start; 
        int end; 
    public: 
        void setStart(int start){
            this->start = start; 
        }
        void setEnd(int end){
            this->end = end; 
        }

        Segment(){}; 
        Segment(int start, int end){
            if(start < end){
                setStart(start); 
                setEnd(end); 
            } else {
                setStart(end);
                setEnd(start); 
            }
        }

        double calcDistance(){
            return end - start; 
        }
        void displayDistance(){
            cout << calcDistance() << "\n"; 
        }
};
int calcMin(int a, int b, int c, int d){
    int min = a; 
    if(b < min) min = b; 
    if (c < min) min = c; 
    if (d < min) min = d; 
    return min; 
}
int calcMax(int a, int b, int c, int d){
    int max = a; 
    if(b > max) max = b; 
    if (c > max) max = c; 
    if (d > max) max = d; 
    return max; 
}
int main(){

    int a, b, c, d, distance = 0; 
    cin >> a >> b >> c >> d; 
    Segment seg1(a,b), seg2(c,d), seg3(calcMin(a, b, c, d), calcMax(a, b, c, d)); 
    distance = seg1.calcDistance() + seg2.calcDistance(); 
    if(distance > seg3.calcDistance()){
        cout << "overlay"; 
    } else 
        cout << "no overlay"; 
    
    
    return 0; 
}