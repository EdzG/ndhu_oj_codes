#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

class Digit { // class Digit represent a digit in base 10
  private: 
    int digit;
  public:
    Digit(int d = 0) : digit(d % 10) {}
    void setDigit(int d) { digit = d % 10; }
    int getDigit() const {return digit;}
};

class Integer { //class Integer represent a poistive integer
  private: 
    Digit value[1000];
    int numOfDigits; 
    bool sign; 
  public:
  //construct an integer in base 10 using a string.
  //This constructor will convert the given string to integer if possible.
  //Otherwise it will convert the digit part in prefix of the given string.
    Integer(string n){
      int isNum = n.length(); 
      for(int i = 0; i < n.length(); i++){
        if(n[i] < 48 || n[i] > 57) {
          isNum = i; 
          break; 
        }
      }
      numOfDigits = isNum; 

      for(int i = 0; i < isNum; i++){
        value[i].setDigit(n[i]-'0'); 
      }
    }
    void setNumOfDigits(int num){numOfDigits = num;}
    
    //default constructor will construct an Integer object with value 0.
    Integer(){numOfDigits = 0; value[0].setDigit(0);}
    //Display the value in given base from 2 to 16.
    //Order of symbol as 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F.
    void displayInBase(int base) {//add (int base) const 
      char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; 
      int loopControl = 1; 
      int arr[numOfDigits] = {0}; 
      for(int i = 0; i < numOfDigits; i++){
        arr[i] = value[i].getDigit(); 
      }

      int j = 0; 
      char result[1000];
      while(loopControl){
        int ans = getRemainder(arr, base, loopControl); 
        result[j] = hex[ans]; 
        j++; 
      }
      result[j] = '\0'; 
      for(int i = j - 1; i >= 0; i--){
        cout << result[i]; 
      }

    }
    int getRemainder(int arr[], int base, int& loopControl){
      int temp = 0; 
      int num = 0; 
      loopControl = 0; 
      
      for(int i = 0; i < numOfDigits; i++){
          num = (temp * 10) + arr[i]; 
          temp = num % base; 
          arr[i] = num / base; 
          if(loopControl == 0) loopControl = num/base; 
      }
      
      return temp; 
    }

  Integer addition(const Integer &b){
        Integer a; 
        int remainder = 0; 
        if(b.numOfDigits > numOfDigits){
            a.numOfDigits = b.numOfDigits; 
            int j = numOfDigits - 1; 
            for(int i = b.numOfDigits - 1;i>= 0; i--){
                if(j>=0) remainder = value[j].getDigit() + b.value[i].getDigit() + remainder; 
                else remainder = b.value[i].getDigit() + remainder; 
                j--; 
                a.value[i].setDigit(remainder); 
                remainder /= 10; 
            }
        } else {
            a.numOfDigits = numOfDigits; 
            int j = b.numOfDigits - 1; 
            for(int i = numOfDigits - 1; i >= 0; i--){
                if(j >= 0) remainder = value[i].getDigit() + b.value[j].getDigit() + remainder; 
                else remainder = value[i].getDigit() + remainder; 
                j--; 
                a.value[i].setDigit(remainder); 
                remainder /= 10; 
            }
        }
        if(remainder > 0){
            for(int i = a.numOfDigits; i > 0; i--){
                int num = a.value[i-1].getDigit(); 
                a.value[i].setDigit(num); 
            }  
            a.value[0].setDigit(remainder); 
            a.setNumOfDigits(a.numOfDigits + 1); 
        }  

        return a; 

    }

    Integer subtraction(const Integer &b){
        //sign = 1 means negative; 
        Integer a; 
        int borrow = 0; 
        int leadingDigit = -1; //holds the index of the leading index; 
        int biggerNum = -1;  
        int bigger = 0; 
        if(numOfDigits == b.numOfDigits){
          for(int i = 0; i < numOfDigits; i++){
            if(value[i].getDigit() < b.value[i].getDigit()){
              biggerNum = 1; 
              break; 
            } else if(value[i].getDigit() > b.value[i].getDigit()){
              biggerNum = 0; 
              break; 
            }
          }
          if(biggerNum == -1) bigger = 1; 
        }
        if(numOfDigits > b.numOfDigits || biggerNum == 0){
          biggerNum = 0; 
          //cout << "it enter here" << endl; 
          //copy the current num into integer a; 
          a.numOfDigits = numOfDigits; 
          for(int b = 0; b < numOfDigits; b++){
            int num = value[b].getDigit(); 
            a.value[b].setDigit(num);
          }
          //subtracting
          int j = b.numOfDigits - 1; 
          for(int i = a.numOfDigits - 1; i >= 0; i--){
            int num = a.value[i].getDigit();
            if(j >= 0) num -= b.value[j].getDigit(); 
            j--; 
            //borrow from the previous number
            if(num < 0 && i > 0){
              num += 10; 
              int temp = a.value[i-1].getDigit() - 1; 
              a.value[i-1].setDigit(temp); 
            } else if(num < 0 && i == 0) {
              num = abs(num); 
              a.sign = 1; 
            }
            if(num > 0) leadingDigit = i; //gets leading number; 
            a.value[i].setDigit(num); 
          }
        } else {
          biggerNum = 1; 
          //copy the b into integer a; 
          a.numOfDigits = b.numOfDigits; 
          a.sign = 1; 
          for(int c = 0; c < b.numOfDigits; c++){
            int num = b.value[c].getDigit(); 
            a.value[c].setDigit(num);
          }
          //subtracting
          int j = numOfDigits - 1; 
          for(int i = a.numOfDigits - 1; i >= 0; i--){
            int num = a.value[i].getDigit();
            if(j >= 0) num -= value[j].getDigit(); 
            j--; 
            //borrow from the previous number
            if(num < 0 && i > 0){
              num += 10; 
              int temp = a.value[i-1].getDigit() - 1; 
              a.value[i-1].setDigit(temp); 
            } else if(num < 0 && i == 0) {
              num = abs(num);  
            }
            if(num > 0) leadingDigit = i; //gets leading number; 
            a.value[i].setDigit(num); 
          }
        }
        
        //remove leading zeros
        if(leadingDigit != 0){
          for(int i = 0; i < a.numOfDigits; i++){
            int num = a.value[i + leadingDigit].getDigit(); 
            a.value[i].setDigit(num); 
          }
          a.setNumOfDigits(a.numOfDigits - leadingDigit);
        }

        if(bigger){
          a.value[0].setDigit(0); 
          a.sign = 0; 
          a.setNumOfDigits(1); 
        } else if(biggerNum == 1) a.sign = -1; 
        else a.sign = 0; 

        return a; 
    }

    void display(){
        if(sign) cout << "-"; 
        for(int i = 0; i < numOfDigits; i++){
            cout << value[i].getDigit(); 
        }
    }
  
};


int main()
{
  string a, b;
  cin >> a >> b;
  Integer num1(a), num2(b);
  num1.addition(num2).display();
  cout << endl;
  num2.addition(num1).display();
  cout << endl;
  cout << a << "-" << b << endl; 
  num1.subtraction(num2).display();
  cout << endl;
  cout << b << "-" << a << endl; 
  num2.subtraction(num1).display();
  cout << endl;
  num1.subtraction(num1).display(); 
  cout << endl; 
  return 0; 
}