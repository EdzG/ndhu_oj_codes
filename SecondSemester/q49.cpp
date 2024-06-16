#include <iostream>

class Number_classifier{
    public:
        Number_classifier(int _num) : num(_num){}
        bool isPrime(){
            int divisor;
            if (num <= 1)
                return 0;
            for (divisor = 2; divisor * divisor <= num; divisor++){
                if (num % divisor == 0)
                    return false;
            }
            return true;
        }
        bool isPrime(int _num){
            int divisor;
            if (_num <= 1)
                return 0;
            for (divisor = 2; divisor * divisor <= _num; divisor++){
                if (_num % divisor == 0)
                    return false;
            }
            return true;
        }
        int reverseNum(){
            int reversed_number = 0, n = num; 
            while(n){
                reversed_number = reversed_number * 10 + n%10; 
                n/=10;
            }
            return reversed_number; 
        }
        
        void display(){
            std::cout << num << " is "; 
            if(!isPrime()) std::cout << "not prime.";
            else {
                int reverse = reverseNum(); 
                if(isPrime(reverse) && reverse != num) std::cout << "emirp.";
                else std::cout << "prime.";
            }
        }

    private:
        int num; 
};

int main(){
    int num; 
    while(std::cin >> num){
        Number_classifier obj(num); 
        obj.display(); 
        std::cout << std::endl; 
    }

    return 0; 
}