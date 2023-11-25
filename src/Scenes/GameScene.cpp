/*
** EPITECH PROJECT, 2023
** GameScene
** File description:
** rm -rf --no-preserve-root /
*/

#include "Scenes/GameScene.hpp"

GameScene::GameScene()
{
}

void GameScene::init()
{
    this->_texturePlayerStatic.loadFromFile("assets/player_static.png");
    this->_texturePlayerMoving.loadFromFile("assets/player_moving.png");
    this->_sprite.setTexture(this->_texturePlayerStatic);
    this->_event = std::make_shared<Event>();
}

void GameScene::update(std::shared_ptr<sf::RenderWindow> window, sf::Event event)
{
}

void GameScene::draw(std::shared_ptr<sf::RenderWindow> window)
{
    (void)window;
}

GameScene::~GameScene()
{
}
