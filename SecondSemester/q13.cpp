#include <iostream>
#include <string>

using namespace std; 

class Matrix{
    private: 
        int dimension; 
        int** matrix; 
    public: 
        Matrix(int dimension); 
        Matrix(); 
        ~Matrix(); 
        void rotateRigth();
        void rotateLeft(); 
        void print();
        void scan();
        void allocateMemory(int**&); 
        int getDimension();
        void setDimension(int); 
};


int main(){
    
    string s = ""; 
    int d = 0; 
    Matrix matrix; 
    while(1){
        cin >> s;
        if(s == "stop") break;
        if(s == "rotate") cin >> s; 
        if(s == "scan"){
            cin >> d; 
            matrix.setDimension(d); 
            matrix.scan(); 
        } else if(s == "print"){
            matrix.print(); 
        } else if(s == "right"){
            matrix.rotateRigth(); 
        } else if(s == "left"){
            matrix.rotateLeft(); 
        } else cout << "unknown" << endl; 
    }

    return 0; 
}

Matrix::Matrix(){dimension = 0; matrix = nullptr;}

Matrix::Matrix(int dimension) {this->dimension = dimension; matrix = nullptr; }

void Matrix::rotateRigth(){
    if(dimension > 0){
        int** temp; 
        allocateMemory(temp); 
        for(int i = 0; i < dimension; i++){
            for(int j = 0; j < dimension; j++){
                temp[i][j] = matrix[(dimension-j-1)][i];
            }
        }
        for(int i = 0; i < dimension; i++){
            for(int j = 0; j < dimension; j++){
                matrix[i][j] = temp[i][j]; 
            }
        }

        for(int i = 0; i < dimension; i++){
            delete[] temp[i]; 
        }
        delete[] temp; 
        temp = nullptr; 
    } else 
        cout << "No element in matrix can be rotated." << endl; 
}

void Matrix::rotateLeft(){
    if(dimension > 0){
        int** temp; 
        allocateMemory(temp); 
        for(int i = 0; i < dimension; i++){
            for(int j = 0; j < dimension; j++){
                temp[i][j] = matrix[j][(dimension - i - 1)];
            }
        }

        for(int i = 0; i < dimension; i++){
            for(int j = 0; j < dimension; j++){
                matrix[i][j] = temp[i][j]; 
            }
        }

        for(int i = 0; i < dimension; i++){
            delete[] temp[i]; 
            
        }
        delete[] temp; 
        temp = nullptr; 
    } else 
        cout << "No element in matrix can be rotated." << endl; 
}
void Matrix::print(){
    if(dimension > 0){
        for(int i = 0; i < dimension; i++){
            for(int j = 0; j < dimension; j++){
                cout << matrix[i][j] << " "; 
            }
            cout << endl; 
        }
        //not sure if this is needed. 
        cout << endl;
    } else 
         cout << "No element in matrix can be printed." << endl; 
}

void Matrix::scan(){
    allocateMemory(matrix); 
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            cin >> matrix[i][j]; 
        }
    }
}

void Matrix::allocateMemory(int**& arr){
    arr = new int* [dimension]; 
    for(int i = 0; i < dimension; i++){
        arr[i] = new int[dimension]; 
    }
}
int Matrix::getDimension(){return dimension;}
void Matrix::setDimension(int dimension){
     if (matrix != nullptr) {
        for (int i = 0; i < this->dimension; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    this->dimension = dimension;
}

Matrix::~Matrix(){
    for(int i = 0; i < dimension; i++){
        delete[] matrix[i]; 
    }
    delete[] matrix; 
}