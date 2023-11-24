/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Graphical
*/

#include "../include/SFMLGraphical.hpp"

void SFMLGraphical::createWindow(std::uint32_t width, std::uint32_t height, std::string title)
{
    _window = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

void SFMLGraphical::destroyWindow()
{
    _window->close();
}

void SFMLGraphical::clear()
{
    _window->clear();
}

void SFMLGraphical::draw()
{
    _window->display();
}

