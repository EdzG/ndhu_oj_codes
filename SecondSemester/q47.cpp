#include <iostream>
#include <string>

class Decryption{
    public:
        Decryption(std::string message):encoded_message(message){}
        void display_decrypted_message(){
            for(int i = 0; i < encoded_message.length(); i++){
                if(encoded_message[i] != ' '){
                    std::cout << get_decrypted_character(encoded_message[i]); 
                } else std::cout << " "; 
            }
            std::cout << std::endl; 
           
        }
        

    private:
        char get_decrypted_character(char chr){
            chr = tolower(chr); 
            for(int i = 0; i < keyboard.length(); i++){
                if(chr == keyboard[i] && i > 1) 
                    return keyboard[i-2];
            }
            return chr; 
        }
        std::string encoded_message;
        static std::string keyboard; 
};

std::string Decryption::keyboard = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";

int main(){
    std::string message; 
    
    while(std::getline(std::cin, message)){
        Decryption decrypted_message(message); 
        decrypted_message.display_decrypted_message(); 
    }
 
    

    return 0; 
}