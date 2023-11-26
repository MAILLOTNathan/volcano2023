/*
** EPITECH PROJECT, 2023
** GameScene
** File description:
** check your malloc!
*/

#pragma once
#include "cppIncludes.hpp"
#include "Scene/Scene.hpp"
#include "Graphical/Event.hpp"

#define PLAYER_SPEED 5

class GameScene : public Scene {
    public:
        GameScene();
        ~GameScene();
        void init() override;
        std::string update(std::shared_ptr<sf::RenderWindow> window, sf::Event event) override;
        void draw(std::shared_ptr<sf::RenderWindow> window) override;
    private:
        sf::Sprite _sprite;
        sf::Texture _texturePlayerStatic;
        sf::Texture _texturePlayerMoving;
        std::shared_ptr<Event> _event;
        sf::Vector2f _playerVelocity;
};
