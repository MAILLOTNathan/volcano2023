/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Graphical
*/

#ifndef SFMLGRAPHICAL_HPP_
#define SFMLGRAPHICAL_HPP_

#include "../../../include/Graphical/AGraphical.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SFMLGraphical : public etib::AGraphical {
    public:
        SFMLGraphical();
        ~SFMLGraphical();

        void init() ;
        void stop() ;

        void createWindow(std::uint32_t width, std::uint32_t height, std::string title) ;
        void destroyWindow() ;

        void clear() ;
        void draw() ;

        void createSprite() ;
        void destroySprite() ;
        void setSpriteTexture() ;
        void setSpritePosition() ;
        void setSpriteRotation() ;
        void setSpriteScale() ;
        void drawSprite() ;

        bool isOpen();

        void createText() ;
        void destroyText() ;
        void setTextString() ;
        void setTextFont() ;
        void setTextPosition() ;
        void setTextRotation() ;
        void setTextScale() ;
        void drawText() ;

    private:
        std::shared_ptr<sf::RenderWindow> _window;
        std::map<std::string, sf::Sprite> _sprites;
};

#endif /* !SFMLGRAPHICAL_HPP_ */
