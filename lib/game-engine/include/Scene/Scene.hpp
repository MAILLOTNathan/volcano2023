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
        virtual std::string update(std::shared_ptr<sf::RenderWindow> window, sf::Event event);
        virtual void draw(std::shared_ptr<sf::RenderWindow> window);
        virtual std::string getSceneName() const;
        virtual void setSceneName(const std::string &name);
    private:
        std::string _name;
};
