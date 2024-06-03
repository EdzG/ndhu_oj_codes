#include <iostream>
#include <string>

using namespace std; 

class ObjectCodeFormat{
    private: 
        string type, imm; 
        int rd, rs, rt;
        static string t0, t1, t2, t3, t4, t5, t6, t7;
    public: 
        ObjectCodeFormat(string type, string r1, string r2, string r3){
            this->type = type; 
            rd = r1[2] - '0';
            rs = r2[2] - '0'; 
            rt = r3[2] - '0'; 
            //cout << rd << " " << rs << " " << rt << endl; 
            cout << "000000" << getRegister(rs) << getRegister(rt) << getRegister(rd) << "00000"; 
            if(this->type == "add"){
                cout << "100000"; 
            } else if(this->type == "sub"){
                cout << "100010";
            }else if(this->type == "or"){
                cout << "100101"; 
            }else{
                cout << "100100"; 
            }
        }
        ObjectCodeFormat(string type, string r1, string r2, int imm){
            int numOfBit; 
            rt = r1[2] - '0'; 
            rs = r2[2] - '0'; 
            this->imm = toBinary(imm, numOfBit);
            cout << "001000" << getRegister(rs) << getRegister(rt); 
            for(int i = 0; i < 16-numOfBit; i++){
                cout << "0"; 
            }
            cout << this->imm; 
        }
        ObjectCodeFormat(); 
        string getRegister(int num){
            if(num == 0) return t0; 
            else if(num == 1) return t1; 
            else if(num == 2) return t2; 
            else if(num == 3) return t3; 
            else if(num == 4) return t4;
            else if(num == 5) return t5; 
            else if(num == 6) return t6; 
            else if(num == 7) return t7; 
            else return ""; 
        }
        string toBinary(int num, int& numOfBit){
            char bin[17];
            int i = 0; 
            while(num > 0){
                bin[i] = (num % 2) + '0'; 
                i++; 
                num /= 2; 
            }
            bin[i] = '\0'; 
            numOfBit = i; 
            char ans[i]; 
            for(int j = 0; j < numOfBit; j++){
                ans[j] = bin[i-1]; 
                i--; 
            }
            ans[numOfBit] = '\0';
            return ans; 
        }
};
string ObjectCodeFormat::t0 = "01000"; 
string ObjectCodeFormat::t1 = "01001"; 
string ObjectCodeFormat::t2 = "01010"; 
string ObjectCodeFormat::t3 = "01011"; 
string ObjectCodeFormat::t4 = "01100"; 
string ObjectCodeFormat::t5 = "01101"; 
string ObjectCodeFormat::t6 = "01110"; 
string ObjectCodeFormat::t7 = "01111"; 




int main(){

string type, r1, r2, r3; 
int imm; 

while(cin >> type){ 
    if(type == "addi"){
        cin >> r1 >> r2 >> imm; 
        ObjectCodeFormat obj(type, r1, r2, imm); 
        cout << endl; 

    } else {
        cin >> r1 >> r2 >> r3; 
        ObjectCodeFormat obj(type, r1, r2, r3); 
        cout << endl; 
    }
}
    return 0; 
}