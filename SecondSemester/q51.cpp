#include <iostream>

class Largest_square{
    public:
        Largest_square(int m, int n): row(m), col(n){
            rectangle = new char *[row]; 
            for(int i = 0; i < row; i++){
                rectangle[i] = new char[col]; 
            }

            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    std::cin >> rectangle[i][j]; 
                }
            }
        }
         ~Largest_square() {
            for(int i = 0; i < row; i++) {
                delete[] rectangle[i];
            }
            delete[] rectangle;
        }
        bool validSquare(int i, int j, int scaler) {
            char chr = rectangle[i][j]; 

            for(int di = 0; di <= scaler; di++) {
                for(int dj = 0; dj <= scaler; dj++) {
                    int ni1 = i + di;
                    int nj1 = j + dj;
                    int ni2 = i - di;
                    int nj2 = j - dj;
                    if(ni1 >= 0 && ni1 < row && nj1 >= 0 && nj1 < col) {
                        if(rectangle[ni1][nj1] != chr) return false; 
                    } else {
                        return false;
                    }
                    if(ni2 >= 0 && ni2 < row && nj2 >= 0 && nj2 < col) {
                        if(rectangle[ni2][nj2] != chr) return false; 
                    } else {
                        return false;
                    }
                }
            }
            return true; 
        }

        int length_of_largest(int i, int j) {
            int length = 1; 
            int scaler = 1; 
            while(validSquare(i, j, scaler)) {
                length += 2; 
                scaler++;
            }
            return length; 
        }

    private:
        int row;
        int col; 
        char** rectangle; 

};


int main(){
    int test_cases; 
    std::cin >> test_cases;
    while(test_cases--){
        int m, n, c; 
        std::cin >> m >> n >> c; 
        std::cout << m <<  " " << n << " " << c << std::endl; 
        Largest_square obj(m, n); 
        for(int i = 0; i < c; i++){
            int x, y; 
            std::cin >> x >> y; 
            std::cout << obj.length_of_largest(x, y) << std::endl;  
        }
    }

    return 0; 
}