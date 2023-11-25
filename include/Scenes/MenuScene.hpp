/*
** EPITECH PROJECT, 2023
** MenuScene
** File description:
** check your malloc!
*/

#pragma once
#include "cppIncludes.hpp"
#include "Scene/Scene.hpp"

class MenuScene : public Scene {
    public:
        MenuScene();
        ~MenuScene();
        void init() override;
        void update() override;
        void draw(std::shared_ptr<sf::RenderWindow> window) override;
    private:
};
