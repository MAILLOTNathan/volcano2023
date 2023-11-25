/*
** EPITECH PROJECT, 2023
** SceneManager
** File description:
** echo $?
*/

#include "Scene/SceneManager.hpp"

SceneManager::SceneManager()
{
    _currentScene = std::make_shared<Scene>();
}

void SceneManager::addScene(const std::string &name, std::shared_ptr<Scene> scene)
{
    if (_scenes.find(name) != _scenes.end())
        throw std::runtime_error("Scene already exists");
    scene->init();
    _scenes[name] = scene;
}

void SceneManager::removeScene(const std::string &name)
{
    if (_scenes.find(name) == _scenes.end())
        throw std::runtime_error("Scene doesn't exists");
    _scenes.erase(name);
}

void SceneManager::loadScene(const std::string &name)
{
    if (_scenes.find(name) == _scenes.end())
        throw std::runtime_error("Scene doesn't exists");
    _currentScene = _scenes[name];
}

void SceneManager::unloadScene(const std::string &name)
{
    if (_scenes.find(name) == _scenes.end())
        throw std::runtime_error("Scene doesn't exists");
    _currentScene = nullptr;
}

void SceneManager::update(std::shared_ptr<sf::RenderWindow> window, sf::Event event)
{
    if (_currentScene)
        _currentScene->update(window, event);
}

void SceneManager::draw(std::shared_ptr<sf::RenderWindow> window)
{
    if (_currentScene)
        _currentScene->draw(window);
}

void SceneManager::unloadAllScenes()
{
    _currentScene = nullptr;
   _scenes.clear();
}

SceneManager::~SceneManager()
{
}
