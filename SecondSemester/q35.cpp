#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>

class Container {
    public:
        virtual void push(int) = 0;
        virtual void pop() = 0;
        virtual int top() const = 0;
        virtual bool empty() const = 0;
};

class Stack: public Container {
    public: 
        Stack():index(-1){}
        void push(int item) override {
            elements[++index] = item; 
        }
        void pop() override {
            if(index == -1) 
                throw std::out_of_range("There are no element"); 
            else index--; 
        }
        int top()const override {
            if(index > -1) return elements[index]; 
            throw std::out_of_range("There are no elements!"); 
        }
        bool empty() const override {
            if(index == -1) return true;
            else return false; 
        }
    private:
        int index; 
        int elements[1000]; 
};

class PriorityQueue: public Container {
    //ensure to keep array sorted in ascending order; 
    //value with the maximum value is always at the top; 
    public:
        PriorityQueue():index(-1){}
        void push(int item) override {
            int i = index;
            while (i >= 0 && elements[i] > item) {
                elements[i + 1] = elements[i];
                i--;
            }
            elements[i + 1] = item;
            index++;   
        }
        void pop() override {
            if(index == -1) 
                throw std::out_of_range("There are no element"); 
            else index--; 
        }
        int top() const override {
             if(index > -1) return elements[index]; 
            throw std::out_of_range("There are no elements!"); 
        }
        bool empty() const override {
            if(index == -1) return true; 
            else return false; 
        }
    private:
        int index; 
        int elements[1000]; 
};


int judge(Container *c) {
    c->push(10); 
    c->push(50); 
    c->push(20); 
    if(c->top() == 50) return 2; 
    else return 1; 
  
}

int main(){

    Container *c = new PriorityQueue(); 
    int a = judge(c); 
    std::cout << a << std::endl; 

    return 0; 
}