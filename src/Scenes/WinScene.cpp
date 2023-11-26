/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** WinScene
*/

#include "Scenes/WinScene.hpp"

WinScene::WinScene()
{
}

void WinScene::init()
{
    this->_textureWin.loadFromFile("assets/win.png");
    this->_spriteWin.setTexture(this->_textureWin);
    this->_spriteWin.setScale(5, 5);
}

std::string WinScene::update(std::shared_ptr<sf::RenderWindow> window, sf::Event event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return "menu";
    return "";
}

void WinScene::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->clear(sf::Color::White);
    window->draw(this->_spriteWin);
}

WinScene::~WinScene()
{
}
