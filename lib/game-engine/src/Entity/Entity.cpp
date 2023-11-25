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

void Entity::setTextureRect(const sf::IntRect &rect)
{
    _sprite.setTextureRect(rect);
}

void Entity::setPosition(const sf::Vector2f &position)
{
    _position = position;
}

void Entity::setScale(const sf::Vector2f &scale)
{
    _scale = scale;
}

void Entity::setOrigin(const sf::Vector2f &origin)
{
    _origin = origin;
}

void Entity::setVelocity(const sf::Vector2f &velocity)
{
    _velocity = velocity;
}

void Entity::setAcceleration(const sf::Vector2f &acceleration)
{
    _acceleration = acceleration;
}

sf::Vector2f Entity::getPosition() const
{
    return _position;
}

sf::Vector2f Entity::getScale() const
{
    return _scale;
}

sf::Vector2f Entity::getOrigin() const
{
    return _origin;
}

sf::Vector2f Entity::getVelocity() const
{
    return _velocity;
}

sf::Vector2f Entity::getAcceleration() const
{
    return _acceleration;
}

sf::IntRect Entity::getTextureRect() const
{
    return _sprite.getTextureRect();
}

Entity::~Entity()
{
}
