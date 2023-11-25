/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Graphical
*/

#include "../include/SFMLGraphical.hpp"

void SFMLGraphical::createWindow(std::uint32_t width, std::uint32_t height, std::string title)
{
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);
}

void SFMLGraphical::init()
{
}

void SFMLGraphical::stop()
{
}

void SFMLGraphical::createSprite()
{
}

void SFMLGraphical::destroySprite()
{
}

void SFMLGraphical::setSpriteTexture()
{
}

void SFMLGraphical::setSpritePosition()
{
}

void SFMLGraphical::setSpriteRotation()
{
}

void SFMLGraphical::setSpriteScale()
{
}

void SFMLGraphical::drawSprite()
{
}

void SFMLGraphical::createText()
{
}

void SFMLGraphical::destroyText()
{
}

void SFMLGraphical::setTextString()
{
}

void SFMLGraphical::setTextFont()
{
}

void SFMLGraphical::setTextPosition()
{
}

void SFMLGraphical::setTextRotation()
{
}

void SFMLGraphical::setTextScale()
{
}

void SFMLGraphical::drawText()
{

}

void SFMLGraphical::destroyWindow()
{
    _window->close();
}

void SFMLGraphical::clear()
{
    _window->clear();
}

bool SFMLGraphical::isOpen()
{
    return _window->isOpen();
}

void SFMLGraphical::draw()
{
    _window->display();
}

