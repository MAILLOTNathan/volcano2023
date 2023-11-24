/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Graphical
*/

#ifndef SFMLGRAPHICAL_HPP_
#define SFMLGRAPHICAL_HPP_

#include "../../../include/Graphical/Graphical.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SFMLGraphical : public etib::Graphical {
    public:
        SFMLGraphical();
        ~SFMLGraphical();

        void init() override;
        void stop() override;

        void createWindow(std::uint32_t width, std::uint32_t height, std::string title) override;
        void destroyWindow() override;

        void clear() override;
        void draw() override;

        void createSprite() override;
        void destroySprite() override;
        void setSpriteTexture() override;
        void setSpritePosition() override;
        void setSpriteRotation() override;
        void setSpriteScale() override;
        void drawSprite() override;

        void createText() override;
        void destroyText() override;
        void setTextString() override;
        void setTextFont() override;
        void setTextPosition() override;
        void setTextRotation() override;
        void setTextScale() override;
        void drawText() override;

    private:
        sf::RenderWindow *_window;
        std::map<std::string, sf::Sprite> _sprites;
};

#endif /* !SFMLGRAPHICAL_HPP_ */
