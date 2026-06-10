#ifndef HITBUTTON_HPP
#define HITBUTTON_HPP

#include "Button.hpp"
#include "BlackJack.hpp"


class HitButton : public Button {
    public:
        HitButton(float x, float y)
            : Button(x, y)
            {
                if (!texture.loadFromFile("ButtonImages/Hit-Neutral.png")) {
                    std::cout << "Failed to load hit button texture\n";
                }
                else {
                    std::cout << "HIT LOADED\n";
                }


                sprite.setTexture(texture);
                sprite.setTextureRect(sf::IntRect({0, 0}, sf::Vector2i(texture.getSize())));
                sprite.setPosition({x, y});
                sprite.setScale({1.f, 1.f});

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
            std::cout << "Button is clicked \n";
        }

};


#endif //HITBUTTON.HPP