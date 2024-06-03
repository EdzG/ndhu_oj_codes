#include <iostream>
#include <string>

using namespace std; 

class CheapestBase{
    private: 
        int cost[36]; 
        int testCase, cheapest; 
        int *ptr; 

    public:
        CheapestBase(){
            cheapest = 0; 
            for(int i = 0; i < 36; i++){
                cin >> cost[i]; 
                cheapest += cost[i]; 
            }
            testCase = 0; 
            ptr = new int[35];  
            for(int i = 0; i < 35; i++){
                ptr[i] = cheapest; 
            }
        }
        void setTestCase(int testCase){
            this->testCase = testCase;
            cheapest = 200000000;
            calculateCheapestBase(); 
            display();  
        }
        void calculateCheapestBase(){
            for(int i = 0; i < 35; i++){
                ptr[i] = calcCost(i+2); 
                if(ptr[i] < cheapest) cheapest = ptr[i]; 
            }
        }
        int calcCost(int base){
            int num = testCase; 
            int price = 0, remainder; 
            int leadingZero = 0; 
            while(num > 0){
                remainder = num % base; 
                num /= base; 
                if(remainder == 0){
                    leadingZero += cost[remainder]; 
                } else leadingZero = 0; 
                price += cost[remainder]; 
            }
            price -= leadingZero; 
            return price; 
        }
        void display(){
            cout << "Cheapest base(s) for number " << testCase << ":"; 
            for(int i = 0; i < 35; i++){
                if(ptr[i] == cheapest){
                    cout << " " << i + 2; 
                }
            }
            cout << endl; 
        }

};

int main(){
    int numOfTestCases = 0, amountOfNumbers = 0; 
    cin >> numOfTestCases; 
    int j = 1; 
    while(numOfTestCases--){
        cout << "Case " << j << ":" << endl; 
        j++; 
        CheapestBase obj; 
        cin >> amountOfNumbers; 
        for(int i = 0; i < amountOfNumbers; i++){
            int num = 0; 
            cin >> num; 
            obj.setTestCase(num); 
        }
        cout << endl; 
    }
    
    return 0; 
}