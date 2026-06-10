#ifndef CARD_HPP
#define CARD_HPP
#include <SFML/Graphics.hpp>
#include <iostream>

class Card {
    private:
        std::string suit;
        std::string rank;
        int blackjackValue;
        std::string imagePath;

        sf::Texture texture;
        sf::Sprite sprite{texture};


    public:
        Card(std::string suit, 
            std::string rank, 
            int blackjackValue, 
            std::string imagePath) 
            : suit(suit),
            rank(rank),
            blackjackValue(blackjackValue),
            imagePath(imagePath),
            texture(imagePath),
            sprite(texture)
            {
                sprite.setTexture(texture);
                sprite.setScale({0.125f, 0.125f});
            }

        
        Card(const Card& other)
            : suit(other.suit),
              rank(other.rank),
              blackjackValue(other.blackjackValue),
              imagePath(other.imagePath),
              texture(other.imagePath),
              sprite(texture)
            {
                sprite.setScale(other.sprite.getScale());
                sprite.setPosition(other.sprite.getPosition());
            }

        const sf::Sprite& getSprite() const {
            return sprite;
        }

        int getValue() const{
            return blackjackValue;
        }

        std::string getSuit() const {
            return suit;
        }

        std::string getRank() const {
            return rank;
        }

        std::string getImage() const {
            return imagePath;
        }

        void setPosition(float x, float y) {
            sprite.setPosition({x, y});
        }



        


};




#endif // CARD_HPP