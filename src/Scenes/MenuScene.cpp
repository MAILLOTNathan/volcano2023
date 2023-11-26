/*
** EPITECH PROJECT, 2023
** MenuScene
** File description:
** rm -rf --no-preserve-root /
*/

#include "Scenes/MenuScene.hpp"

MenuScene::MenuScene()
{
}

void MenuScene::init()
{
    this->_backgroundTexture.loadFromFile("assets/menu_bg.png");
    this->_background.setTexture(this->_backgroundTexture);
    this->_background.setScale(sf::Vector2f(2.0f, 2.0f));

    this->_guiManager.init();
    this->_guiManager.addButton("play", "assets/play_normal.png", "assets/play_hover.png", sf::Vector2f(100, 100), sf::Vector2f(2.0f, 2.0f), []() {
        std::cout << "Button play clicked" << std::endl;
    });
    this->_guiManager.addButton("quit", "assets/quit_normal.png", "assets/quit_hover.png", sf::Vector2f(100, 200), sf::Vector2f(2.0f, 2.0f), [&]() {
        exit(0);
    });
}

void MenuScene::update(std::shared_ptr<sf::RenderWindow> window, sf::Event event)
{
    this->_guiManager.handleEvent(_window, event);
}

void MenuScene::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->_background);
    this->_guiManager.draw(window);
}

MenuScene::~MenuScene()
{
}
