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


class Mux
{
    public :
        virtual void setData(bool, int) = 0 ;
        virtual void setData(Gate *, int) = 0 ;
        virtual void setSelect(bool, int) = 0 ;
        virtual void setSelect(Gate *, int) = 0 ;
        virtual void setEnable(bool) = 0 ;
        virtual void setEnable(Gate *) = 0 ;
        virtual Gate *output() = 0 ;
    protected :
        Gate *enable ;
} ;

class Mux2_1 : public Mux
{
    public :
        Mux2_1() : Mux2_1(0) {}
        Mux2_1(bool val)
        {
            if(val) this -> enable = &t ;
            else this -> enable = &f ;
            component[0] = new AND ;
            component[1] = new AND ;
            component[2] = new NOT ;
            component[3] = new OR ;
            component[4] = new AND ;
        }
        virtual void setData(bool val, int pin)
        {
            switch(pin)
            {
                case 0 : component[0] -> setValue(val, 0) ; break ;
                case 1 : component[1] -> setValue(val, 0) ; break ;
                default : ;
            }
        }
        virtual void setData(Gate *gate, int pin)
        {
            switch(pin)
            {
                case 0 : component[0] -> setValue(gate, 0) ; break ;
                case 1 : component[1] -> setValue(gate, 0) ; break ;
                default : ;
            }
        }
        virtual void setEnable(bool val)
        {
            if(val) this -> enable = &t ;
            else this -> enable = &f ;
        }
        virtual void setEnable(Gate *gate)
        {
            this -> enable = gate ;
        }
        virtual void setSelect(bool val, int pin = 0)
        {
            component[1] -> setValue(val, 1) ;
            component[2] -> setValue(val, 0) ;
            component[0] -> input[1] = component[2] ;
        }
        virtual void setSelect(Gate *gate, int pin = 0)
        {
            component[1] -> setValue(gate, 1) ;
            component[2] -> setValue(gate, 0) ;
            component[0] -> input[1] = component[2] ;
        }
        virtual Gate *output()
        {
            component[3] -> setValue(component[0], 0) ;
            component[3] -> setValue(component[1], 1) ;
            component[4] -> setValue(this -> enable, 0) ;
            component[4] -> setValue(component[3], 1) ;
            return component[4] ;
        }
    private :
        Gate *component[5] ;
} ;
class Mux4_1 : public Mux
{
public :
    Mux4_1() : Mux4_1(0) {}
    Mux4_1(bool val) {
        setEnable(val);

        mux2_1[0] = new Mux2_1;
        mux2_1[1] = new Mux2_1;

        component[0] = new NOT;
        component[1] = new AND;

        mux2_1[0]->setEnable(this->enable);
        mux2_1[1]->setEnable(this->enable);
    }
    virtual void setData(bool val, int pin) override {
        mux2_1[(pin / 2) % 2]->setData(val, pin % 2);
    }
    virtual void setData(Gate *gate, int pin) override {
        mux2_1[(pin / 2) % 2]->setData(gate, pin % 2);
    }
    virtual void setSelect(bool val, int pin) override {
        // S0 => mux2_1 && S1 => which output 
        if (!pin) {
            mux2_1[0]->setSelect(val, 0);
            mux2_1[1]->setSelect(val, 0);
        }
        else 
            component[0]->setValue(val, 0);
    }
    virtual void setSelect(Gate *gate, int pin) override {
        if (!pin) {
            mux2_1[0]->setSelect(gate, 0);
            mux2_1[1]->setSelect(gate, 0);
        }
        else 
            component[0]->setValue(gate, 0);
    }
    virtual void setEnable(bool val) override {
        if (val) this->enable = &t;
        else this->enable = &f;
    }
    virtual void setEnable(Gate *gate) override { this->enable = gate; }
    virtual Gate *output() override {
        component[1]->setValue(this->enable, 0);
        if (component[0]->output()) {
            component[1]->setValue(mux2_1[0]->output(), 1);
        } else {
            component[1]->setValue(mux2_1[1]->output(), 1);
        }
        return component[1];
    }
private :
    Mux *mux2_1[2] ;
    Gate *component[3] ;
} ;



int main(){

    

    return 0; 
}