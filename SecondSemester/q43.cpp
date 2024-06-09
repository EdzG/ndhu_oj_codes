#include <iostream>


class Gate
{
    public :
        Gate *input[2] ;
        virtual bool output() = 0;
  		void setValue(Gate *, int);
        void setValue(bool, int);
} ;

class TRUE : public Gate
{
    public :
        virtual bool output() { return 1;}
        void setValue(Gate *, int) {}
        void setValue(bool, int) {}
} ;

class FALSE : public Gate
{
    public :
        virtual bool output() { return 0 ; }
        void setValue(Gate *, int) {}
        void setValue(bool, int) {}
} ;

TRUE t;
FALSE f;

void Gate::setValue(bool val, int pin)
{
    if(val) this -> input[pin] = &t;
    else this -> input[pin] = &f;
}

void Gate::setValue(Gate *gate, int pin) {this -> input[pin] = gate;}

class NOT : public Gate
{
    public :
        virtual bool output() {return !(this -> input[0] -> output()) ; }
        void setValue(bool val, int pin = 0)
        {
        	if(val) this -> input[0] = &t ;
            else this -> input[0] = &f ;
        }
        void setValue(Gate* gate, int pin = 0) { this -> input[0] = gate ; }
} ;

class NAND : public Gate
{
    public :
        virtual bool output() { return !(this -> input[0] -> output()) || !(this -> input[1] -> output());}
};

class NOR : public Gate
{
    public :
        virtual bool output() { return !(this -> input[0] -> output()) && !(this -> input[1] -> output()) ; }
} ;

class AND : public Gate
{
    public :
        AND() : Gate() {
            component[0] = new NOT; 
            component[1] = new NAND; 
        }
        virtual bool output() {
            component[1] -> input[0] = this-> input[0]; 
            component[1] -> input[1] = this -> input[1]; 
            component[0] -> input[0] = component[1]; 
            return component[0] -> output(); 
        }
    private :
        Gate *component[2] ;
} ;

class OR : public Gate
{
    public :
        OR() : Gate() {
            component[0] = new NOT; 
            component[1] = new NOR; 
        }
        virtual bool output() {
            component[1]->input[0] = this->input[0]; 
            component[1]->input[1] = this->input[1]; 
            component[0]->input[0] = this->component[1]; 
            return component[0]->output(); 
        }
    private :
        Gate *component[2] ;
};

class XOR : public Gate
{
    public :
        XOR() : Gate() {
            component[0] = new NOT; 
            component[1] = new NOT;
            component[2] = new AND; 
            component[3] = new AND;  
            component[4] = new OR; 
        }
        virtual bool output() {

            //Not gates
            component[0]->input[0] = this->input[0]; 
            component[1]->input[0] = this->input[1]; 
            //and gates
            component[2]->input[0] = component[0]; 
            component[2]->input[1] = this->input[1]; 
            component[3]->input[0] = component[1];
            component[3]->input[1] = this->input[0]; 
            //or gate
            component[4]->input[0] = component[2]; 
            component[4]->input[1] = component[3]; 

            return component[4]->output(); 
        }
    private :
        Gate *component[5] ;
};

class Adder
{
    public :
        virtual void setValue(bool, int) = 0 ;
        virtual void setValue(Gate *, int) = 0 ;
        virtual Gate *sum() = 0 ;
        virtual Gate *carryOut() = 0 ;
};

class OneBitHalfAdder : public Adder
{
    public :
        OneBitHalfAdder() {
            component[0] = new XOR; 
            component[1] = new AND; 
        }

        virtual void setValue(bool val, int pin) {
          component[0] ->setValue(val,pin); 
          component[1]->setValue(val,pin); 
        }
        virtual void setValue(Gate *gate, int pin) {
            component[0]->setValue(gate, pin); 
            component[1]->setValue(gate, pin); 
        }
        virtual Gate *sum() {
            return component[0]; 
        }
        virtual Gate *carryOut() {
            return component[1]; 
        }
    private :
        Gate *component[2] ;
};

class OneBitFullAdder : public Adder
{
    public :
        OneBitFullAdder() {
            a[0] = new OneBitHalfAdder;
            a[1] = new OneBitHalfAdder; 
            carry = new OR; 
        }
        virtual void setValue(bool val, int pin) {
            if (pin < 2) {
                a[0]->setValue(val, pin);
            } else {
                a[1]->setValue(val, 1);
            }
            a[1]->setValue(a[0]->sum(), 0); 
        }
        virtual void setValue(Gate *gate, int pin) {
             if (pin < 2) {
                a[0]->setValue(gate, pin);
            } else {
                a[1]->setValue(gate, 1);
            }
             a[1]->setValue(a[0]->sum(), 0); 
        }
        virtual Gate *sum() {
            return a[1]->sum(); 
        }
        virtual Gate *carryOut() {
            carry->setValue(a[0]->carryOut(), 0); 
            carry->setValue(a[1]->carryOut(), 1); 
            return carry; 
        }
    private :
        Adder *a[2] ;
        Gate *carry ;
};


