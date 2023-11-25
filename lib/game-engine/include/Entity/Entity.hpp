/*
** EPITECH PROJECT, 2023
** Entity
** File description:
** man man
*/

#pragma once
#include "cppIncludes.hpp"

class Entity {
    public:
        Entity();
       ~Entity();
        void init(const std::string &filename);
        void update(std::shared_ptr<sf::RenderWindow> window);
        void draw(std::shared_ptr<sf::RenderWindow> window);
    private:
        std::string _filename;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Vector2f _position;
        sf::Vector2f _scale;
        sf::Vector2f _origin;
        sf::Vector2f _velocity;
        sf::Vector2f _acceleration;
};
