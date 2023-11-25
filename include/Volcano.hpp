/*
** EPITECH PROJECT, 2023
** Volcano
** File description:
** epitech > 42
*/

#pragma once
#include "cppIncludes.hpp"
#include "Maths/Rect.hpp"
#include "Maths/Vector2.hpp"
#include "Graphical/Window.hpp"
#include "GUI/GUIManager.hpp"

class Volcano {
    public:
        Volcano();
        void init(std::uint32_t width, std::uint32_t height, std::string title);
        void registerEvent();
        void registerGUI();
        void run();
        ~Volcano();
    private:
        std::shared_ptr<Window> _window;
        std::shared_ptr<GUIManager> _guiManager;
};
