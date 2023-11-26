/*
** EPITECH PROJECT, 2023
** Volcano
** File description:
** programmers start to count from 0
*/

#include "Graphical/Window.hpp"
#include "Entity/EntityManager.hpp"
#include "Volcano.hpp"
#include "Scenes/MenuScene.hpp"
#include "Scenes/WinScene.hpp"
#include "Scenes/LooseScene.hpp"

sf::Color color = sf::Color::Black;

Volcano::Volcano()
{
}

void Volcano::init(std::uint32_t width, std::uint32_t height, std::string title)
{
    _window = std::make_shared<Window>();
    this->_window->init(width, height, title);

    _guiManager = std::make_shared<GUIManager>();
    _guiManager->init();

    _sceneManager = std::make_shared<SceneManager>();
}

void Volcano::registerEvent()
{
    this->_window->getEventManager().bindKey(std::make_shared<Button<etibEvent::Keyboard>>(etibEvent::Keyboard::Escape, etibEvent::JUST_PRESSED), [&]() {
        this->_window->stop();
    });
}

void Volcano::registerGUI()
{
    this->_guiManager->addButton("play", "assets/play_normal.png", "assets/play_hover.png", sf::Vector2f(100, 100), sf::Vector2f(1, 1), [&]() {
        color = sf::Color::Red;
        std::cout << "Hello toi" << std::endl;

    });

    this->_guiManager->addButton("quit", "assets/quit_normal.png", "assets/quit_hover.png", sf::Vector2f(200, 100), sf::Vector2f(1, 1), [&]() {
        this->_window->stop();
    });
}

void Volcano::run()
{
    std::string new_scene;
    _sceneManager->addScene("menu", std::make_shared<MenuScene>(), _window->getEventManager());
    _sceneManager->addScene("game", std::make_shared<GameScene>(), _window->getEventManager());
    _sceneManager->addScene("win", std::make_shared<WinScene>(), _window->getEventManager());
    _sceneManager->addScene("loose", std::make_shared<LooseScene>(), _window->getEventManager());
    _sceneManager->loadScene("menu");
    // e_manager.registerEntity("player", "assets/theboat.png");
    while (_window->isOpen()) {
        _window->pollEvent();
        _window->clear(color);
        new_scene = _sceneManager->update(_window->getWindow(), _window->getEvent());
        if (new_scene != "")
            _sceneManager->loadScene(new_scene);
        new_scene = "";
        _sceneManager->draw(_window->getWindow());
        _window->draw();
    }
}

Volcano::~Volcano()
{
}
