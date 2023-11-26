/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** LooseScene
*/

#include "Scenes/LooseScene.hpp"

LooseScene::LooseScene()
{
}

void LooseScene::init()
{
    this->_textureLoose.loadFromFile("assets/loose.png");
    this->_spriteLoose.setTexture(this->_textureLoose);
    this->_spriteLoose.setScale(5, 5);
}

std::string LooseScene::update(std::shared_ptr<sf::RenderWindow> window, sf::Event event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return "menu";
    return "";
}

void LooseScene::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->clear(sf::Color::White);
    window->draw(this->_spriteLoose);
}

LooseScene::~LooseScene()
{
}
