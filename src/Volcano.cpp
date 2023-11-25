/*
** EPITECH PROJECT, 2023
** Volcano
** File description:
** programmers start to count from 0
*/

#include "Graphical/Window.hpp"
#include "Entity/EntityManager.hpp"
#include "Volcano.hpp"

Volcano::Volcano()
{
}

void Volcano::init(std::uint32_t width, std::uint32_t height, std::string title)
{
    _window = std::make_shared<Window>();
    this->_window->init(width, height, title);
}

void Volcano::run()
{
    EntityManager e_manager;
    e_manager.registerEntity("player", "assets/theboat.png");
    sf::Event event;
    while (_window->isOpen()) {
        _window->pollEvent(event);
        e_manager.updateEntities(_window->getWindow());
        _window->clear();
        e_manager.drawEntity("player", _window->getWindow());
        _window->draw();
    }
}

Volcano::~Volcano()
{
}
