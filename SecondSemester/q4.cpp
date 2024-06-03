#include <iostream>

using namespace std;

class Speed {
    private: 
        double distance; 
        double duration; 
    public:
        void setDistance(double distance){
            this->distance = distance; 
        }
        void setDuration(double duration){
            this->duration = duration; 
        }
        int getDistance(){
            return distance; 
        }
        int getDuration(){
            return duration; 
        }
        double calcSpeed(){
            return distance/duration; 
        }

        void displaySpeed(){
            cout << calcSpeed(); 
        }

        Speed(){
            //default constructor
        }
        Speed(double distance, double duration){
            setDistance(distance); 
            setDuration(duration); 
        }
};

int main(){
    double distance, duration; 
    cin >> distance >> duration; 
    Speed person(distance, duration); 
    person.displaySpeed(); 

    return 0; 
}