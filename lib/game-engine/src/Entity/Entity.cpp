/*
** EPITECH PROJECT, 2023
** Entity
** File description:
** programmers start to count from 0
*/

#include "Entity/Entity.hpp"

Entity::Entity()
{
    _position = sf::Vector2f(0, 0);
    _scale = sf::Vector2f(0, 0);
    _origin = sf::Vector2f(0, 0);
    _velocity = sf::Vector2f(0, 0);
    _acceleration = sf::Vector2f(0, 0);
}

void Entity::init(const std::string &filename)
{
    _filename = filename;
    _texture.loadFromFile(filename);
    if (!_texture.loadFromFile(filename))
        throw std::runtime_error("Error: could not load texture");
    _sprite.setTexture(_texture);
    _sprite.setPosition(_position);
}

void Entity::update(std::shared_ptr<sf::RenderWindow> window)
{

}

void Entity::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(_sprite);
}

Entity::~Entity()
{
}
