#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <SFML/Graphics.hpp>
#include <iostream>



class Button {
    protected:
        sf::Texture texture;
        sf::Sprite sprite{texture};

    public:
        Button(float x, float y) {
            sprite.setPosition({x, y});

        }

        virtual ~Button() = default;



        bool isMouseOver(sf::RenderWindow& window) {
            auto mousePos = sf::Mouse::getPosition(window);
            auto worldPos = window.mapPixelToCoords(mousePos);

            return sprite.getGlobalBounds().contains(worldPos);

        }

        void draw(sf::RenderWindow& window) {
            window.draw(sprite);
            
        }

        virtual void onClick() {
            std::cout << "Button is pressed \n";
        }
      
        
};





#endif //BUTTON_HPP