class Decoder
{
    public :
        virtual void setValue(bool, int) = 0 ;
        virtual void setValue(Gate *, int) = 0 ;
        virtual void setEnable(bool) = 0 ;
        virtual void setEnable(Gate *) = 0 ;
        virtual int output() = 0 ;
        virtual Gate *operator[](int) = 0 ;
    protected :
        Gate *enable ;
} ;

class Decoder2_4 : public Decoder
{
    public :
        Decoder2_4() : Decoder2_4(0) {}
        Decoder2_4(bool val)
        {
            if(val) this -> enable = &t ;
            else this -> enable = &f ;
            for(int i = 0 ; i < 2 ; i++)
                component[i] = new NOT ;
            for(int i = 2 ; i < 6 ; i++)
                component[i] = new AND ;
            for(int i = 0 ; i < 4 ; i++)
                enables[i] = new AND ;
        }
        virtual void setEnable(bool val)
        {
            if(val) this -> enable = &t ;
            else this -> enable = &f ;
        }
        virtual void setEnable(Gate *gate) { this -> enable = gate ; }
        virtual void setValue(Gate *gate, int i) { component[i % 2] -> input[0] = gate ; }
        virtual void setValue(bool val, int i)
        {
            if(val) component[i % 2] -> input[0] = &t ;
            else component[i % 2] -> input[0] = &f ;
        }
        virtual Gate *operator[](int n)
        {
            _out() ;
            switch(n)
            {
                case 0 : return enables[0] ;
                case 1 : return enables[1] ;
                case 2 : return enables[2] ;
                case 3 : return enables[3] ;
                default : return nullptr ;
            }
        }
        friend std::ostream &operator<<(std::ostream &out, Decoder2_4 dec)
        {
            for(int i = 3 ; i >= 0 ; i--)
                out << dec[i] -> output() << " " ;
            return out ;
        }
        virtual int output()
        {
            for(int i = 0 ; i < 4 ; i++)
                if(enables[i] -> output()) return i ;
        }
    private :
        Gate *component[6] ;
        Gate *enables[4] ;

        void _out()
        {
            component[2] -> input[0] = component[0] ;
            component[2] -> input[1] = component[1] ;

            component[3] -> input[0] = component[0] -> input[0] ;
            component[3] -> input[1] = component[1] ;

            component[4] -> input[0] = component[0] ;
            component[4] -> input[1] = component[1] -> input[0] ;

            component[5] -> input[0] = component[0] -> input[0] ;
            component[5] -> input[1] = component[1] -> input[0] ;

            for(int i = 0 ; i < 4 ; i++)
            {
                enables[i] -> input[0] = this -> enable ;
                enables[i] -> input[1] = component[i + 2] ;
            }
        }
} ;

class Decoder4_16 : public Decoder
{
    public :
        Decoder4_16() {}
        Decoder4_16(bool val) {}
        virtual void setEnable(bool val) {}
        virtual void setEnable(Gate *gate) {}
        virtual void setValue(bool val, int pin) {}
        virtual void setValue(Gate *gate, int pin) {}
        virtual Gate *operator[](int n) {}
        friend std::ostream &operator<<(std::ostream &out, Decoder4_16 dec) {}
        int output() {}
    private :
        Decoder *dec2_4[5] ;
} ;



int main(){

    AND andGate;
    OR orGate;
    XOR xorGate;
    // NOT notGate;

    andGate.setValue(true, 0);
    andGate.setValue(true, 1);
    std::cout << "AND Gate: " << andGate.output() << std::endl;

    orGate.setValue(false, 0);
    orGate.setValue(false, 1);
    std::cout << "OR Gate: " << orGate.output() << std::endl;

    xorGate.setValue(false, 0);
    xorGate.setValue(true, 1);
    std::cout << "XOR Gate: " << xorGate.output() << std::endl;

    OneBitHalfAdder halfAdder;
    halfAdder.setValue(true, 0);
    halfAdder.setValue(false, 1);
    std::cout << "Half Adder Sum: " << halfAdder.sum()->output() << std::endl;
    std::cout << "Half Adder Carry Out: " << halfAdder.carryOut()->output() << std::endl;

    OneBitFullAdder fullAdder;
    fullAdder.setValue(true, 0);
    fullAdder.setValue(false, 1);
    fullAdder.setValue(true, 2); // Set the carry-in
    std::cout << "Full Adder Sum: " << fullAdder.sum()->output() << std::endl;
    std::cout << "Full Adder Carry Out: " << fullAdder.carryOut()->output() << std::endl;

    return 0; 
}