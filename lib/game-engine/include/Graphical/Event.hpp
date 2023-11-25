/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "cppIncludes.hpp"
#include "Graphical/Button.hpp"

class Event {
    public:
        Event();
        ~Event();

        void bindKey(std::shared_ptr<Button<etibEvent::Keyboard>> button, std::function<void(void)> func);
        void bindMouse(std::shared_ptr<Button<etibEvent::Mouse>> button, std::function<void(void)> func);

        void unbindKey(std::shared_ptr<Button<etibEvent::Keyboard>> button);
        void unbindMouse(std::shared_ptr<Button<etibEvent::Mouse>> button);

        void manageEvent(sf::Event &event);
        void manageKeyboardEvent(sf::Event &event);
        void manageMouseEvent(sf::Event &event);

    // private:
        std::map<std::shared_ptr<Button<etibEvent::Keyboard>>, std::function<void(void)>> _keyMap;
        std::map<std::shared_ptr<Button<etibEvent::Mouse>>, std::function<void(void)>> _mouseMap;
};

#endif /* !EVENT_HPP_ */
