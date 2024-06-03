#include <iostream>

using namespace std;

class LicensePlate{
    private: 
        int num; 
    public: 
        LicensePlate(int num){this->num = num;}
        void checkLicensePlate(){
            int temp = num; 
            int flag = 0; 
            while(temp){
                if(temp%10 == 4){
                    cout << "Yes"; 
                    flag = 1; 
                    break; 
                } else temp/=10; 
            }
            if(!flag) cout << "No"; 
        }
};

int main(){
    int num; 
    cin >> num; 
    LicensePlate obj(num); 
    obj.checkLicensePlate(); 
    return 0; 
}