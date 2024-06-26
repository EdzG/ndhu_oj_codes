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
} ;

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
} ;
/* Reference example
class XNOR : public Gate
{
    public :
        XNOR() : Gate()
        {
            component[0] = new NOT ;
            component[1] = new XOR ;
        }
        virtual bool output()
        {
            component[1] -> input[0] = this -> input[0] ;
            component[1] -> input[1] = this -> input[1] ;
            component[0] -> input[0] = component[1] ;
            return component[0] -> output() ;
        }
    private :
        Gate *component[2] ;
} ;
*/

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

    // notGate.setValue(true, 0);
    // std::cout << "NOT Gate: " << notGate.output() << std::endl;

    return 0; 
}