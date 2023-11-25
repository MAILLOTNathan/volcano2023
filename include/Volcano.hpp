/*
** EPITECH PROJECT, 2023
** Volcano
** File description:
** epitech > 42
*/

#pragma once
#include "Maths/Rect.hpp"
#include "Maths/Vector2.hpp"
#include "Graphical/Window.hpp"

class Volcano {
    public:
        Volcano();
        void init(std::uint32_t width, std::uint32_t height, std::string title);
        void registerEvent();
        void run();
        ~Volcano();
    private:
        std::shared_ptr<Window> _window;
};
