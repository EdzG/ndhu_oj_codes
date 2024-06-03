#include <iostream>

using namespace std;

int reverseNumber(int n){
    int d = 0; 
    while(n > 0){
        d = (d * 10) + (n % 10); 
        n/=10; 
    }
    return d; 
}

void reverseAndAdd(int& iterations, int& palindrome){
    for(int i = 1; i <= 1000 && palindrome < 4294967295; i++){
        int r = reverseNumber(palindrome); 
        palindrome += r; 
        iterations = i; 
        if(palindrome == reverseNumber(palindrome)) break; 
    }
}

int main(){
    int N = 0, iterations = 0, palindrome = 0; 
    cin >> N; 
    while(N--){
        cin >> palindrome; 
        reverseAndAdd(iterations, palindrome); 
        cout << iterations << " " << palindrome << endl; 
        iterations = 0; 
        palindrome = 0; 

    }
    return 0; 
}