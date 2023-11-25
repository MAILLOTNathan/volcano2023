/*
** EPITECH PROJECT, 2023
** Volcano
** File description:
** programmers start to count from 0
*/

#include "Graphical/Window.hpp"
#include "Volcano.hpp"

Volcano::Volcano()
{
}

void Volcano::init(std::uint32_t width, std::uint32_t height, std::string title)
{
    _window = std::make_shared<Window>();
    this->_window->init(width, height, title);
}

void Volcano::registerEvent()
{
    this->_window->getEventManager().bindKey(std::make_shared<Button<etibEvent::Keyboard>>(etibEvent::Keyboard::Escape, etibEvent::JUST_PRESSED), [&]() {
        this->_window->stop();
    });

    this->_window->getEventManager().bindKey(std::make_shared<Button<etibEvent::Keyboard>>(etibEvent::Keyboard::A, etibEvent::JUST_PRESSED), [&]() {
        std::cout << "A pressed" << std::endl;
    });
}

void Volcano::run()
{
    while (_window->isOpen()) {
        _window->pollEvent();
        _window->clear();
        _window->draw();
    }
}

Volcano::~Volcano()
{
}
