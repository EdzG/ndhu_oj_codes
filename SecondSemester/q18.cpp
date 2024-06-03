#include <iostream>
#include <cmath>

using namespace std; 

class Fraction {
    private:
        int numerator, denominator;
    public:
        Fraction() : numerator(0), denominator(1) {}
        Fraction(int n, int m) : numerator(n) {
            if(m == 0)
            throw "divided by zero";
            denominator = m;
        }
        int getNumerator() const {
            return numerator;
        }
        int getDenominator() const {
            return denominator;
        }
        void setNumerator(int n) {
            numerator = n;
        }
        void setDenominator(int m) {
            if(m == 0)
            throw "divided by zero";
            denominator = m;
        }
        friend std::ostream& operator << (std::ostream& out, const Fraction &f) {
            if (f.denominator != 1)
                out << "[" << f.numerator << "/" << f.denominator << "]";
            else
                out << f.numerator;
            return out;
        }

         Fraction operator -(const Fraction& frac){
            int deno = 0; 
            int nume = 0; 
            deno = (denominator == frac.denominator)? denominator: denominator * frac.denominator; 
            nume = (deno / denominator) * numerator; 
            nume -= (deno / frac.denominator) * frac.numerator; 
            Fraction f1(nume, deno); 
            f1.reduction(); 
            return f1; 
        }
        Fraction operator +(const Fraction& frac){
            int deno = 0; 
            int nume = 0; 
            deno = (denominator == frac.denominator)? denominator: denominator * frac.denominator; 
            nume = (deno / denominator) * numerator; 
            nume += (deno / frac.denominator) * frac.numerator; 

            Fraction f1(nume, deno); 
            f1.reduction(); 
            return f1; 
        }

        void reduction(){
            int sign = (numerator < 0)? -1: 1; 
            sign *= (denominator < 0)? -1: 1; 
            numerator = abs(numerator); 
            denominator = abs(denominator); 
            int min = (numerator > denominator)? denominator: numerator; 
                for(int i = min; i >= 2; i--){
                    if((numerator % i == 0) && (denominator % i == 0)){
                        numerator /= i; 
                        denominator /= i; 
                    }
                }
            numerator *= sign; 
            if(numerator == 0) denominator = 1; 
        }


        bool operator ==(const Fraction& frac){
            Fraction f1(frac.numerator, frac.denominator); 
            Fraction f2(numerator, denominator); 
            f1.reduction(); 
            f2.reduction(); 
            return (f1.numerator == f2.numerator && f1.denominator == f2.denominator); 

        }

        Fraction operator *(const Fraction& frac){
            int nume = numerator * frac.numerator; 
            int deno = denominator * frac.denominator; 
            Fraction f1(nume, deno); 
            f1.reduction(); 
            return f1; 
        }

        Fraction operator /(const Fraction& frac){ //possibility of dividing by zero?
            int nume = frac.denominator; 
            int deno = frac.numerator; 
            Fraction f1(nume, deno); 
            Fraction f2(numerator, denominator); 
            return (f1 * f2); 
        }

        void operator =(const Fraction& frac){
            numerator = frac.numerator; 
            denominator = frac.denominator; 
            reduction(); 
        }

        void display(){
            reduction(); 
            if(denominator != 1) cout << "(" << numerator << "/" << denominator << ")" << endl; 
            else cout << "(" << numerator << ")" << endl; 

        }
};


int main(){

    Fraction a(1,2), b(1,2), c(1,2), d(1,2), e(1,2), f(1,2); 

    a = (((b + c) - d) * e)/f; 
    cout << a << endl; 
    Fraction g(10,8); 
    g.display(); 

    return 0; 
}