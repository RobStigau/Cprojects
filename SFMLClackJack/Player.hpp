#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Card.hpp"
#include "Deck.hpp"


class Player {

    private:
        std::vector<Card> hand;

    public:
        Player() {};

        void addCard(Card card) {
            hand.push_back(std::move(card));
        }

        std::vector<Card>& getHand() {
            return hand;
        }
        int getHandValue() {
            int handValue = 0;
            int aceCnt = 0;

            for (const Card& card : hand) {
                int cardVal = card.getValue();
                handValue += cardVal;

                if (cardVal == 11) {
                    aceCnt++;
                }
 
            }
            while (handValue > 21 && aceCnt > 0) {
                handValue -= 10;
                aceCnt--;
            }
            return handValue;
        }

        void draw(sf::RenderWindow& window) {
            for (const Card& card : hand) {
                window.draw(card.getSprite());
            
            }
        }

        void clearHand() {
            hand.clear();
        }

};



#endif // PLAYER_HPP