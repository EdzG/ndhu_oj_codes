#include <iostream>
#include <string>
#include <cstring>

class Date 
{
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
    for (int y = 1900; y < year; y++ )
      days += 365 + isLeapYear(y);

    for (int m = 0; m < month - 1; m++){
      days += dayInMonth[m]; 
      if(m == 1 && isLeapYear(year)) days++; 
    }
    return days + day;
  }


  bool isLeapYear(int year){
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
  }

  int operator-( Date& other )
  {
    return abs(daysBeforeDate() - other.daysBeforeDate());
  }

};

int main() 
{
  std::string str = "1990/10/22"; 
  std::string str2 = "1994/06/22"; 

  Date obj(str), obj2(str2); 
  std::cout << (obj - obj2) << std::endl;

  return 0;
}

