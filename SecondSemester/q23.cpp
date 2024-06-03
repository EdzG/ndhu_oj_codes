#include <iostream>
#include <string>

class Time{
    private: 
        int hour, minute, second; 
    public: 
        Time():hour(0), minute(0), second(0){}
        Time(std::string str){
            hour = ((str[0] - '0') * 10) + (str[1] - '0'); 
            minute = ((str[3] - '0') * 10) + (str[4] - '0');
            second = ((str[6] - '0') * 10) + (str[7] - '0'); 
        }
        std::string toString() const{
            std::string str = {"00:00:00"}; 
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
class Date {
  private: 
    int year, month, day;
  public:
    Date(): year(1900), month(1), day(1){}
    Date(std::string str){
      year = 0; 
      for(int i = 0; i < 4; i++){
          year = (year * 10) + str[i] - '0'; 
      }
      month = ((str[5] - '0') * 10) + (str[6] - '0');
      day = ((str[8] - '0') * 10) + (str[9] - '0'); 
    }
    std::string toString() const{
      std::string str = {"1900/01/01"}; 
      if(year != 0){
          int temp = year; 
          for(int i = 3; i >= 0; i--){
              str[i] = (temp % 10) + '0'; 
              temp  /= 10; 
          }
      } 
      if(month != 0){
          str[5] = (month / 10) + '0'; 
          str[6] = (month % 10) + '0'; 
      }
      if(day != 0){
          str[8] = (day / 10) + '0'; 
          str[9] = (day % 10) + '0'; 
      }
      return str;     
    }

  int daysBeforeDate(){
    int dayInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    for (int i = 1900; i < year; i++ )
      days += 365 + isLeapYear(i);

    for (int i = 0; i < month - 1; i++){
      days += dayInMonth[i]; 
      if(i == 1 && isLeapYear(year)) days++; 
    }
    return days + day;
  }


  bool isLeapYear(int year){
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
  }

  int operator-( Date& obj )
  {
    return abs(daysBeforeDate() - obj.daysBeforeDate());
  }

};

class DateTime : public Time, public Date {
  private:
    std::string dateTime;
  public:
    DateTime() : Date("1900/01/01"), Time("00:00:00") {};
    DateTime(std::string str) : Date(str.substr(0, 10)), Time(str.substr(11)) {};
    std::string toString() {
      return Date::toString() + " " + Time::toString();
    }
};

int main() {
  return 0;
}

