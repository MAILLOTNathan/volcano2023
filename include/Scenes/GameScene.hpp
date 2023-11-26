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

#define PLAYER_SPEED 10

class GameScene : public Scene {
    public:
        GameScene();
        ~GameScene();
        void init() override;
        std::string update(std::shared_ptr<sf::RenderWindow> window, sf::Event event) override;
        void draw(std::shared_ptr<sf::RenderWindow> window) override;
    private:
        sf::Sprite _spritePlayer;
        sf::Texture _texturePlayerStatic;
        sf::Texture _texturePlayerMoving;
        sf::Vector2f _playerVelocity;
        sf::Clock _clock;
        sf::Sprite _spriteBgScene;
        sf::Texture _textureBgScene;
        sf::Sprite _spriteQuestion;
        sf::Texture _textureQuestion;

        int _cmptQuestion;
        std::vector<std::string> _questions;
        std::vector<std::array<std::string, 4>> _answers;
        std::array<int, 5> _correctAnswers;
        int score;
        sf::Font _font;
        std::array<sf::Text, 5> _textQuestions;
        sf::Text _textScore;
        int life;
        sf::Sprite _spriteLife;
        sf::Texture _textureLife;
};
