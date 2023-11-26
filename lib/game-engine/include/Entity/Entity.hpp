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
        void setTextureRect(const sf::IntRect &rect);
        void setPosition(const sf::Vector2f &position);
        void setScale(const sf::Vector2f &scale);
        void setOrigin(const sf::Vector2f &origin);
        void setVelocity(const sf::Vector2f &velocity);
        void setAcceleration(const sf::Vector2f &acceleration);

        sf::IntRect getTextureRect() const;
        sf::Vector2f getPosition() const;
        sf::Vector2f getScale() const;
        sf::Vector2f getOrigin() const;
        sf::Vector2f getVelocity() const;
        sf::Vector2f getAcceleration() const;

        void update(std::shared_ptr<sf::RenderWindow> window);
        void draw(std::shared_ptr<sf::RenderWindow> window);
    private:
        std::string _filename;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::IntRect _rect;
        sf::Vector2f _position;
        sf::Vector2f _scale;
        sf::Vector2f _origin;
        sf::Vector2f _velocity;
        sf::Vector2f _acceleration;
};
