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
        
        
       friend bool operator ==(const Fraction& frac, const Fraction& frac2);
       friend Fraction operator +(const Fraction& frac, const Fraction& frac2);
       friend Fraction operator -(const Fraction& frac, const Fraction& frac2);
        
    
};

void reduction(Fraction& frac){
    //get the signs
    int sign = (frac.getNumerator() < 0) ? -1 : 1;
    sign *= (frac.getDenominator() < 0)? -1 : 1; 
 
    //make values positive; 
    frac.setDenominator(abs(frac.getDenominator())); 
    frac.setNumerator(abs(frac.getNumerator())); 

    int min = (frac.getNumerator() > frac.getDenominator())? frac.getDenominator(): frac.getNumerator(); 
        for(int i = min; i >= 2; i--){
            if((frac.getNumerator() % i == 0) && (frac.getDenominator() % i == 0)){
                int deno = frac.getDenominator(); 
                int nume = frac.getNumerator(); 
                frac.setDenominator(deno/i);
                frac.setNumerator(nume/i); 
            }
        }
        sign *= frac.getNumerator(); 
        frac.setNumerator(sign); 
        if(frac.getNumerator() == 0) frac.setDenominator(1);
}

bool operator ==(const Fraction& frac, const Fraction& frac2){
    Fraction f1(frac.getNumerator(), frac.getDenominator()); 
    Fraction f2(frac2.getNumerator(), frac2.getDenominator()); 
    reduction(f1); 
    reduction(f2); 
    return (f1.getNumerator() == f2.getNumerator() && f1.getDenominator() == f2.getDenominator());
   
}

Fraction operator +(const Fraction& frac, const Fraction& frac2){
    int deno = (frac.getDenominator() == frac2.getDenominator())? frac.getDenominator(): frac.getDenominator() * frac2.getDenominator(); 
    int nume = (deno / frac.getDenominator()) * frac.getNumerator(); 
    nume += (deno / frac2.getDenominator()) * frac2.getNumerator(); 

    Fraction f1(nume, deno); 
    reduction(f1); 
    return f1; 
}

Fraction operator -(const Fraction& frac, const Fraction& frac2){
 
    int deno = (frac.getDenominator() == frac2.getDenominator())? frac.getDenominator(): frac.getDenominator() * frac2.getDenominator(); 
    int nume = (deno / frac.getDenominator()) * frac.getNumerator(); 
    nume -= (deno / frac2.getDenominator()) * frac2.getNumerator(); 
    Fraction f1(nume, deno); 
    reduction(f1);  
    return f1; 
}


int main(){

    int n1, n2, m1, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    Fraction f1(n1, m1), f2(n2, m2);
    cout << (f1 + f2) << endl;
    cout << (f1 - f2) << endl;
    cout << (f1 == f2) << endl;

    return 0; 
}
