#include <iostream>

class LinkedList
{
    public :
        class Node
        {
            public :
                Node() : next(nullptr), data(0) {}
                Node(int d) : next(nullptr), data(d) {}
                Node(Node *n) : next(n), data(0) {}
                Node(Node *n, int d) : next(n), data(d) {}
                int data;
                Node *next;
        };
        LinkedList() : head(nullptr), length(0) {}
        ~LinkedList() {
            while(length != 0){
                removeFromHead(); 
            }
            head = nullptr; 
            length = 0; 
        }
        bool addFromHead(int d) {
            Node *tmp = new Node(d); 
            tmp->next = head; 
            head = tmp; 
            length++;  
            return true; 
        }
        bool addFromTail(int d) {
            if(length == 0){
                head = new Node(d); 
                length++; 
                return true; 
            }

            Node *tmp = head; 
            while(tmp->next != nullptr){
                tmp = tmp->next; 
            }
            Node *newNode = new Node(d); 
            tmp->next = newNode; 
            length++; 
            return true; 
        }
        bool removeFromHead() {
            if(length == 0) return false; 
            Node *tmp = head->next; 
            delete head; 
            head = tmp; 
            length--; 
            return true; 
        }
        bool removeFromTail() {
            if(length == 0) return false; 
            if(length == 1){
                delete head; 
                head = nullptr; 
                length = 0; 
                return true; 
            }
            Node *tmp = head; 
            while(tmp->next != nullptr){
                if(tmp->next->next == nullptr) break; 
                tmp = tmp->next; 
            }
            delete tmp->next; 
            tmp->next = nullptr; 
            length--; 
            return true; 
        }
        friend std::ostream &operator<<(std::ostream &o, LinkedList *l) {
            if(l == nullptr){
                o << ""; 
                return o; 
            }
            o << "{"; 
            Node* ptr = l->head; 
            while(ptr != nullptr){
                if(ptr->next == nullptr){
                    o << ptr->data; 
                } else {
                    o << ptr->data << ", "; 
                }
                ptr = ptr->next; 
            }
            o << "}" << std::endl; 
            return o; 
        }
        size_t getSize() const {return length;}
    protected :
        Node *head;
        int length; 

};

int main(){
    LinkedList a; 
    a.addFromHead(5); 
    a.addFromHead(6); 
    a.addFromTail(4); 
    std::cout << &a << std::endl; 
    a.removeFromHead(); 
    std::cout << &a << std::endl; 
    a.removeFromTail(); 
    std::cout << &a << std::endl; 
    a.removeFromHead(); 
    std::cout << &a << std::endl; 
    a.addFromTail(3); 
    std::cout << &a << std::endl; 
    a.addFromTail(2); 
    std::cout << &a << std::endl; 
    a.removeFromTail(); 
    std::cout << &a << std::endl; 
    a.removeFromTail(); 
    
    // a.removeFromHead(); 
    // a.removeFromHead(); 
    std::cout << &a << std::endl; 

    return 0;
}