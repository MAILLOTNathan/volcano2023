/*
** EPITECH PROJECT, 2023
** Scene
** File description:
** if you code on paper, you're not a real programmer
*/

#pragma once
#include "cppIncludes.hpp"
#include "Entity/EntityManager.hpp"


class Scene {
    public:
        Scene();
        virtual ~Scene() = default;
        virtual void init();
        virtual void update();
        virtual void draw(std::shared_ptr<sf::RenderWindow> window);
    private:
};
