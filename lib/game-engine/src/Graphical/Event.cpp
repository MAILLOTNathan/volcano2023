/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Event
*/

#include "Graphical/Event.hpp"
#include "Graphical/Window.hpp"

Event::Event()
{
}

Event::~Event()
{
}

void Event::bindKey(std::shared_ptr<Button<etibEvent::Keyboard>> button, std::function<void(void)> func)
{
    this->_keyMap[button] = func;
}

void Event::bindMouse(std::shared_ptr<Button<etibEvent::Mouse>> button, std::function<void(void)> func)
{
    this->_mouseMap[button] = func;
}

void Event::unbindKey(std::shared_ptr<Button<etibEvent::Keyboard>> button)
{
    this->_keyMap.erase(button);
}

void Event::unbindMouse(std::shared_ptr<Button<etibEvent::Mouse>> button)
{
    this->_mouseMap.erase(button);
}

void Event::manageEvent(sf::Event &event)
{
    this->manageKeyboardEvent(event);
    this->manageMouseEvent(event);
}

void Event::manageKeyboardEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) {
        for (auto it = this->_keyMap.begin(); it != this->_keyMap.end(); it++) {
            if ((int)it->first->getButton() == (int)event.key.code && (!it->first->isPressed() || it->first->getType() == etibEvent::PRESSED)) {
                it->first->setPressed(true);
                if (it->first->getType() <= etibEvent::JUST_PRESSED)
                    it->second();
                break;
            }
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        for (auto it = this->_keyMap.begin(); it != this->_keyMap.end(); it++) {
            if ((int)it->first->getButton() == (int)event.key.code && (it->first->isPressed() || it->first->getType() == etibEvent::RELEASED)) {
                it->first->setPressed(false);
                if (it->first->getType() >= etibEvent::RELEASED)
                    it->second();
                break;
            }
        }
    }
}

void Event::manageMouseEvent(sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonReleased) {
        for (auto it = this->_mouseMap.begin(); it != this->_mouseMap.end(); it++) {
            if ((int)it->first->getButton() == (int)event.mouseButton.button && (it->first->isPressed() || it->first->getType() == etibEvent::RELEASED)) {
                it->first->setPressed(false);
                if (it->first->getType() >= etibEvent::RELEASED)
                    it->second();
                break;
            }
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        for (auto& it: this->_mouseMap) {
            if (sf::Mouse::isButtonPressed((sf::Mouse::Button)it.first->getButton()) && (!it.first->isPressed() || it.first->getType() == etibEvent::PRESSED)) {
                it.first->setPressed(true);
                if (it.first->getType() <= etibEvent::JUST_PRESSED)
                    it.second();
                    break;
            }
        }
    }
}