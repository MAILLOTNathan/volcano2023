/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** GUIButton
*/

#include "GUI/GUIButton.hpp"

GUIButton::GUIButton()
{
}

GUIButton::~GUIButton()
{
}

void GUIButton::init(std::string path_normal, std::string path_hover)
{
    _textures[0].loadFromFile(path_normal);
    _textures[1].loadFromFile(path_hover);
    _sprite.setTexture(_textures[0]);
}

void GUIButton::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(_sprite);
}

void GUIButton::setPosition(sf::Vector2f pos)
{
    _sprite.setPosition(pos);
}

void GUIButton::setScale(sf::Vector2f scale)
{
    _sprite.setScale(scale);
}

void GUIButton::setRect(sf::IntRect rect)
{
    _rect = rect;
    // _sprite.setTextureRect(_rect);
}

void GUIButton::changeState(bool hover)
{
    if (hover)
        _sprite.setTexture(_textures[1]);
    else
        _sprite.setTexture(_textures[0]);
}

void GUIButton::setCallback(std::function<void()> callback)
{
    _callback = callback;
}

bool GUIButton::isHover(sf::Vector2i mousePos)
{
    if (mousePos.x >= _sprite.getPosition().x && mousePos.x <= _sprite.getPosition().x + _rect.width
    && mousePos.y >= _sprite.getPosition().y && mousePos.y <= _sprite.getPosition().y + _rect.height)
        return true;
    return false;
}

sf::Vector2f GUIButton::getPosition()
{
    return _sprite.getPosition();
}

sf::Vector2f GUIButton::getScale()
{
    return _sprite.getScale();
}

sf::IntRect GUIButton::getRect()
{
    return _rect;
}

sf::Sprite GUIButton::getSprite()
{
    return _sprite;
}

std::function<void()> GUIButton::getCallback()
{
    return _callback;
}