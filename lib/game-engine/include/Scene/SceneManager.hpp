/*
** EPITECH PROJECT, 2023
** SceneManager
** File description:
** don't forget to free at the end
*/

#pragma once
#include "cppIncludes.hpp"
#include "Scene.hpp"

class SceneManager {
    public:
        SceneManager();
        ~SceneManager();

        void addScene(const std::string &name, std::shared_ptr<Scene> scene);
        void removeScene(const std::string &name);
        void loadScene(const std::string &name);
        void unloadScene(const std::string &name);
        std::string update(std::shared_ptr<sf::RenderWindow> window, sf::Event event);
        void draw(std::shared_ptr<sf::RenderWindow> window);
        void unloadAllScenes();
        std::string getCurrentSceneName();

    private:
        std::map<std::string, std::shared_ptr<Scene>> _scenes;
        std::shared_ptr<Scene> _currentScene;
};
