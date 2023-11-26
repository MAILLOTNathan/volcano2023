/*
** EPITECH PROJECT, 2023
** MenuScene
** File description:
** check your malloc!
*/

#pragma once
#include "cppIncludes.hpp"
#include "Scene/Scene.hpp"
#include "GUI/GUIManager.hpp"
class MenuScene : public Scene {
    public:
        MenuScene();
        ~MenuScene();
        void init();
        std::string update(std::shared_ptr<sf::RenderWindow> window, sf::Event event);
        void draw(std::shared_ptr<sf::RenderWindow> window);
    private:
        sf::Sprite _background;
        sf::Texture _backgroundTexture;
        GUIManager _guiManager;
        std::shared_ptr<sf::RenderWindow> _window;
};
