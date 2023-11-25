/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Window
*/

#include "Graphical/Window.hpp"

Window::Window()
{
    this->_height = 0;
    this->_width = 0;
    this->_title = "";
}

Window::~Window()
{
}

void Window::init(std::uint32_t width, std::uint32_t height, std::string title)
{
    this->_width = width;
    this->_height = height;
    this->_title = title;
    this->_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);
}

void Window::stop()
{
    this->_window->close();
}

void Window::clear()
{
    this->_window->clear();
}

void Window::draw()
{
    this->_window->display();
}

void Window::pollEvent(sf::Event &event)
{
    while (this->_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            this->_window->close();
    }
}

bool Window::isOpen()
{
    return this->_window->isOpen();
}

std::uint32_t Window::getWidth() const
{
    return this->_width;
}

std::uint32_t Window::getHeight() const
{
    return this->_height;
}

std::string Window::getTitle() const
{
    return this->_title;
}