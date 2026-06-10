#ifndef RESETBUTTON_HPP
#define RESETBUTTON_HPP

#include "Button.hpp"


class ResetButton : public Button {
    public:
        ResetButton(float x, float y)
            : Button(x, y)
            {
                if (!texture.loadFromFile("ButtonImages/ResetButtonBJ.png")) {
                    std::cout << "Failed to load Stand button texture\n";
                }
                else {
                    std::cout << "RESET LOADED\n";
                }


                sprite.setTexture(texture);
                sprite.setTextureRect(sf::IntRect({0, 0}, sf::Vector2i(texture.getSize())));
                sprite.setPosition({x, y});
                sprite.setScale({0.5f, 0.5f});

                std::cout << "Texture size: "
                          << texture.getSize().x << " "
                          << texture.getSize().y << "\n";

                auto bounds = sprite.getGlobalBounds();
                std::cout << "Button bounds: "
                
                          << bounds.position.x << " "
                          << bounds.position.y << " "
                          << bounds.size.x << " "
                          << bounds.size.y << "\n";
            }
        
        void onClick() override {
            std::cout << "Button is clicked but this is for stand \n";
        }

};


#endif //RESETBUTTON.HPP