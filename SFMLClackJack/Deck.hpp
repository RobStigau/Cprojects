#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include <iostream>
#include <random>
#include <utility>
#include "Card.hpp"


std::random_device rd;
std::mt19937 gen(rd());

class Deck {
    private:
        std::vector<Card> cardList;
        std::vector<Card> discardList;

    public:
        Deck() {

            std::string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
            std::string ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
            std::string imageFiles[52] = {"ImageFolder/2Hearts.png", "ImageFolder/2Diamonds.png","ImageFolder/2Clubs.png","ImageFolder/2Spades.png", 
                                          "ImageFolder/3Hearts.png", "ImageFolder/3Diamonds.png","ImageFolder/3Clubs.png","ImageFolder/3Spades.png",
                                          "ImageFolder/4Hearts.png", "ImageFolder/4Diamonds.png","ImageFolder/4Clubs.png","ImageFolder/4Spades.png",
                                          "ImageFolder/5Hearts.png", "ImageFolder/5Diamonds.png","ImageFolder/5Clubs.png","ImageFolder/5Spades.png",
                                          "ImageFolder/6Hearts.png", "ImageFolder/6Diamonds.png","ImageFolder/6Clubs.png","ImageFolder/6Spades.png",
                                          "ImageFolder/7Hearts.png", "ImageFolder/7Diamonds.png","ImageFolder/7Clubs.png","ImageFolder/7Spades.png",
                                          "ImageFolder/8Hearts.png", "ImageFolder/8Diamonds.png","ImageFolder/8Clubs.png","ImageFolder/8Spades.png",
                                          "ImageFolder/9Hearts.png", "ImageFolder/9Diamonds.png","ImageFolder/9Clubs.png","ImageFolder/9Spades.png",
                                          "ImageFolder/10Hearts.png", "ImageFolder/10Diamonds.png","ImageFolder/10Clubs.png","ImageFolder/10Spades.png",
                                          "ImageFolder/JackHearts.png", "ImageFolder/JackDiamonds.png","ImageFolder/JackClubs.png","ImageFolder/JackSpades.png",
                                          "ImageFolder/QueenHearts.png", "ImageFolder/QueenDiamonds.png","ImageFolder/QueenClubs.png","ImageFolder/QueenSpades.png",
                                          "ImageFolder/KingHearts.png", "ImageFolder/KingDiamonds.png","ImageFolder/KingClubs.png","ImageFolder/KingSpades.png",
                                          "ImageFolder/AceHearts.png", "ImageFolder/AceDiamonds.png","ImageFolder/AceClubs.png","ImageFolder/AceSpades.png"
                                        };

            for (const std::string& suit : suits) {
                for (const std::string& rank : ranks) {
                    int blackjackValue;
                    std::string imagePath;


                    if (rank == "Ace") {
                        blackjackValue = 11;
                    }
                    else if (rank == "Jack" || rank == "Queen" || rank == "King" ) {
                        blackjackValue = 10;
                    }
                    else {
                        blackjackValue = std::stoi(rank);

                    }

                    imagePath = "ImageFolder/" + rank + suit + ".png";
                    Card card(suit, rank, blackjackValue, imagePath);
                    cardList.emplace_back(suit, rank, blackjackValue, imagePath);
                }
            }
        }

        Card getCard() {
            Card card = cardList.back();
            cardList.pop_back();
            return card;
        }


        void shuffle() {
            std::shuffle(cardList.begin(), cardList.end(), gen);
        }



    };





#endif // DECK_HPP