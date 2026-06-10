#include <iostream>
#include "C-Turtle/CTurtle.hpp"
#include <unordered_map>
#include <memory>
#include <random>

namespace turtCard = cturtle;

std::random_device rd;
std::mt19937 gen(rd());


struct Card {
    std::string suit;
    std::string value;
    std::shared_ptr<cturtle::Turtle> turtCard;
};

class Player {
    public:
        std::vector<Card> hand;
};


class Deck{

    private:
        std::vector<Card> cardList;
        std::vector<Card> discardList;
    
    public:
        Deck(cturtle::TurtleScreen& screen) {
            for (int i = 0; i < 52; i++) {
                std::string suit;
                std::string value;

                if (i < 13) {
                    suit = "Hearts";
                    value = std::to_string(i + 1);
                
                }
                else if (i < 26) {
                    suit = "Diamonds";
                    value = std::to_string(i - 12);

                }
                else if (i < 39) {
                    suit = "Clubs";
                    value = std::to_string(i - 25);
                }
                else {
                    suit = "Spades";
                    value = std::to_string(i - 38);
                }

                Card card = {suit, value, std::make_shared<cturtle::Turtle> (screen)};
                cardList.push_back(card);
            }

        }
        Card getCard() {
            int deckSize = cardList.size();
            std::uniform_int_distribution<> dis(0, deckSize - 1);
            int randomIndex = dis(gen);
            Card grabbedCard = cardList[randomIndex];
            discardList.push_back(grabbedCard);
            cardList.erase(cardList.begin() + randomIndex);
            return grabbedCard;
        }


};

class Button {
    private:
        std::string label;
        std::shared_ptr<cturtle::Turtle> turtButton;
        

}


class ClackJack {
    private:
        Deck deck;
        Player player;
        Player dealer;
    
    public:
        void startGame() {
            bool Gamerule = true;
            player.hand.push_back(deck.getCard());
            dealer.hand.push_back(deck.getCard());
            player.hand.push_back(deck.getCard());
            dealer.hand.push_back(deck.getCard());

            while (Gamerule) {

            }

            
        }
}; 



int main() {

    cturtle::TurtleScreen screen;

    scr
    Deck deck(screen);



    
    screen.exitonclick();
    return 0;
}



