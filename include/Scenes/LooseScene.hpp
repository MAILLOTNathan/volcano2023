/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** LooseScene
*/

#ifndef LOOSESCENE_HPP_
#define LOOSESCENE_HPP_

#include "cppIncludes.hpp"
#include "Scene/SceneManager.hpp"

class LooseScene : public Scene{
    public:
        LooseScene();
        ~LooseScene();
        void init() override;
        std::string update(std::shared_ptr<sf::RenderWindow> window, sf::Event event) override;
        void draw(std::shared_ptr<sf::RenderWindow> window) override;
    private:
        sf::Sprite _spriteLoose;
        sf::Texture _textureLoose;
};

#endif /* !LOOSESCENE_HPP_ */
