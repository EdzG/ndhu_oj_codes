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


int main() {
    Stack stack;
    PriorityQueue priorityQueue;

    // Pushing elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Pop and print elements from the stack
    while (!stack.empty()) {
        std::cout << "Stack top: " << stack.top() << std::endl;
        stack.pop();
    }

    // Pushing elements onto the priority queue
    priorityQueue.push(30);
    priorityQueue.push(10);
    priorityQueue.push(20);
    priorityQueue.push(100); 

    // Pop and print elements from the priority queue
    while (!priorityQueue.empty()) {
        std::cout << "Priority queue top: " << priorityQueue.top() << std::endl;
        priorityQueue.pop();
    }

    return 0;
}
