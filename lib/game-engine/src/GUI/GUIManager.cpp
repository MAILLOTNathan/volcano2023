/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** GUIManager
*/

#include "GUI/GUIManager.hpp"

GUIManager::GUIManager()
{
}

GUIManager::~GUIManager()
{
}


void GUIManager::init()
{
}

void GUIManager::draw(std::shared_ptr<sf::RenderWindow> window)
{
    for (auto &button : _buttons)
        button.second->draw(window);
}

void GUIManager::handleEvent(std::shared_ptr<sf::RenderWindow> window, sf::Event event)
{
    for (auto &button : _buttons) {
        if (button.second->isHover(sf::Mouse::getPosition())) {
            button.second->changeState(true);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                button.second->getCallback()();
        } else
            button.second->changeState(false);
    }
}

void GUIManager::addButton(std::string name, std::string path_normal, std::string path_hover, sf::Vector2f pos, sf::Vector2f scale, std::function<void()> callback)
{
    _buttons[name] = std::make_shared<GUIButton>();
    _buttons[name]->init(path_normal, path_hover);
    _buttons[name]->setPosition(pos);
    _buttons[name]->setScale(scale);
    _buttons[name]->setRect(sf::IntRect(_buttons[name]->getSprite().getGlobalBounds()));
    // show the rect
    std::cout << "top: " << _buttons[name]->getRect().top << std::endl;
    std::cout << "left: " << _buttons[name]->getRect().left << std::endl;
    std::cout << "width: " << _buttons[name]->getRect().width << std::endl;
    std::cout << "height: " << _buttons[name]->getRect().height << std::endl;
    _buttons[name]->setCallback(callback);
}

void GUIManager::removeButton(std::string name)
{
    _buttons.erase(name);
}

void GUIManager::removeAllButtons()
{
    _buttons.clear();
}