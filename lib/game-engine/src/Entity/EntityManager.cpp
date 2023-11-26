/*
** EPITECH PROJECT, 2023
** EntityManager
** File description:
** you're a bad developer
*/

#include "Entity/EntityManager.hpp"

EntityManager::EntityManager()
{
}

void EntityManager::registerEntity(const std::string &name, const std::string &filename)
{
    if (_entities.find(name) != _entities.end())
        return;
    _entities[name] = std::make_shared<Entity>();
    _entities[name]->init(filename);
}

void EntityManager::updateEntities(std::shared_ptr<sf::RenderWindow> window)
{
    for (auto &entity : _entities) {
        entity.second->update(window);
    }
}

void EntityManager::drawEntity(const std::string &name, std::shared_ptr<sf::RenderWindow> window)
{
    if (_entities.find(name) == _entities.end())
        return;
    _entities[name]->draw(window);
}

std::shared_ptr<Entity> EntityManager::getEntity(const std::string &name)
{
    if (_entities.find(name) == _entities.end())
        return nullptr;
    return _entities[name];
}

EntityManager::~EntityManager()
{
}
