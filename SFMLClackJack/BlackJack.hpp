#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include "Player.hpp"
#include "Deck.hpp"
#include "HitButton.hpp"
#include "StandButton.hpp"
#include "ResetButton.hpp"
#include <SFML/Graphics.hpp>

class BlackJack {
private:
    Deck deck;
    Player player;
    Player dealer;

public:


    void startGame() {
        initGenerateHand(player, dealer);
        }



    void playerCardToHand(Player& player) {
        player.addCard(deck.getCard());
    }


    void initGenerateHand(Player& player, Player& dealer) {
        playerCardToHand(player);
        playerCardToHand(dealer);
    }

    void layoutHand(Player& player, float startX, float startY) {
        for (Card& card : player.getHand()) {
            card.setPosition(startX, startY);
            startX = startX + 80.f;
            std::cout << "layout card moved to "
                      << startX
                      << ", "
                      << startY
                      << "\n";
        }
    }

    bool dealerSequence() {
        bool playerWon = false;
        while (dealer.getHandValue() <= player.getHandValue()) {
            playerCardToHand(dealer);
            layoutHand(dealer, 200, 20);
            if (dealer.getHandValue() > 21) {
                playerWon = true;
                return playerWon;
            }

            else if (dealer.getHandValue() > player.getHandValue()) {
                playerWon = false;
                return playerWon;
            }

            else{ 
                continue;
            }
            
        }
        return false;
 
    }

    bool disable(bool buttonEnable) {
        buttonEnable = false;
        return buttonEnable;
    }



    int run() {
        sf::RenderWindow window(sf::VideoMode({612, 306}), "ClackJack");

        HitButton hitbutton(50.f, 200.f);
        StandButton standbutton(50.f, 50.f);
        ResetButton resetbutton(30.f, 110.f);
        sf::Texture backgroundTexture;
        sf::Font font;
        sf::Font winfont;
        sf::Font losefont;



        if (!font.openFromFile("BJFont.ttf")) {
            return -1;
        }

        if (!winfont.openFromFile("BJFont.ttf")) {
            return -1;
        }

        if (!losefont.openFromFile("BJFont.ttf")) {
            return -1;
        }


        if (!backgroundTexture.loadFromFile("ImageFolder/BlackJackBG.png")) {
            return -1;
        }

        sf::Texture hitTexture;
        if (!hitTexture.loadFromFile("ButtonImages/Hit-Neutral.png")) {
            return -1;
        }

        sf::Texture standTexture;
        if (!standTexture.loadFromFile("ButtonImages/Stand-Neutral.png")) {
            return -1;
        }

        sf::Texture resetTexture;
        if (!resetTexture.loadFromFile("ButtonImages/ResetButtonBJ.png")) {
            return -1;
        }


        



        
        sf::Sprite background(backgroundTexture);

        //sf::Sprite hitbuttonSprite(hitTexture);
        
        
        
        deck.shuffle();
        startGame();
        bool gameOver = false;
        bool hitEnabled = true;
        bool standEnabled = true;

        //HitButton hitButton(100.f, 20.f);

        layoutHand(player, 200, 200);
        layoutHand(dealer, 200, 20);


        sf::Text handValueText(font);
        handValueText.setPosition({120.f, 130.f});
        handValueText.setString(std::to_string(player.getHandValue()));
        handValueText.setCharacterSize(30);

        sf::Text WinText(winfont);
        WinText.setPosition({200.f, 130.f});
        WinText.setString(std::string("YOU WIN"));
        WinText.setCharacterSize(30);

        sf::Text LoseText(losefont);
        LoseText.setPosition({200.f, 130.f});
        LoseText.setString(std::string("YOU LOSE"));
        LoseText.setCharacterSize(30);
        //Card testCard = deck.getCard();
        bool playerWon = false;
        bool playerLose = false;



        while (window.isOpen()) {

            

            while (auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }

                if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                    if (mousePressed->button == sf::Mouse::Button::Left) {
                        if(hitbutton.isMouseOver(window) && !gameOver && hitEnabled) {
                            hitbutton.onClick();
                            playerCardToHand(player);
                            layoutHand(player, 200, 200);
                            handValueText.setString(std::to_string(player.getHandValue()));

                            if (player.getHandValue() > 21) {
                                gameOver = true;
                            }

                            else if (player.getHandValue() == 21) {
                                gameOver = true;
        
                            }
                        }
                    

                        if(standbutton.isMouseOver(window) && !gameOver && standEnabled) {
                            gameOver = true;
                            standEnabled = false;
                            hitEnabled = false;
                            bool result = dealerSequence();
                            if (result == true) {
                                playerWon = true;
                            }
                            else {
                                playerLose = true;
                            }
                        }

                        if(resetbutton.isMouseOver(window) && gameOver) {
                            player.clearHand();
                            dealer.clearHand();

                            deck = Deck();
                            deck.shuffle();
                            startGame();
                            layoutHand(player, 200, 200);
                            layoutHand(dealer, 200, 20);
                            gameOver = false;
                            hitEnabled = true;
                            standEnabled = true;
                            playerWon = false;
                            playerLose = false;

                            handValueText.setString(std::to_string(player.getHandValue()));
                        }



                    }
                
                }
                
            }

            window.clear();



            window.draw(background);
            window.draw(handValueText);

            
            //window.draw(testCard.getSprite());
            //window.draw(hitbuttonSprite);
            hitbutton.draw(window);
            standbutton.draw(window);
            resetbutton.draw(window);
            player.draw(window);
            dealer.draw(window);
            if (player.getHandValue() > 21) {
                window.draw(LoseText);
            }
            if (player.getHandValue() == 21) {
                window.draw(WinText);
            }

            if (playerWon) {
                window.draw(WinText);
            }

            if (playerLose) {
                window.draw(LoseText);
            }


            
            

            // Later: draw cards and buttons here

            window.display();
        }
        return 0;
    }
};






#endif // BLACKJACK_HPP