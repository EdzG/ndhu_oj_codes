#include <iostream>

#define spade 4
#define heart 3
#define diamond 2
#define club 1

class PokerCard {
    public:
        PokerCard(std::string s, int f) {
            suit = s;
            face = f;
        }
        //Please finish the comparison operator override
        //compare face first, if the same then compare suit 
        //請完成比較運算子多載
        //先比較 face ， face 一樣再比較 suit
        //1 > 13 > 12 > 11 > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2
        //spade > heart > diamond > club

        friend std::ostream &operator<<(std::ostream &out, const PokerCard &p){
            out<<"["<<p.face<<" of "<<p.suit<<"]";
            return out;
        }

        bool operator>(PokerCard &b){
            int result = faceComparison(face, b.face); 
            //std::cout << "this is result " << result << std::endl; 
            if(result == 0){
                result = suitToNum(suit) - suitToNum(b.suit);
                if(result > 0) return true; 
                else return false; 
            } else if(result > 0) return true; 
            else return false; 

        }
        bool operator<(PokerCard &b){
            PokerCard a(suit, face); 
            return b > a; 
        }
        bool operator==(PokerCard &b){
            int result = faceComparison(face, b.face); 
            return !result && suitToNum(suit) == suitToNum(b.suit); 
        }
        int suitToNum(std::string card_suit){
            if(card_suit == "spade") return 4; 
            if(card_suit ==  "heart") return 3; 
            if(card_suit == "diamond") return 2; 
            if(card_suit == "club") return 1; 
            else return 0; 
        }
        int faceComparison(int a, int b){
            if(a == 1 && b > a) return 1; 
            if(b == 1 && a > b) return -1; 
            return a - b; 
            //positive means a is bigger
            //negative means a is smaller
            //0 means equal 
        }

    private:
        std::string suit;
        int face;
};

int main() {
    // Creating some PokerCard objects
    PokerCard card1("spade", 1);
    PokerCard card2("heart", 1);
    PokerCard card3("club", 10);
    PokerCard card4("spade", 10); 
    // Printing the PokerCard objects
    // std::cout << "Card 1: " << card1 << std::endl;
    // std::cout << "Card 2: " << card2 << std::endl;
    // std::cout << "Card 3: " << card3 << std::endl;
    // std::cout << "Card 4: " << card4 << std::endl; 

    std::cout << (card1 < card2) << std::endl; 
    std::cout << (card2 < card1) << std::endl; 
    std::cout << (card1 > card2) << std::endl; 
    std::cout << (card2 > card1) << std::endl; 
    std::cout << (card1 == card4) << std::endl; 
    std::cout << (card4 == card1) << std::endl; 
    std::cout << (card1 < card3) << std::endl; 

    // Comparing PokerCard objects
    // if (card1 > card2)
    //     std::cout << "Card 1 is greater than Card 2" << std::endl;
    // else if (card1 < card2)
    //     std::cout << "Card 1 is less than Card 2" << std::endl;
    // else
    //     std::cout << "Card 1 is equal to Card 2" << std::endl;

    // if (card1 == card3)
    //     std::cout << "Card 1 is equal to Card 3" << std::endl;
    // else
    //     std::cout << "Card 1 is not equal to Card 3" << std::endl;
    // if(card1 == card4) std::cout << "yes it is " << std::endl; 

    return 0;
}