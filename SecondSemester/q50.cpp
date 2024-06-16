#include <iostream>

class Mine_sweeper{
    public:
        Mine_sweeper(int r, int c) : row(r), col (c){
            mine_field = new char* [row]; 
            for(int i = 0; i < row; i++){
                mine_field[i] = new char[col]; 
            }
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    std::cin >> mine_field[i][j]; 
                }
            }
        }
         ~Mine_sweeper() {
            for(int i = 0; i < row; i++) {
                delete[] mine_field[i];
            }
            delete[] mine_field;
        }

        void displayField(){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    int num = adjacent_mine(i, j); 
                    if(num == -1) std::cout << "*"; 
                    else std::cout << num; 
                }
                std::cout << std::endl; 
            }
            
        }
        int adjacent_mine(int i, int j) {
            int num_of_adjacent_mines = 0; 
            char mine = '*'; 
            if(mine_field[i][j] == mine) return -1; 

            for(int di = -1; di <= 1; di++) {
                for(int dj = -1; dj <= 1; dj++) {
                    if(di == 0 && dj == 0) continue; 
                    int ni = i + di;
                    int nj = j + dj;
                    if(ni >= 0 && ni < row && nj >= 0 && nj < col) {
                        if(mine_field[ni][nj] == mine) num_of_adjacent_mines++; 
                    }
                }
            }
            return num_of_adjacent_mines; 
        }

    private:
        char **mine_field; 
        int row; 
        int col; 

};
int main(){
    int i, j, counter = 1; 
    while(std::cin >> i >> j && i != 0 && j != 0){
        Mine_sweeper obj(i, j); 
        std::cout << "Field #" << counter++ << ":" << std::endl; 
        obj.displayField(); 
        std::cout << std::endl; 
    }

    return 0; 
}