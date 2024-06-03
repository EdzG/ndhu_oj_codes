#include <iostream>
#include <string>
#include <cmath>

using namespace std; 

class Time{
    private: 
        int hour, minute, second; 
    public: 
        Time():hour(0), minute(0), second(0){}
        Time(string str){
            hour = ((str[0] - '0') * 10) + (str[1] - '0'); 
            minute = ((str[3] - '0') * 10) + (str[4] - '0');
            second = ((str[6] - '0') * 10) + (str[7] - '0'); 
        }
        string toString() const{
            string str = {"00:00:00"}; 
            if(hour != 0){
                str[0] = (hour / 10) + '0'; 
                str[1] = (hour % 10) + '0';
            } 
            if(minute != 0){
                str[3] = (minute / 10) + '0'; 
                str[4] = (minute % 10) + '0'; 
            }
            if(second != 0){
                str[6] = (second / 10) + '0'; 
                str[7] = (second % 10) + '0'; 
            }
        return str; 

        }
        int operator -(const Time& obj) const{
            int timeInSec = (hour * 3600) + (minute * 60) + second; 
            int timeInSec2 = (obj.hour * 3600) + (obj.minute * 60)  + obj.second; 
            return abs(timeInSec - timeInSec2); 
        }

};

int main(){

    string str = {"00:08:43"}; 
    string str2 = {"18:22:52"};

    Time obj(str), obj2(str2); 
    cout << obj - obj2 << endl; 

    string something = obj.toString(); 
    cout << something << endl; 

    return 0; 
}