/*
** EPITECH PROJECT, 2023
** Volcano
** File description:
** epitech > 42
*/

#pragma once
#include "Graphical/AGraphical.hpp"
#include "SFMLGraphical.hpp"
#include "Graphical/ASprite.hpp"
#include "Maths/Rect.hpp"
#include "Maths/Vector2.hpp"

class Volcano {
    public:
        Volcano();
        void init();
        void run();
        ~Volcano();
    private:
        std::shared_ptr<etib::IGraphical> _graphical;
};
