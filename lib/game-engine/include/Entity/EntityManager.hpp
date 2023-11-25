/*
** EPITECH PROJECT, 2023
** EntityManager
** File description:
** r/ProgrammerHumor
*/

#pragma once
#include "../cppIncludes.hpp"
#include "./Entity.hpp"

class EntityManager {
    public:
        EntityManager();
        ~EntityManager();

        void registerEntity(const std::string &name, const std::string &filename);
        void updateEntities(std::shared_ptr<sf::RenderWindow> window);
        void drawEntity(const std::string &name, std::shared_ptr<sf::RenderWindow> window);

    private:
        std::map<std::string, std::shared_ptr<Entity>> _entities;
};
