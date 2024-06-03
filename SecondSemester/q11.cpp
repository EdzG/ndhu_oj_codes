#include <iostream>
#include <string>
#include <cctype>

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
    
    //default constructor will construct an Integer object with value 0.
    Integer();
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
  
};


int main()
{
  string in = "10kfdlaj"; 
  int j;
  cin >> in;
  Integer i(in);
  for(j = 2;j <= 16;j ++) {
    i.displayInBase(j);
    cout << endl;
  }

  return 0; 
}