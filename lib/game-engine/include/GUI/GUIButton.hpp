/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** GUIButton
*/

#ifndef GUIBUTTON_HPP_
#define GUIBUTTON_HPP_

#include "cppIncludes.hpp"

class GUIButton {
    public:
        GUIButton();
        ~GUIButton();

        void init(std::string path_normal, std::string path_hover);
        void draw(std::shared_ptr<sf::RenderWindow> window);
        void setPosition(sf::Vector2f pos);
        void setScale(sf::Vector2f scale);
        void setRect(sf::IntRect rect);
        void changeState(bool hover);
        void setCallback(std::function<void()> callback);
        void setName(const std::string &name) { _name = name; }

        bool isHover(sf::Vector2i mousePos);

        sf::Vector2f getPosition();
        sf::Vector2f getScale();
        sf::IntRect getRect();
        sf::Sprite getSprite();
        std::function<void()> getCallback();

    protected:
    private:
        std::string _name;
        std::array<sf::Texture, 2> _textures;
        sf::Sprite _sprite;
        sf::IntRect _rect;
        std::function<void()> _callback;
};

#endif /* !GUIBUTTON_HPP_ */
