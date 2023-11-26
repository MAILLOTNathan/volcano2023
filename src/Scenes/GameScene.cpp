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
    this->_playerVelocity = {0, 0};

    this->_event->bindKey(std::make_shared<Button<etibEvent::Keyboard>>(etibEvent::Keyboard::A, etibEvent::PRESSED), [&] {
        this->_playerVelocity.x -= PLAYER_SPEED;
    });

    this->_event->bindKey(std::make_shared<Button<etibEvent::Keyboard>>(etibEvent::Keyboard::D, etibEvent::PRESSED), [&] {
        this->_playerVelocity.x += PLAYER_SPEED;
    });
}

std::string GameScene::update(std::shared_ptr<sf::RenderWindow> window, sf::Event event)
{
    return "";
}

void GameScene::draw(std::shared_ptr<sf::RenderWindow> window)
{
    (void)window;
}

GameScene::~GameScene()
{
}
