/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** GUIManager
*/

#ifndef GUIMANAGER_HPP_
#define GUIMANAGER_HPP_

#include "cppIncludes.hpp"
#include "GUI/GUIButton.hpp"

class GUIManager {
    public:
        GUIManager();
        ~GUIManager();

        void init();
        void draw(std::shared_ptr<sf::RenderWindow> window);
        int handleEvent(std::shared_ptr<sf::RenderWindow>, sf::Event event);
        void addButton(std::string name, std::string path_normal, std::string path_hover, sf::Vector2f pos, sf::Vector2f scale, std::function<void()> callback);
        void removeButton(std::string name);
        void removeAllButtons();

    private:
        std::map<std::string, std::shared_ptr<GUIButton>> _buttons;
};

#endif /* !GUIMANAGER_HPP_ */
