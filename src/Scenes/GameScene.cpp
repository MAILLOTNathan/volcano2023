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
    if (this->_playerVelocity.x != 0) {
        this->_sprite.setTexture(this->_texturePlayerMoving);
        if (this->_playerVelocity.x > 0 && this->_playerVelocity.y <= 0) {
            this->_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
        } else if (this->_playerVelocity.x < 0 && this->_playerVelocity.y <= 0) {
            this->_sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
        } else if (this->_playerVelocity.x > 0 && this->_playerVelocity.y >= 0) {
            this->_sprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
        } else if (this->_playerVelocity.x < 0 && this->_playerVelocity.y >= 0) {
            this->_sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
        }
    }
    else
        this->_sprite.setTexture(this->_texturePlayerStatic);
    this->_sprite.move(this->_playerVelocity);
}

void GameScene::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->_sprite);
}

GameScene::~GameScene()
{
}
