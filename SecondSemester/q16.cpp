#include <iostream>
#include <string>

using namespace std; 

class Anagram : public string {
  private: 
    string input; 
  public:
    Anagram(string str){
        this->input = str; 
    }
    Anagram(){this->input = "";}
    bool operator==(const Anagram &str) const{
      //ascii values for Upper case 97-122
      //lower case 
      bool ans = true; 
      int firstString[26] = {0}, secondString[26] = {0}; 

      for(int i = 0; i < this->input.length(); i++){
        if(this->input[i] >=97 && this->input[i] <= 122){
          int chr = tolower(this->input[i]); 
          firstString[chr - 97] +=1; 
        }
      }
      for(int i = 0; i < str.input.length(); i++){
        if(str.input[i] >= 97 && str.input[i] <= 122){
          int chr = tolower(str.input[i]); 
          secondString[chr - 97] +=1; 
        }

      }
      for(int i = 0; i < 26; i++){
        if(firstString[i] != secondString[i]){
          ans = false; 
        }
      }

      return ans; 
  }

};

int main(){
    string buf;
    getline(cin, buf);
    Anagram a1(buf);
    getline(cin, buf);
    Anagram a2(buf);
    cout << (a1 == a2) << endl;
    cout << (a2 == a1) << endl;

    return 0; 
}