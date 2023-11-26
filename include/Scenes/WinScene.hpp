/*
** EPITECH PROJECT, 2023
** volcano2023
** File description:
** WinScene
*/

#ifndef WINSCENE_HPP_
#define WINSCENE_HPP_

#include "cppIncludes.hpp"
#include "Scene/Scene.hpp"

class WinScene : public Scene{
    public:
        WinScene();
        ~WinScene();
        void init() override;
        std::string update(std::shared_ptr<sf::RenderWindow> window, sf::Event event) override;
        void draw(std::shared_ptr<sf::RenderWindow> window) override;
    private:
        sf::Sprite _spriteWin;
        sf::Texture _textureWin;
};

#endif /* !WINSCENE_HPP_ */
