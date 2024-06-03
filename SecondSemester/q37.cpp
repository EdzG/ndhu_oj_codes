#include <iostream>

template<class T>
class LinkedList
{
    public :
        class Node
        {
            public :
                Node() : next(nullptr), data(0) {}
                Node(T d) : next(nullptr), data(d) {}
                Node(Node *n) : next(n), data(0) {}
                Node(Node *n, T d) : next(n), data(d) {}
                T data;
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
        bool addFromHead(T d) {
            Node *tmp = new Node(d); 
            tmp->next = head; 
            head = tmp; 
            length++;  
            return true; 
        }
        bool addFromTail(T d) {
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
        bool searchData(T d){
            Node *tmp = head; 
            while(tmp != nullptr){
                if(tmp->data == d) return true; 
                tmp = tmp->next; 
            }
            return false; 
        }
        T operator[](int i){
            Node *tmp = head; 
            while(i > 0 && tmp != nullptr){
                tmp = tmp->next; 
                i--; 
            }
            return tmp? tmp->data: -1; 
        }
    protected:
        Node *head;
        int length; 
};

template<class T>
class Set : private LinkedList<T>
{
    public :
        //initialize members
        Set<T>() : LinkedList<T>() {}
        //add an element, return true if added, false if not
        bool addElement(T d) {
            if(LinkedList<T>::searchData(d)) return false; 
            LinkedList<T>::addFromTail(d); 
            return true; 
        }
        ~Set<T>(){
            this->LinkedList<T>::~LinkedList();  
        }
        //display in format {4,5}
        friend std::ostream &operator<<(std::ostream &o, Set<T> *s) {
             if(s == nullptr){
                o << "{}"; 
                return o; 
            }
            o << "{"; 
            if(s->length > 0){
                for(int i = 0; i < s->length - 1; i++){
                o << (*s)[i]; 
                o << ", "; 
                }
                o << (*s)[s->length-1]; 
            }
            o << "}" << std::endl; 

            return o; 
        }
        //return Set pointer with elements of union set
        Set<T>* operator+(Set<T> *s) {
            Set<T> *result = new Set<T>(); 
            for(int i = 0; i < this->length; i++){
                result->addElement((*this)[i]); 
            }
            for(int i = 0; i < s->length; i++){
                result->addElement((*s)[i]); 
            }

            return result; 
        }
        //return pointer with difference of two sets
        Set<T>* operator-(Set<T> *s) {
            Set<T> *result = new Set<T>(); 
            for(int i = 0; i < this->length; i++){
                if(!s->searchData((*this)[i]))
                    result->addElement((*this)[i]); 
            }
            return result; 
        }
        //return intersection
        Set<T>* operator*(Set<T> *s) {
            Set<T> *result = new Set<T>(); 
            for(int i = 0; i < this->length; i++){
                if(s->searchData((*this)[i]))
                    result->addElement((*this)[i]); 
            }
            return result; 
        }

        bool operator==(Set<T> *s) {
            if(this->length != s->length) return false; 
            for(int i = 0; i < this->length; i++){
                if(!s->searchData((*this)[i])) return false; 
            }
            return true; 
        }

        // A proper superset of B {4,5} > {4,5} return true; 
        bool operator>(Set<T> *s) {
            if(s->length >= this->length) return false; 
            for(int i = 0; i < s->length; i++){
                if(!this->searchData((*s)[i])) return false; 
            }
            return true; 
        }
        //A is proper subset of B; 
        bool operator<(Set<T> *s) {
            if(this->length >= s->length) return false; 
            for(int i = 0; i < this->length; i++){
                if(!s->searchData((*this)[i])) return false; 
            }
            return true; 
        }

        // A is superset of B
        bool operator>=(Set<T> *s) {
            if(s->length > this->length) return false; 
            for(int i = 0; i < s->length; i++){
                if(!this->searchData((*s)[i])) return false; 
            }
            return true; 
        }
        //A is a subset of B
        bool operator<=(Set<T> *s) {
            if(this->length > s->length) return false; 
            for(int i = 0; i < this->length; i++){
                if(!s->searchData((*this)[i])) return false; 
            }
            return true; 
        }


};

int main() {
    Set<int> set1;
    set1.addElement(1);
    set1.addElement(2);
    set1.addElement(3);

    Set<int> set2;
    set2.addElement(2);
    set2.addElement(3);
    set2.addElement(4);

    Set<int>* unionSet = set1 + &set2;
    Set<int>* intersectionSet = set1 * &set2;
    Set<int>* differenceSet = set1 - &set2;

    std::cout << "Set1: " << &set1 << std::endl;
    std::cout << "Set2: " << &set2 << std::endl;
    std::cout << "Union: " << unionSet << std::endl;
    std::cout << "Intersection: " << intersectionSet << std::endl;
    std::cout << "Difference: " << differenceSet << std::endl;

    Set<int> a; 
    Set<int> b; 
    a.addElement(4); 
    a.addElement(5); 
    b.addElement(4); 
    b.addElement(5); 
    int isSubSet = b < &a, isntSubset = b <= &a, isSuperSet = a > &b, isntSuperset =  a >= &b; 

    std::cout << "a: " << &a << std::endl; 
    std::cout << "b: " << &b << std::endl; 
    
    std::cout << "b proper subset a: " << isSubSet << std::endl; 
    std::cout << "b subset a: " << isntSubset << std::endl; 
    std::cout << "a proper superset b: " << isSuperSet << std::endl; 
    std::cout << "a superset b: " << isntSuperset << std::endl; 



    delete unionSet;
    delete intersectionSet;
    delete differenceSet;

    return 0;
}
