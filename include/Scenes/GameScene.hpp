/*
** EPITECH PROJECT, 2023
** GameScene
** File description:
** check your malloc!
*/

#pragma once
#include "cppIncludes.hpp"
#include "Scene/Scene.hpp"

class GameScene : public Scene {
    public:
        GameScene();
        ~GameScene();
        void init() override;
        void update() override;
        void draw(std::shared_ptr<sf::RenderWindow> window) override;
    private:
};
