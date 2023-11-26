/*
** EPITECH PROJECT, 2023
** Scene
** File description:
** C-x C-c
*/

#include "Scene/Scene.hpp"
#include "Graphical/Event.hpp"

Scene::Scene()
{
}

void Scene::init()
{
}

void Scene::setEvent(Event event)
{
    _event = event;
}

std::string Scene::update(std::shared_ptr<sf::RenderWindow> window, sf::Event event)
{
    return "";
}

void Scene::setSceneName(const std::string &name)
{
    _name = name;
}

std::string Scene::getSceneName() const
{
    return _name;
}

void Scene::draw(std::shared_ptr<sf::RenderWindow> window)
{
    (void)window;
}
