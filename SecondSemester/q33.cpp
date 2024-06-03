#include <iostream>

template <class T>
class Set{
    public:
        Set():count(0){}
        Set(const Set &obj){
            for(int i = 0; i < obj.count; i++){
                element[i] = obj.element[i]; 
            }
            count = obj.count; 
        }
        void display(){
            int j; 
            for(j = 0; j < count; j++){
                std::cout << element[j] << " "; 
            }
        }
        int add(const T a){
            if(count < 100 && !contains(a)){
                element[count] = a; 
                count++; 
                return 1;
            } else return 0;    
        }
        int add(const Set<T> obj){
            int num_of_additions = 0; 
            for(int j = 0; j < obj.count; j++){
                if(count < 100 && !contains(obj.element[j])){
                    element[count++] = obj.element[j]; 
                    num_of_additions++;
                }
            }
            return num_of_additions; 
        }
        

        bool contains(const T& item) const {
            for(int i = 0; i < count; i++){
                if(element[i] == item){
                    return true;
                }
            }
            return false;
        }
        
        Set operator+ (const Set& obj){
            Set<int> result; 
            for(int i = 0; i < count; i++){
                result.add(element[i]); 
            }
            for(int i = 0; i < obj.count; i++){
                result.add(obj.element[i]); 
            }
            return result; 
        }
        Set operator- (const Set& obj){
            Set<int> result; 
            int min = (count > obj.count)? obj.count: count; 
            for(int i = 0; i < count; i++){
                if(contains(element[i]) && obj.contains(element[i])) result.add(element[i]); 
            }
            return result; 
        }

    private: 
        T element[100]; 
        int count; 
};


int main() {
    // Create a set of integers
    Set<int> intSet;

    // Add some elements to the set
    intSet.add(10);
    intSet.add(20);
    intSet.add(30);
    intSet.add(10); 

    // Display the elements of the set
    std::cout << "Elements of intSet: ";
    intSet.display();
    std::cout << std::endl;

    // Create another set of integers
    Set<int> anotherIntSet;

    // Add some elements to the second set
    anotherIntSet.add(40);
    int num_added = anotherIntSet.add(50);
    anotherIntSet.add(10); 
    anotherIntSet.add(60); 
    std::cout << "Elements added when adding one element: " << num_added << std::endl; 


    // Display the elements of the second set
    std::cout << "Elements of anotherIntSet: ";
    anotherIntSet.display();
    std::cout << std::endl;

    // Add elements from anotherIntSet to intSet
    // int numAdded = intSet.add(anotherIntSet);

    // Display the updated elements of intSet
    // std::cout << "Elements of intSet after adding anotherIntSet: ";
    // intSet.display();
    // std::cout << std::endl;
    // std::cout << "Number of elements added: " << numAdded << std::endl;

    std::cout << "Testing the Union of two sets" << std::endl; 
    Set<int> _union = intSet + anotherIntSet; 
    _union.display(); 
    std::cout << std::endl; 

    std::cout << "Testing the Intersect of two sets" << std::endl; 
    Set<int> _intersect; 
    _intersect = intSet - anotherIntSet; 
    _intersect.display(); 
    std::cout << std::endl; 


    

    return 0;
}
